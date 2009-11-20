using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Schema;
using System.Collections;
using System.IO;
using System.Text.RegularExpressions;

namespace CaDeclDoxyFilter
{
    class Program
    {
        static void Usage()
        {
            Console.WriteLine("usage: CaDeclDoxyFilter [filename]");
        }

        static int Main(string[] args)
        {
            try
            {
                if (args.Length != 1)
                {
                    Usage();
                    throw new ArgumentException("filename");
                }

                Process(args[0]);

                return 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return -1;
            }
        }

        static void Process(string filename)
        {
            List<string> customactions = new List<string>();

            string contents = File.ReadAllText(filename, Encoding.ASCII);
            Console.WriteLine(contents);

            Regex m_function = new Regex(@"CA_API UINT __stdcall (?<name>\w*)");
            Match m = m_function.Match(contents);
            while (m.Success)
            {
                customactions.Add(m.Groups["name"].Value);
                m = m.NextMatch();
            }

            if (customactions.Count > 0)
            {
                Console.WriteLine(@"/*! \page customactions All Custom Actions");
                foreach (string ca in customactions)
                {
                    Console.WriteLine(@"\li \ref {0}", ca);
                }
                Console.WriteLine("*/");
            }
        }
    }
}
