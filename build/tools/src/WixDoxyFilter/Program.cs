using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Collections;
using System.IO;
using System.Text.RegularExpressions;

namespace WixDoxyFilter
{
    class Program
    {
        static void Usage()
        {
            Console.WriteLine("usage: WixDoxyFilter [filename]");
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

                WixPreprocessor preprocessor = new WixPreprocessor(args[0]);
                XmlDocument xml = new XmlDocument();
                preprocessor.Preprocess();

                //Console.WriteLine(preprocessor.Result);
                xml.LoadXml(preprocessor.Result);

                XmlNamespaceManager nsm = new XmlNamespaceManager(xml.NameTable);
                nsm.AddNamespace("wix", "http://schemas.microsoft.com/wix/2006/wi");

                TransformProducts(xml, nsm);
                TransformModules(xml, nsm);

                return 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return -1;
            }
        }

        static string ExpandVariable(string id)
        {
            // todo: expand variables
            return id;
        }

        static string ExpandId(string id)
        {
            if (id == "*") return Guid.NewGuid().ToString();
            return ExpandVariable(id);
        }

        static string MakeId(string id)
        {
            string result = "";
            for (int i = 0; i < id.Length; i++)
            {
                if (!Char.IsLetterOrDigit(id[i]))
                {
                    result += '_';
                }
                else
                {
                    result += id[i];
                }
            }

            return result.ToLower();
        }

        static void TransformPackages(XmlNode product, XmlNamespaceManager nsm)
        {
            XmlNodeList packages = product.SelectNodes("//wix:Package", nsm);
            foreach (XmlNode package in packages)
            {
                XmlAttribute description = package.Attributes["Description"];
                if (description != null) Console.WriteLine("{0}", description.Value);
            }
        }

        static string GetProductId(XmlNode product)
        {
            XmlAttribute name = product.Attributes["Name"];
            string s_name = name != null ? name.Value : "Unknown";
            return MakeId(s_name);            
        }

        static void TransformComponents(XmlNode product, string product_id, XmlNamespaceManager nsm)
        {
            string components_id = string.Format("{0}_components", product_id);
            Console.WriteLine(@"\section {0} Components", components_id);
            XmlNodeList components = product.SelectNodes("//wix:Component", nsm);
            foreach (XmlNode component in components)
            {
                // Get installation directory information                
                String installationPath = GetDirectoryPath(component, nsm);

                XmlAttribute id = component.Attributes["Id"];
                XmlAttribute guid = component.Attributes["Guid"];
                string s_id = ExpandId(id != null ? id.Value : Guid.NewGuid().ToString());
                string s_guid = guid != null ? guid.Value : string.Empty;
                string component_id = string.Format("{0}_{1}", components_id, MakeId(s_id));
                Console.WriteLine(@"\subsection {0} {1}", component_id, s_id);
                
                TransformComment(component);
                
                Console.WriteLine();
                Console.WriteLine(@"\li Component guid: {0}", s_guid);
                Console.WriteLine(@"\li Installation Path: " + installationPath.ToString());

                TransformComponentChildren(installationPath, component, nsm);
            }
        }

