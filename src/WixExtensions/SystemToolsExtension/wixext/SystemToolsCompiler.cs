namespace AppSecInc.Wix.Extensions
{
    using System;
    using System.Collections;
    using System.Globalization;
    using System.Reflection;
    using System.Text;
    using System.Text.RegularExpressions;
    using System.Xml;
    using System.Xml.Schema;

    using Microsoft.Tools.WindowsInstallerXml;

    /// <summary>
    /// The compiler for the Windows Installer XML Toolset SystemTools Extension.
    /// </summary>
    public sealed class SystemToolsCompiler : CompilerExtension
    {
        private XmlSchema schema;

        /// <summary>
        /// Instantiate a new SystemToolsCompiler.
        /// </summary>
        public SystemToolsCompiler()
        {
            this.schema = LoadXmlSchemaHelper(Assembly.GetExecutingAssembly(), "AppSecInc.Wix.Extensions.Xsd.SystemTools.xsd");
        }

        /// <summary>
        /// Gets the schema for this extension.
        /// </summary>
        /// <value>Schema for this extension.</value>
        public override XmlSchema Schema
        {
            get { return this.schema; }
        }

        public override void FinalizeCompile()
        {
            Core.EnsureTable(null, "Win32_CopyFiles");
            Core.EnsureTable(null, "Win32_DeleteFiles");
            Core.EnsureTable(null, "Win32_Execute");
            Core.EnsureTable(null, "CompareVersions");
            Core.EnsureTable(null, "TemplateFiles");
            Core.EnsureTable(null, "TemplateFileProperties");
            Core.EnsureTable(null, "RegistryCopy");
            base.FinalizeCompile();
        }

        /// <summary>
        /// Processes an element for the Compiler.
        /// </summary>
        /// <param name="sourceLineNumbers">Source line number for the parent element.</param>
        /// <param name="parentElement">Parent element of element to process.</param>
        /// <param name="element">Element to process.</param>
        /// <param name="contextValues">Extra information about the context in which this element is being parsed.</param>
        public override void ParseElement(SourceLineNumberCollection sourceLineNumbers, XmlElement parentElement, XmlElement element, params string[] contextValues)
        {
            switch (parentElement.LocalName)
            {
                case "Fragment":
                case "Module":
                case "Product":
                    switch (element.LocalName)
                    {
                        case "CopyFile":
                        case "CopyFiles":
                            this.ParseCopyFileElement(element);
                            break;
                        case "MoveFile":
                        case "MoveFiles":
                            this.ParseMoveFileElement(element);
                            break;
                        case "DeleteFile":
                        case "DeleteFiles":
                            this.ParseDeleteFileElement(element);
                            break;
                        case "CompareVersion":
                            this.ParseCompareVersionElement(element);
                            break;
                        case "Execute":
                            this.ParseExecuteElement(null, false, element);
                            break;
                        case "ScheduleExecute":
                            this.ParseExecuteElement(null, true, element);
                            break;
                        case "TemplateFile":
                            this.ParseTemplateFileElement(null, element);
                            break;
                        default:
                            this.Core.UnexpectedElement(parentElement, element);
                            break;
                    }
                    break;
                case "Component":
                    string componentId = contextValues[0];
                    switch (element.LocalName)
                    {
                        case "Execute":
                            this.ParseExecuteElement(componentId, false, element);
                            break;
                        case "ScheduleExecute":
                            this.ParseExecuteElement(null, true, element);
                            break;
                        case "TemplateFile":
                            this.ParseTemplateFileElement(componentId, element);
                            break;
                        default:
                            this.Core.UnexpectedElement(parentElement, element);
                            break;
                    }
                    break;
                case "RegistryKey":
                    string registryKeyId = contextValues[0];
                    switch (element.LocalName)
                    {
                        case "RegistryKeyCopy":
                            this.ParseRegistryCopyElement(registryKeyId, element);
                            break;
                        default:
                            this.Core.UnexpectedElement(parentElement, element);
                            break;
                    }
                    break;
                default:
                    this.Core.UnexpectedElement(parentElement, element);
                    break;
            }
        }

        enum CopyFileAttributes
        {
            CopyOnInstall = 1,
            CopyOnUnInstall = 2,
            // CopyOnRollback = 4,
            // CopyOnReInstall = 8,
            CopyRecurse = 16,
        };

        private void ParseCopyFileElement(XmlNode node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);
            string sourceName = null;
            string targetName = null;
            string overwrite = null;
            string wildcard = null;
            string id = null;
            string condition = null;
            int attributes = 0;

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Source":
                            sourceName = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Target":
                            targetName = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Wildcard":
                            wildcard = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Overwrite":
                            overwrite = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "CopyOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)CopyFileAttributes.CopyOnInstall;
                            }
                            break;
                        case "CopyOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)CopyFileAttributes.CopyOnUnInstall;
                            }
                            break;
                        case "Recurse":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)CopyFileAttributes.CopyRecurse;
                            }
                            break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }
                }
                else
                {
                    this.Core.UnsupportedExtensionAttribute(sourceLineNumbers, attrib);
                }
            }

            if (null == id)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Id"));
            }

            if (null == sourceName)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Source"));
            }

            if (null == targetName)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Target"));
            }

            if (attributes == 0)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "CopyOnInstall"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    if (child.NamespaceURI == this.schema.TargetNamespace)
                    {
                        this.Core.UnexpectedElement(node, child);
                    }
                    else
                    {
                        this.Core.UnsupportedExtensionElement(node, child);
                    }
                }
                else if (XmlNodeType.CDATA == child.NodeType || XmlNodeType.Text == child.NodeType)
                {
                    condition = child.Value.Trim();
                }
            }

            // reference the Win32_CopyFiles custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_CopyFiles_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_CopyFiles_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_CopyFiles_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_CopyFiles_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the Win32_CopyFiles table
                Row row = Core.CreateRow(sourceLineNumbers, "Win32_CopyFiles");
                row[0] = id;
                row[1] = sourceName;
                row[2] = targetName;
                row[3] = wildcard;
                row[4] = overwrite;
                row[5] = condition;
                row[6] = attributes;
            }
        }

        enum MoveFileAttributes
        {
            MoveOnInstall = 1,
            MoveOnUnInstall = 2,
            // MoveOnRollback = 4,
            // MoveOnReInstall = 8,
            MoveRecurse = 16,
            MoveDeleteEmptyDirectories = 32,
        };

        private void ParseMoveFileElement(XmlNode node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);
            string sourceName = null;
            string targetName = null;
            string wildcard = null;
            string overwrite = null;
            string id = null;
            string condition = null;
            int attributes = 0;

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Source":
                            sourceName = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Target":
                            targetName = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Wildcard":
                            wildcard = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Overwrite":
                            overwrite = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "MoveOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MoveFileAttributes.MoveOnInstall;
                            }
                            break;
                        case "MoveOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MoveFileAttributes.MoveOnUnInstall;
                            }
                            break;
                        case "Recurse":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MoveFileAttributes.MoveRecurse;
                            }
                            break;
                        case "DeleteEmptyDirectories":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MoveFileAttributes.MoveDeleteEmptyDirectories;
                            }
                            break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }
                }
                else
                {
                    this.Core.UnsupportedExtensionAttribute(sourceLineNumbers, attrib);
                }
            }

            if (null == id)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Id"));
            }

            if (null == sourceName)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Source"));
            }

            if (null == targetName)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Target"));
            }

            if (attributes == 0)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "MoveOnInstall"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    if (child.NamespaceURI == this.schema.TargetNamespace)
                    {
                        this.Core.UnexpectedElement(node, child);
                    }
                    else
                    {
                        this.Core.UnsupportedExtensionElement(node, child);
                    }
                }
                else if (XmlNodeType.CDATA == child.NodeType || XmlNodeType.Text == child.NodeType)
                {
                    condition = child.Value.Trim();
                }
            }

            // reference the Win32_MoveFiles custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_MoveFiles_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_MoveFiles_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_MoveFiles_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_MoveFiles_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the Win32_MoveFiles table
                Row row = Core.CreateRow(sourceLineNumbers, "Win32_MoveFiles");
                row[0] = id;
                row[1] = sourceName;
                row[2] = targetName;
                row[3] = wildcard;
                row[4] = overwrite;
                row[5] = condition;
                row[6] = attributes;
            }
        }

        enum DeleteFileAttributes
        {
            DeleteOnInstall = 1,
            DeleteOnUnInstall = 2,
            // DeleteOnRollback = 4,
            // DeleteOnReInstall = 8,
            CheckIfExists = 16,
            DeleteRecurse = 32,
            DeleteEmptyDirectories = 64,
        };

        private void ParseDeleteFileElement(XmlNode node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);
            string file = null;
            string wildcard = null;
            string id = null;
            string condition = null;
            int attributes = 0;

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "File":
                        case "Path":
                            file = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Wildcard":
                            wildcard = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "DeleteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)DeleteFileAttributes.DeleteOnInstall;
                            }
                            break;
                        case "DeleteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)DeleteFileAttributes.DeleteOnUnInstall;
                            }
                            break;
                        case "CheckIfExists":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)DeleteFileAttributes.CheckIfExists;
                            }
                            break;
                        case "Recurse":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)DeleteFileAttributes.DeleteRecurse;
                            }
                            break;
                        case "DeleteEmptyDirectories":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)DeleteFileAttributes.DeleteEmptyDirectories;
                            }
                            break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }
                }
                else
                {
                    this.Core.UnsupportedExtensionAttribute(sourceLineNumbers, attrib);
                }
            }

            if (null == id)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Id"));
            }

            if (null == file)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "File"));
            }

            if (attributes == 0)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "DeleteOnInstall"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    if (child.NamespaceURI == this.schema.TargetNamespace)
                    {
                        this.Core.UnexpectedElement(node, child);
                    }
                    else
                    {
                        this.Core.UnsupportedExtensionElement(node, child);
                    }
                }
                else if (XmlNodeType.CDATA == child.NodeType || XmlNodeType.Text == child.NodeType)
                {
                    condition = child.Value.Trim();
                }
            }

            // reference the Win32_DeleteFiles custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_DeleteFiles_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_DeleteFiles_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_DeleteFiles_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_DeleteFiles_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the Win32_DeleteFiles table
                Row row = Core.CreateRow(sourceLineNumbers, "Win32_DeleteFiles");
                row[0] = id;
                row[1] = file;
                row[2] = wildcard;
                row[3] = condition;
                row[4] = attributes;
            }
        }

        private void ParseCompareVersionElement(XmlElement node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);
            string installVersion = null;
            string minVersion = null;
            string maxVersion = null;
            string property = null;
            string id = null;

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeIdentifierValue(sourceLineNumbers, attrib);
                            break;
                        case "InstalledVersion":
                            installVersion = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Property":
                            property = this.Core.GetAttributeIdentifierValue(sourceLineNumbers, attrib);
                            break;
                        case "MinimumVersion":
                            minVersion = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "MaximumVersion":
                            maxVersion = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }
                }
                else
                {
                    this.Core.UnsupportedExtensionAttribute(sourceLineNumbers, attrib);
                }
            }

            if (null == id)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Id"));
            }

            if (null == installVersion)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "InstalledVersion"));
            }

            if (null == minVersion)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "MinimumVersion"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    if (child.NamespaceURI == this.schema.TargetNamespace)
                    {
                        this.Core.UnexpectedElement(node, child);
                    }
                    else
                    {
                        this.Core.UnsupportedExtensionElement(node, child);
                    }
                }
            }

            // Reference CustomAction since nothing will happen without it
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CompareVersions");

            if (!this.Core.EncounteredError)
            {
                Row row = this.Core.CreateRow(sourceLineNumbers, "CompareVersions");
                row[0] = id;
                row[1] = installVersion;
                row[2] = minVersion;
                row[3] = maxVersion;
                row[4] = property;
            }
        }

        enum ExecuteAttributes
        {
            ContinueOnError = 1,
            ExecuteOnInstall = 2,
            ExecuteOnUnInstall = 4,
            ExecuteOnRollback = 8,
            // ExecuteOnReInstall = 16,
            ScheduleIndependently = 32
        };

        private void ParseExecuteElement(string componentid, bool scheduleIndependently, XmlElement node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);
            string id = null;
            string directory = null;
            string commandline = null;
            string errormessage = null;
            string condition = null;
            int returncode = 0;
            int attributes = (scheduleIndependently ? (int)ExecuteAttributes.ScheduleIndependently : 0);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeIdentifierValue(sourceLineNumbers, attrib);
                            break;
                        case "Directory":
                            directory = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "CommandLine":
                            commandline = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "ErrorMessage":
                            errormessage = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "ReturnCode":
                            returncode = this.Core.GetAttributeIntegerValue(sourceLineNumbers, attrib, int.MinValue, int.MaxValue);
                            break;
                        case "ContinueOnError":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ExecuteAttributes.ContinueOnError;
                            }
                            break;
                        case "ExecuteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ExecuteAttributes.ExecuteOnInstall;
                            }
                            break;
                        case "ExecuteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ExecuteAttributes.ExecuteOnUnInstall;
                            }
                            break;
                        case "ExecuteOnRollback":
                            
                            if (!scheduleIndependently)
                            {
                                // rollback is currently not supported for not explicitly scheduled CAs
                                this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            }

                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ExecuteAttributes.ExecuteOnRollback;
                            }

                            break;
                        //case "ExecuteOnReInstall":
                        //    if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                        //    {
                        //        attributes |= (int)ExecuteAttributes.ExecuteOnReInstall;
                        //    }
                        //    break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }
                }
                else
                {
                    this.Core.UnsupportedExtensionAttribute(sourceLineNumbers, attrib);
                }
            }

            if (null == id)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Id"));
            }

            if (null == commandline)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "CommandLine"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    if (child.NamespaceURI == this.schema.TargetNamespace)
                    {
                        this.Core.UnexpectedElement(node, child);
                    }
                    else
                    {
                        this.Core.UnsupportedExtensionElement(node, child);
                    }
                }
                else if (XmlNodeType.CDATA == child.NodeType || XmlNodeType.Text == child.NodeType)
                {
                    condition = child.Value.Trim();
                }
            }

            // Reference CustomAction since nothing will happen without it
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_Execute_Immediate");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_Execute_Deferred");

            // A scheduled custom action is explicitly defined with the name Id
            if (scheduleIndependently)
            {
                if (!this.Core.EncounteredError)
                {
                    Row row = this.Core.CreateRow(sourceLineNumbers, "CustomAction");
                    row[0] = id; // action, \todo check that this is properly modularized in a merge module
                    bool rollback = (attributes & (int) ExecuteAttributes.ExecuteOnRollback) != 0;
                    row[1] = 1 + (rollback ? 1280 : 1024); // type 1 CA, deferred or rollback
                    row[2] = "SystemToolsCA"; // source
                    row[3] = "Win32_Execute_Deferred"; // target
                }
            }

            if (!this.Core.EncounteredError)
            {
                Row row = this.Core.CreateRow(sourceLineNumbers, "Win32_Execute");
                row[0] = id;
                row[1] = componentid;
                row[2] = condition;
                row[3] = directory;
                row[4] = commandline;
                row[5] = errormessage;
                row[6] = returncode;
                row[7] = attributes;
            }
        }

        enum TemplateFileAttributes
        {
            ExecuteOnInstall = 1,
            ExecuteOnUnInstall = 2,
            // ExecuteOnRollback = 4,
            ExecuteOnReInstall = 8,
        };

        private void ParseTemplateFileElement(string componentid, XmlElement node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);
            string id = null;
            string source = null;
            string target = null;
            string condition = null;
            int attributes = 0;

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeIdentifierValue(sourceLineNumbers, attrib);
                            break;
                        case "Source":
                            source = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Target":
                            target = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "ExecuteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)TemplateFileAttributes.ExecuteOnInstall;
                            }
                            break;
                        case "ExecuteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)TemplateFileAttributes.ExecuteOnUnInstall;
                            }
                            break;
                        case "ExecuteOnReInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)TemplateFileAttributes.ExecuteOnReInstall;
                            }
                            break;
                        //case "ExecuteOnRollback":
                        //    if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                        //    {
                        //        attributes |= (int)TemplateFileAttributes.ExecuteOnRollback;
                        //    }
                        //    break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }
                }
                else
                {
                    this.Core.UnsupportedExtensionAttribute(sourceLineNumbers, attrib);
                }
            }

            if (null == id)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Id"));
            }

            if (null == source)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Source"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    switch (child.LocalName)
                    {
                        case "TemplateFileProperty":
                            this.ParseTemplateFileProperty(id, child);
                            break;
                        case "Condition":
                            condition = child.Value.Trim();
                            break;
                        default:
                            this.Core.UnexpectedElement(node, child);
                            break;
                    }
                }
            }

            // Reference CustomAction since nothing will happen without it
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "TemplateFiles_Immediate");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "TemplateFiles_Deferred");

            if (!this.Core.EncounteredError)
            {
                Row row = this.Core.CreateRow(sourceLineNumbers, "TemplateFiles");
                row[0] = id;
                row[1] = componentid;
                row[2] = condition;
                row[3] = source;
                row[4] = target;
                row[5] = attributes;
            }
        }

        private void ParseTemplateFileProperty(string templatefileid, XmlNode node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);
            string id = null;
            string name = null;
            string value = null;
            int escape = 0;

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeIdentifierValue(sourceLineNumbers, attrib);
                            break;
                        case "Name":
                            name = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Value":
                            value = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Escape":
                            escape = this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes ? 1 : 0;
                            break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }
                }
                else
                {
                    this.Core.UnsupportedExtensionAttribute(sourceLineNumbers, attrib);
                }
            }

            if (null == id)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Id"));
            }

            if (null == name)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Name"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    if (child.NamespaceURI == this.schema.TargetNamespace)
                    {
                        this.Core.UnexpectedElement(node, child);
                    }
                    else
                    {
                        this.Core.UnsupportedExtensionElement(node, child);
                    }
                }
            }

            if (!this.Core.EncounteredError)
            {
                Row row = this.Core.CreateRow(sourceLineNumbers, "TemplateFileProperties");
                row[0] = id;
                row[1] = templatefileid;
                row[2] = name;
                row[3] = value;
                row[4] = escape;
            }
        }

        enum RegistryCopyAttributes
        {
            CopyOnInstall = 1,
            CopyOnUnInstall = 2,
            RestoreOnRollback = 4,
            // CopyOnReInstall = 8,
            CheckIfExists = 16,
            RemoveSource = 32,
            Overwrite = 64,
        };

        private void ParseRegistryCopyElement(string registryKeyId, XmlNode node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            string id = null;
            string targetroot = null;
            string targetpath = null;
            string condition = null;
            int attributes = 0;

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "TargetRoot":
                            targetroot = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "TargetPath":
                            targetpath = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "CopyOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)RegistryCopyAttributes.CopyOnInstall;
                            }
                            break;
                        case "CopyOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)RegistryCopyAttributes.CopyOnUnInstall;
                            }
                            break;
                        case "RemoveSource":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)RegistryCopyAttributes.RemoveSource;
                            }
                            break;
                        case "CheckIfExists":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)RegistryCopyAttributes.CheckIfExists;
                            }
                            break;
                        case "Overwrite":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)RegistryCopyAttributes.Overwrite;
                            }
                            break;
                        case "RestoreOnRollback":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)RegistryCopyAttributes.RestoreOnRollback;
                            }
                            break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }
                }
                else
                {
                    this.Core.UnsupportedExtensionAttribute(sourceLineNumbers, attrib);
                }
            }

            if (null == id)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Id"));
            }

            if (null == targetpath)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "TargetPath"));
            }

            if (((attributes & (int)RegistryCopyAttributes.RestoreOnRollback) > 0) &&
                ((attributes & (int)RegistryCopyAttributes.CopyOnInstall) == 0))
            {
                this.Core.OnMessage(WixErrors.IllegalAttributeValueWithoutOtherAttribute(sourceLineNumbers,
                    "RegistryCopy", "RestoreOnRollback", "yes", "CopyOnInstall"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    switch (child.LocalName)
                    {
                        case "Condition":
                            condition = child.Value.Trim();
                            break;
                        default:
                            this.Core.UnexpectedElement(node, child);
                            break;
                    }
                }
            }

            // reference the Win32_RegistryKeys custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_RegistryCopy_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_RegistryCopy_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_RegistryCopy_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_RegistryCopy_Deferred_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Win32_RegistryCopy_Rollback");

            if (!Core.EncounteredError)
            {
                // create a row in the Win32_RegistryKeys table
                Row row = Core.CreateRow(sourceLineNumbers, "RegistryCopy");
                row[0] = id;
                row[1] = registryKeyId;
                row[2] = targetroot;
                row[3] = targetpath;
                row[4] = condition;
                row[5] = attributes;
            }
        }
    }
}
