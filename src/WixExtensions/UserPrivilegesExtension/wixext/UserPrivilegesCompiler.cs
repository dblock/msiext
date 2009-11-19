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
    using System.Diagnostics;

    using Microsoft.Tools.WindowsInstallerXml;

    /// <summary>
    /// The compiler for the Windows Installer XML Toolset UserPrivileges Extension.
    /// </summary>
    public sealed class UserPrivilegesCompiler : CompilerExtension
    {
        private XmlSchema schema;

        /// <summary>
        /// Instantiate a new UserPrivilegesCompiler.
        /// </summary>
        public UserPrivilegesCompiler()
        {
            this.schema = LoadXmlSchemaHelper(Assembly.GetExecutingAssembly(), "AppSecInc.Wix.Extensions.Xsd.UserPrivileges.xsd");
        }

        public override void FinalizeCompile()
        {
            Core.EnsureTable(null, "LocalUsers");
            Core.EnsureTable(null, "LocalGroups");
            Core.EnsureTable(null, "LocalGroupMembers");
            base.FinalizeCompile();
        }

        /// <summary>
        /// Gets the schema for this extension.
        /// </summary>
        /// <value>Schema for this extension.</value>
        public override XmlSchema Schema
        {
            get { return this.schema; }
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
                case "Product":
                case "Module":
                case "Fragment":
                    switch (element.LocalName)
                    {
                        case "LocalUser":
                            this.ParseLocalUserElement(null, element);
                            break;
                        case "LocalGroup":
                            this.ParseLocalGroupElement(null, element);
                            break;
                        case "LocalGroupMember":
                            this.ParseLocalGroupMemberElement(null, null, null, element);
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
                        case "LocalUser":
                            this.ParseLocalUserElement(componentId, element);
                            break;
                        case "LocalGroup":
                            this.ParseLocalGroupElement(componentId, element);
                            break;
                        case "LocalGroupMember":
                            this.ParseLocalGroupMemberElement(componentId, null, null, element);
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

        enum LocalUserAttributes
        {
            CreateOnInstall = 1,
            CreateOnUnInstall = 2,
            DeleteOnInstall = 4,
            DeleteOnUnInstall = 8,
            CheckIfExists = 16
        };

        private void ParseLocalUserElement(string componentid, XmlNode node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            string id = null;
            string username = null;
            string password = null;
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
                        case "Username":
                            username = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Password":
                            password = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "CreateOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalUserAttributes.CreateOnInstall;
                            }
                            break;
                        case "CreateOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalUserAttributes.CreateOnUnInstall;
                            }
                            break;
                        case "DeleteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalUserAttributes.DeleteOnInstall;
                            }
                            break;
                        case "DeleteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalUserAttributes.DeleteOnUnInstall;
                            }
                            break;
                        case "CheckIfExists":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalUserAttributes.CheckIfExists;
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

            if (null == username)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Username"));
            }

            // find unexpected child elements
            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    switch (child.LocalName)
                    {
                        case "LocalGroupMember":
                            this.ParseLocalGroupMemberElement(componentid, null, id, child);
                            break;
                        default:
                            this.Core.UnexpectedElement(node, child);
                            break;
                    }
                }
            }

            // reference the LocalUser custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateLocalUsers_Immediate");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateLocalUsers_Deferred");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DeleteLocalUsers_Immediate");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DeleteLocalUsers_Deferred");

            if (! Core.EncounteredError)
            {
                // create a row in the LocalUsers table
                Row row = Core.CreateRow(sourceLineNumbers, "LocalUsers");
                row[0] = id;
                row[1] = componentid;
                row[2] = username;
                row[3] = password;
                row[4] = attributes;
            }
        }

        enum LocalGroupAttributes
        {
            CreateOnInstall = 1,
            CreateOnUnInstall = 2,
            DeleteOnInstall = 4,
            DeleteOnUnInstall = 8,
            CheckIfExists = 16
        };

        private void ParseLocalGroupElement(string componentid, XmlNode node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            string id = null;
            string name = null;
            string description = null;
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
                        case "Name":
                            name = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Description":
                            description = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "CreateOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupAttributes.CreateOnInstall;
                            }
                            break;
                        case "CreateOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupAttributes.CreateOnUnInstall;
                            }
                            break;
                        case "DeleteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupAttributes.DeleteOnInstall;
                            }
                            break;
                        case "DeleteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupAttributes.DeleteOnUnInstall;
                            }
                            break;
                        case "CheckIfExists":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupAttributes.CheckIfExists;
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

            if (null == name)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Name"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    switch (child.LocalName)
                    {
                        case "LocalGroupMember":
                            this.ParseLocalGroupMemberElement(componentid, id, null, child);
                            break;
                        default:
                            this.Core.UnexpectedElement(node, child);
                            break;
                    }
                }
            }

            // reference the LocalGroup custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateLocalGroups_Immediate");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateLocalGroups_Deferred");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DeleteLocalGroups_Immediate");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DeleteLocalGroups_Deferred");

            if (!Core.EncounteredError)
            {
                // create a row in the LocalGroups table
                Row row = Core.CreateRow(sourceLineNumbers, "LocalGroups");
                row[0] = id;
                row[1] = componentid;
                row[2] = name;
                row[3] = description;
                row[4] = attributes;
            }
        }

        enum LocalGroupMemberAttributes
        {
            AddOnInstall = 1,
            AddOnUnInstall = 2,
            RemoveOnInstall = 4,
            RemoveOnUnInstall = 8,
            CheckIfMember = 16
        };

        private void ParseLocalGroupMemberElement(string componentid, string groupid, string userid, XmlNode node)
        {
            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            string id = null;
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
                        case "GroupId":
                            if (!string.IsNullOrEmpty(groupid))
                            {
                                this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            }
                            groupid = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "UserId":
                            if (!string.IsNullOrEmpty(userid))
                            {
                                this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            }
                            userid = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "AddOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupMemberAttributes.AddOnInstall;
                            }
                            break;
                        case "AddOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupMemberAttributes.AddOnUnInstall;
                            }
                            break;
                        case "RemoveOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupMemberAttributes.RemoveOnInstall;
                            }
                            break;
                        case "RemoveOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupMemberAttributes.RemoveOnUnInstall;
                            }
                            break;
                        case "CheckIfMember":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)LocalGroupMemberAttributes.CheckIfMember;
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

            if (null == userid)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "UserId"));
            }

            if (null == groupid)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "GroupId"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    this.Core.UnsupportedExtensionElement(node, child);
                }
            }

            // reference the LocalGroup custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "AddLocalGroupMembers_Immediate");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "AddLocalGroupMembers_Deferred");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "RemoveLocalGroupMembers_Immediate");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "RemoveLocalGroupMembers_Deferred");

            if (!Core.EncounteredError)
            {
                // create a row in the LocalGroupMembers table
                Row row = Core.CreateRow(sourceLineNumbers, "LocalGroupMembers");
                row[0] = id;
                row[1] = componentid;
                row[2] = userid;
                row[3] = groupid;
                row[4] = attributes;
            }
        }
    }
}