        static void TransformMerges(XmlNode product, string product_id, XmlNamespaceManager nsm)
        {
            string merges_id = string.Format("{0}_merges", product_id);
            Console.WriteLine(@"\section {0} Merge Modules", merges_id);
            XmlNodeList merges = product.SelectNodes("//wix:Merge", nsm);
            foreach (XmlNode merge in merges)
            {
                XmlAttribute id = merge.Attributes["Id"];
                XmlAttribute sourcefile = merge.Attributes["SourceFile"];
                string s_id = ExpandId(id != null ? id.Value : Guid.NewGuid().ToString());
                string s_sourcefile = sourcefile != null ? Path.GetFullPath(sourcefile.Value) : string.Empty;
                string merge_id = string.Format("{0}_{1}", merges_id, MakeId(s_id));
                Console.WriteLine(@"\subsection {0} {1}", merge_id, s_id);
                TransformComment(merge);
                Console.WriteLine();
                Console.WriteLine("Source: {0}", s_sourcefile.Replace(@"\", @"\\"));
                
                // Adding a reference to the merge module documentation
                // Check how a doxygen page name is generated for a merge module in TransformModules function
                string ref_id = (id != null) ? id.Value : "Unknown";
                string module_ref_id = string.Format("{0}_wxs", MakeId(ref_id));
                Console.WriteLine(@"<br><b>{0} documentation:</b> \ref {1}", id.Value, module_ref_id);
                Console.WriteLine();
            }
        }

        static void TransformComponentChildren(string installationPath, XmlNode node, XmlNamespaceManager nsm)
        {
            if (node.HasChildNodes)
            {
                StringBuilder registry_s = new StringBuilder();
                XmlNodeList children = node.ChildNodes;
                foreach (XmlNode childNode in children)
                {
                    if (childNode.Name == "Condition")
                    {
                        TransformComponentCondition(childNode, nsm);
                    }
                    else if (childNode.Name == "Environment")
                    {
                        TransformComponentEnvironment(childNode, nsm);
                    }
                    else if (childNode.Name == "File")
                    {
                        TransformComponentFile(installationPath, childNode, nsm);
                    }
                    else if (childNode.Name == "RegistryValue")
                    {
                        registry_s.AppendLine(TransformComponentRegistryValue(childNode, nsm));
                    }                    
                    else
                    {
                        TransformComponentChildren(installationPath, childNode, nsm);
                    }
                }

                if (registry_s.Length > 0)
                {
                    Console.WriteLine();
                    Console.WriteLine(@"\par Registry Settings");
                    Console.WriteLine();
                    Console.WriteLine("<table>{0}</table>", registry_s.ToString());
                }
            }
        }

        static String GetDirectoryPath(XmlNode componentNode, XmlNamespaceManager nsm)
        {
            XmlNode parent = componentNode.ParentNode;
            StringBuilder installationPath = new StringBuilder("");

            if (parent != null)
            {
                XmlAttribute id = parent.Attributes["Id"];
                string s_id = (id != null) ? id.Value : "";

                // If it is of type wix:Directory get the name or id.
                if (parent.Name == "Directory")
                {
                    installationPath.Insert(0, GetNodeDirectory(parent, nsm));
                    installationPath.Insert(0, GetDirectoryPath(parent, nsm));
                }
                // If the parent is of type wix:DirectoryRef find the wix:Directory node that the
                // DirectoryRef points to and then get the name or id.
                else if (parent.Name == "DirectoryRef")
                {
                    if (!String.IsNullOrEmpty(s_id))
                    {
                        XmlNode installdir = parent.SelectSingleNode(String.Format("//wix:Directory[@Id='{0}']", s_id), nsm);
                        if (installdir != null)
                        {
                            installationPath.Insert(0, GetNodeDirectory(installdir, nsm));
                            installationPath.Insert(0, GetDirectoryPath(installdir, nsm));
                        }
                    }
                }
            }

            return installationPath.ToString();
        }
       
        static String GetNodeDirectory(XmlNode node, XmlNamespaceManager nsm)
        {
            StringBuilder installationPath = new StringBuilder("");

            if (node.Name == "Directory")
            {
                XmlAttribute id = node.Attributes["Id"];
                XmlAttribute name = node.Attributes["Name"];

                string s_id = (id != null) ? id.Value : "";
                string s_name = (name != null) ? name.Value : "";

                switch (s_id)
                {
                    // Add other special folder name cases here...
                    case "ProgramFilesFolder":
                        string programfiles = "\\%ProgramFiles\\%";
                        installationPath.Insert(0, @"\\");
                        installationPath.Insert(0, programfiles);
                        break;

                    case "ProgramMenuFolder":
                        string programMenu = "[ProgramMenuFolder]";
                        installationPath.Insert(0, @"\\");
                        installationPath.Insert(0, programMenu);
                        break;

                    case "SystemFolder":
                        string systemFolder = "[SystemFolder]";
                        installationPath.Insert(0, @"\\");
                        installationPath.Insert(0, systemFolder);
                        break;

                    // MergeRedirectFolder - I cannot obtain the INSTALLDIR value
                    // as it is resolved during compilation of the Wxs file.
                    case "MergeRedirectFolder":
                        string installdir = "[INSTALLDIR]";
                        installationPath.Insert(0, @"\\");
                        installationPath.Insert(0, installdir);
                        break;

                    case "INSTALLDIR":
                        if ((!String.IsNullOrEmpty(s_name)) && (s_name != "."))
                        {
                            installationPath.Insert(0, @"\\");
                            installationPath.Insert(0, s_name);
                        }
                        else
                        {
                            installationPath.Insert(0, @"\\");
                            installationPath.Insert(0, "]");
                            installationPath.Insert(0, s_id);
                            installationPath.Insert(0, "[");
                        }
                        break;

                    case "TARGETDIR":
                        break;

                    default:
                        if (!String.IsNullOrEmpty(s_name))
                        {
                            installationPath.Insert(0, @"\\");
                            installationPath.Insert(0, s_name);
                        }
                        else
                        {
                            installationPath.Insert(0, @"\\");
                            installationPath.Insert(0, "]");
                            installationPath.Insert(0, s_id);
                            installationPath.Insert(0, "[");
                        }
                        break;
                }
            }

            return installationPath.ToString();
        }

        static void TransformComponentFile(string installationPath, XmlNode fileNode, XmlNamespaceManager nsm)
        {
            string name = fileNode.Attributes["Name"].Value;
            Console.WriteLine(@"\li File: <b>{0}{1}</b>", installationPath, name);
        }

        static string TransformComponentRegistryValue(XmlNode registryNode, XmlNamespaceManager nsm)
        {
            XmlAttribute root = null;
            XmlAttribute key = null;
            XmlAttribute action = null;

            if (registryNode.ParentNode.Name == "RegistryKey")
            {
                root = registryNode.ParentNode.Attributes["Root"];
                key = registryNode.ParentNode.Attributes["Key"];
                action = registryNode.ParentNode.Attributes["Action"];
            }
            else
            {
                root = registryNode.Attributes["Root"];
                key = registryNode.Attributes["Key"];
                action = registryNode.Attributes["Action"];
            }

            XmlAttribute name = registryNode.Attributes["Name"];
            XmlAttribute value = registryNode.Attributes["Value"];
            XmlAttribute type = registryNode.Attributes["Type"];

            string s_root = (root != null) ? root.Value : "";
            string s_key = (key != null) ? key.Value : "";
            string s_action = (action != null) ? action.Value : "";
            string s_name = (name != null) ? name.Value : "";
            string s_value = (value != null) ? value.Value : "";
            string s_type = (type != null) ? type.Value : "";

            return string.Format("<tr><td>{0}\\{1}</td><td>{2}</td><td>{3}</td><td>{4}</td><td>{5}</td></tr>",
                s_root, s_key.Replace(@"\", @"\\"), s_action, s_name, s_value.Replace(@"\", @"\\"), s_type);
        }

        static void TransformComponentEnvironment(XmlNode environmentNode, XmlNamespaceManager nsm)
        {
            XmlAttribute action = environmentNode.Attributes["Action"];
            XmlAttribute name = environmentNode.Attributes["Name"];
            XmlAttribute permanent = environmentNode.Attributes["Permanent"];
            XmlAttribute system = environmentNode.Attributes["System"];
            XmlAttribute value = environmentNode.Attributes["Value"];

            string s_action = (action != null) ? action.Value : "";
            string s_name = (name != null) ? name.Value : "";
            string s_permanent = (permanent != null) ? permanent.Value : "";
            string s_system = (system != null) ? system.Value : "";
            string s_value = (value != null) ? value.Value : "";

            Console.WriteLine(@"\li Environment Variable: {0}", s_name.Replace(@"\", @"\\"));
            Console.WriteLine(@"<UL><LI>Action - {0}</LI>", s_action);
            Console.WriteLine(@"<LI>Value - {0}</LI>", s_value.Replace(@"\", @"\\"));
            Console.WriteLine(@"<LI>Type - {0} variable</LI>", (s_system == "system" ? s_system : "user"));
            Console.WriteLine(@"<LI>Permanent - {0}</LI></UL>", s_permanent);
        }

        static void TransformComponentCondition(XmlNode conditionNode, XmlNamespaceManager nsm)
        {
            string s_condition = conditionNode.InnerText;
            Console.WriteLine(@"\li Condition: {0}", s_condition);
        }

        static void TransformProductFeatures(XmlNode product, string product_id, XmlNamespaceManager nsm)
        {
            TransformProductFeatures(product, null, product_id, nsm);
        }

        static void TransformProductFeatures(XmlNode product, XmlNode parent, string product_id, XmlNamespaceManager nsm)
        {
            XmlAttribute name = product.Attributes["Name"];
            string s_name = name != null ? name.Value : "Unknown";

            string features_id = string.Format("{0}_features", product_id);
            
            if (parent == null)
            {
                Console.WriteLine(@"\section {0} Features", features_id);
            }

            XmlNodeList features = (parent != null ? parent.SelectNodes("wix:Feature", nsm) : product.SelectNodes("wix:Feature", nsm));
            foreach (XmlNode feature in features)
            {
                XmlAttribute id = feature.Attributes["Id"];
                XmlAttribute title = feature.Attributes["Title"];
                string s_id = ExpandId(id != null ? id.Value : Guid.NewGuid().ToString());
                string s_title = title != null ? title.Value : string.Empty;
                string feature_id = string.Format("{0}_{1}", features_id, MakeId(s_id));
                Console.WriteLine(@"\subsection {0} {1}", feature_id, s_title);
                TransformComment(feature);
                TransformFeatureComponents(feature, product_id, nsm);
                TransformFeatureMerges(feature, product_id, nsm);
                TransformProductFeatures(product, feature, product_id, nsm);
            }
        }

        static void TransformFeatureComponents(XmlNode feature, string product_id, XmlNamespaceManager nsm)
        {
            XmlNodeList componentrefs = feature.SelectNodes("wix:ComponentRef", nsm);
            foreach (XmlNode componentref in componentrefs)
            {
                XmlAttribute id = componentref.Attributes["Id"];
                string s_id = id != null ? id.Value : "Unknown";
                string components_id = string.Format("{0}_components", product_id);
                string component_id = string.Format("{0}_{1}", components_id, MakeId(s_id));
                Console.WriteLine(string.Format(@"\li \ref {0}", component_id));
            }
        }

        static void TransformFeatureMerges(XmlNode feature, string product_id, XmlNamespaceManager nsm)
        {
            XmlNodeList mergerefs = feature.SelectNodes("wix:MergeRef", nsm);
            foreach (XmlNode mergeref in mergerefs)
            {
                XmlAttribute id = mergeref.Attributes["Id"];
                string s_id = id != null ? id.Value : "Unknown";
                string merges_id = string.Format("{0}_merges", product_id);
                string merge_id = string.Format("{0}_{1}", merges_id, MakeId(s_id));
                Console.WriteLine(string.Format(@"\li \ref {0}", merge_id));
            }
        }

        static void TransformProducts(XmlDocument xml, XmlNamespaceManager nsm)
        {
            XmlNodeList products = xml.SelectNodes("//wix:Product", nsm);
            foreach (XmlNode product in products)
            {
                // XmlAttribute id = product.Attributes["Id"];
                XmlAttribute name = product.Attributes["Name"];
                // string s_id = ExpandId(id != null ? id.Value : Guid.NewGuid().ToString());
                string s_name = name != null ? name.Value : "Unknown";
                string product_id = string.Format("{0}_wxs", MakeId(s_name));
                Console.WriteLine(string.Format(@"/*! \page {0} {1}", product_id, s_name));
                TransformPackages(product, nsm);
                TransformComment(product);
                TransformConditions(product, product_id, nsm);
                TransformProductFeatures(product, product_id, nsm);
                TransformComponents(product, product_id, nsm);
                TransformMerges(product, product_id, nsm);
                TransformProperties(product, product_id, nsm);
                Console.WriteLine(@"*/");
            }
        }

        static void TransformModules(XmlDocument xml, XmlNamespaceManager nsm)
        {
            XmlNodeList modules = xml.SelectNodes("//wix:Module", nsm);
            foreach (XmlNode module in modules)
            {
                XmlAttribute id = module.Attributes["Id"];
                string s_id = id != null ? id.Value : "Unknown";
                string module_id = string.Format("{0}_wxs", MakeId(s_id));
                Console.WriteLine(string.Format(@"/*! \page {0} {1}", module_id, s_id));
                TransformPackages(module, nsm);
                TransformComment(module);
                TransformComponents(module, module_id, nsm);
                TransformProperties(module, module_id, nsm);
                Console.WriteLine(@"*/");
            }
        }

        static void TransformComment(XmlNode node)
        {
            XmlNode comment = node.PreviousSibling;
            if (comment != null && comment.NodeType == XmlNodeType.Comment)
            {
                Console.WriteLine(comment.InnerText);
            }
        }

        static void TransformConditions(XmlNode product, string product_id, XmlNamespaceManager nsm)
        {
            string conditions_id = string.Format("{0}_conditions", product_id);
            XmlNodeList conditions = product.SelectNodes("wix:Condition", nsm);
            if (conditions.Count == 0)
                return;

            Console.WriteLine(@"\section {0} Prerequisites and Conditions", conditions_id);
            Console.WriteLine(@"<table>");
            foreach (XmlNode condition in conditions)
            {
                XmlAttribute message = condition.Attributes["Message"];
                string s_message = (message != null ? message.Value : string.Empty);
                string data = condition.InnerText.Trim();
                string condition_id = string.Format("{0}_{1}", conditions_id, MakeId(data));
                Console.WriteLine(@"<tr><td width=250><em>{0}</em></td><td>",data);
                TransformComment(condition);
                Console.WriteLine("<br /><em>{0}</em></td></tr>", s_message);
            }
            Console.WriteLine("</table>");
        }

        static void TransformProperties(XmlNode node, string product_id, XmlNamespaceManager nsm)
        {
            string properties_id = string.Format("{0}_properties", product_id);
            Console.WriteLine(@"\section {0} Properties", properties_id);

            {
                StringBuilder properties_s = new StringBuilder();

                // Note: I have not included propertyRef tag as all the properties defined by us should be available
                //       via wix:Property
                XmlNodeList properties = node.SelectNodes("wix:Property", nsm);

                foreach (XmlNode property in properties)
                {
                    XmlAttribute id = property.Attributes["Id"];
                    XmlAttribute value = property.Attributes["Value"];

                    string s_id = (id != null ? id.Value : string.Empty);
                    string s_value = (value != null ? value.Value : string.Empty);
                    XmlNode comment = property.PreviousSibling;

                    properties_s.AppendFormat(@"<tr><td><em>{0}</em></td><td>{1}</td><td>{2}</td></tr>",
                        s_id,
                        (comment != null && comment.NodeType == XmlNodeType.Comment) ? comment.InnerText : string.Empty,
                        s_value);
                }

                if (properties_s.Length != 0)
                {
                    Console.WriteLine(@"\subsection defined_{0} Defined Properties", properties_id);
                    Console.WriteLine();
                    Console.WriteLine(@"<table><tr><td>\b Property</td><td>\b Description</td><td>\b Default</td></tr>");
                    Console.WriteLine(properties_s.ToString());
                    properties_s.Append("</table>");
                }
            }

            {
                XmlNodeList customactions = node.SelectNodes("wix:CustomAction", nsm);
                StringBuilder properties_s = new StringBuilder();
                foreach (XmlNode ca in customactions)
                {
                    XmlAttribute property = ca.Attributes["Property"];

                    if (property == null)
                        continue;

                    XmlAttribute id = ca.Attributes["Id"];
                    XmlAttribute value = ca.Attributes["Value"];

                    string s_id = (id != null ? id.Value : string.Empty);
                    string s_property = (property != null ? property.Value : string.Empty);
                    string s_value = (value != null ? value.Value : string.Empty);
                    XmlNode comment = ca.PreviousSibling;

                    properties_s.AppendFormat(@"<tr><td><em>{0}</em></td><td>{1}</td><td>{2}</td><td>{3}</td></tr>",
                        s_property,
                        (comment != null && comment.NodeType == XmlNodeType.Comment) ? comment.InnerText : string.Empty,
                        s_value,
                        s_id);
                }

                if (properties_s.Length != 0)
                {
                    Console.WriteLine(@"\subsection ca_{0} Properties Set by Custom Actions", properties_id);
                    Console.WriteLine(@"<table><tr><td>\b Property</td><td>\b Description</td><td>\b Default</td><td><b>Custom Action</b></td></tr>");
                    Console.WriteLine(properties_s.ToString());
                    Console.WriteLine("</table>");
                }
            }
        }
    }
}
