using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Text.RegularExpressions;
using System.IO;

namespace WixDoxyFilter
{
    public class WixPreprocessor
    {
        private string _filename;
        private string _root;
        private Dictionary<string, string> _defines = new Dictionary<string, string>();
        private string _result;

        public WixPreprocessor(string filename)
        {
            _filename = filename;
            _root = Path.GetDirectoryName(_filename);
        }

        public string Result
        {
            get
            {
                return _result;
            }
        }

        public Dictionary<string, string> Defines
        {
            get
            {
                return _defines;
            }
            set
            {
                _defines = value;
            }
        }

        public WixPreprocessor(string filename, string root)
        {
            _filename = filename;
            _root = root;
        }

        private string GetSysVariable(string name)
        {
            switch (name)
            {
                case "SOURCEFILEDIR":
                    return _root;
            }
            return string.Format("[sys: {0}]", name);
        }

        private string RewriteVariable(Match m)
        {
            string type = m.Groups["type"].Value;
            string variable = m.Groups["variable"].Value;
            string result = string.Format("[{0}: {1}]", type, variable);
            switch (type)
            {
                case "var":
                    string value;
                    if (_defines.TryGetValue(variable, out value))
                        result = _defines[variable];
                    break;
                case "sys":
                    result = GetSysVariable(variable);
                    break;
            }
            // Console.WriteLine("Resolving {0}.{1} => {2}", type, variable, result);
            return result;
        }

        public string Expand(string value)
        {
            MatchEvaluator m = new MatchEvaluator(RewriteVariable);
            return Regex.Replace(value, @"[\$\!]+\((?<type>[\w]*)\.(?<variable>[\w]*)\)", m); 
        }

        public void Preprocess()
        {
            StringBuilder sb = new StringBuilder();
            StreamReader r = new StreamReader(_filename);
            while (!r.EndOfStream)
            {
                string line = r.ReadLine();

                // <?define ?>
                Match m_define = Regex.Match(line, @"\<\?define\s(?<name>.*)=(?<value>.*)\?\>");
                if (m_define.Success)
                {
                    // Console.WriteLine("{0}: {1} - {2}", line, m_define.Success, m_define.Length);
                    string value = m_define.Groups["value"].Value;
                    value = value.Trim("\" '".ToCharArray());
                    value = Expand(value);
                    // Console.WriteLine("Value: {0}", value);
                    _defines[m_define.Groups["name"].Value] = value;
                }

                Match m_include = Regex.Match(line, @"\<\?include\s(?<filename>.*)\s\?\>");
                if (m_include.Success)
                {
                    string filename = m_include.Groups["filename"].Value;
                    filename = Path.Combine(_root, filename);
                    // preprocess internals
                    XmlDocument includexml = new XmlDocument();
                    // Console.WriteLine("Preprocessing {0}", filename);
                    WixPreprocessor innerpreprocessor = new WixPreprocessor(filename, _root);
                    innerpreprocessor._defines = _defines;
                    innerpreprocessor.Preprocess();
                    // Console.WriteLine("Done preprocessing {0}", filename);
                    //Console.WriteLine(innerpreprocessor.Result);
                    includexml.LoadXml(innerpreprocessor.Result);
                    line = includexml.DocumentElement.InnerXml;
                }

                sb.AppendLine(Expand(line));
            }

            _result = sb.ToString();
        }
    }
}
