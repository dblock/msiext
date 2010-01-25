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
    /// The compiler for the Windows Installer XML Toolset DataSource Extension.
    /// </summary>
    public sealed class DataSourceCompiler : CompilerExtension
    {
        private XmlSchema schema;

        /// <summary>
        /// Instantiate a new DataSourceCompiler.
        /// </summary>
        public DataSourceCompiler()
        {
            this.schema = LoadXmlSchemaHelper(Assembly.GetExecutingAssembly(), "AppSecInc.Wix.Extensions.Xsd.DataSource.xsd");
        }

        public override void FinalizeCompile()
        {
            Core.EnsureTable(null, "DatabaseConnectionString");
            Core.EnsureTable(null, "ODBCExecute");
            Core.EnsureTable(null, "ODBCDataSourceConfig"); // (?) there's already a definition for ODBCDataSource
            Core.EnsureTable(null, "MSSQLDatabase");
            Core.EnsureTable(null, "MSSQLDatabaseOption");
            Core.EnsureTable(null, "MSSQLDatabaseFileSpec");
            Core.EnsureTable(null, "MSSQLDataFile");
            Core.EnsureTable(null, "MSSQLDataFileParameter");
            Core.EnsureTable(null, "AccessDatabase");
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
                case "Fragment":
                case "Module":
                case "Product":
                    switch (element.LocalName)
                    {
                        case "ODBCConnection":
                            this.ParseODBCConnectionElement(element);
                            break;
                        case "MSSQLDatabaseConnection":
                            this.ParseMSSQLDatabaseConnectionElement(element);
                            break;
                        case "MSSQLDatabase":
                            this.ParseMSSQLDatabaseElement(null, element);
                            break;
                        case "MSSQLDataFile":
                        case "MSSQLDataBinaryFile":
                            this.ParseMSSQLDataFile(null, null, null, element);
                            break;
                        case "AccessDatabaseConnection":
                            this.ParseAccessDatabaseConnectionElement(element);
                            break;
                        case "AccessDatabase":
                            this.ParseAccessDatabaseElement(null, element);
                            break;
                        case "ODBCExecute":
                        case "ODBCExecuteBinary":
                        case "ODBCExecuteFile":
                            this.ParseODBCExecute(null, null, element);
                            break;
                        case "ODBCDataSource":
                            this.ParseODBCDataSource(null, element);
                            break;
                        case "MSSQLDataSource":
                            this.ParseMSSQLDataSource(null, element);
                            break;
                        case "AccessDataSource":
                            this.ParseAccessDataSource(null, element);
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
                        case "MSSQLDatabase":
                            this.ParseMSSQLDatabaseElement(componentId, element);
                            break;
                        case "MSSQLDataFile":
                        case "MSSQLDataBinaryFile":
                            this.ParseMSSQLDataFile(componentId, null, null, element);
                            break;
                        case "AccessDatabase":
                            this.ParseAccessDatabaseElement(componentId, element);
                            break;
                        case "ODBCExecute":
                        case "ODBCExecuteBinary":
                        case "ODBCExecuteFile":
                            this.ParseODBCExecute(componentId, null, element);
                            break;
                        case "ODBCDataSource":
                            this.ParseODBCDataSource(componentId, element);
                            break;
                        case "MSSQLDataSource":
                            this.ParseMSSQLDataSource(componentId, element);
                            break;
                        case "AccessDataSource":
                            this.ParseAccessDataSource(componentId, element);
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

        private void ParseODBCConnectionElement(XmlNode node)
        {
            string connectionstring = null;
            string id = null;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "ConnectionString":
                            connectionstring = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
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

            if (string.IsNullOrEmpty(connectionstring))
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "ConnectionString"));
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
                else
                {
                    this.Core.UnsupportedExtensionElement(node, child);
                }
            }

            if (!Core.EncounteredError)
            {
                // create a row in the DatabaseConnectionString table
                Row row = Core.CreateRow(sourceLineNumbers, "DatabaseConnectionString");
                row[0] = id;
                row[1] = connectionstring;
            }
        }

        private void ParseMSSQLDatabaseConnectionElement(XmlNode node)
        {
            MSSQLConnectionInfo connectionInfo = new MSSQLConnectionInfo();
            string id = null;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "IpAddress":
                            connectionInfo.IpAddress = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Port":
                            connectionInfo.Port = this.Core.GetAttributeIntegerValue(sourceLineNumbers, attrib, 0, int.MaxValue);
                            break;
                        case "Protocol":
                            connectionInfo.Protocol = (ODBCConnectionProtocol)Enum.Parse(typeof(ODBCConnectionProtocol),
                                this.Core.GetAttributeValue(sourceLineNumbers, attrib));
                            break;
                        case "Instance":
                            connectionInfo.InstanceName = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Username":
                            connectionInfo.Username = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Password":
                            connectionInfo.Password = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Database":
                            connectionInfo.Database = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Application":
                            connectionInfo.AppName = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "NamedPipe":
                            connectionInfo.NamedPipe = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "WindowsAuthentication":
                            connectionInfo.TrustedAuth = (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes);
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

            if (null == connectionInfo.IpAddress)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "IpAddress"));
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
                else
                {
                    this.Core.UnsupportedExtensionElement(node, child);
                }
            }

            if (!Core.EncounteredError)
            {
                // create a row in the DatabaseConnectionString table
                Row row = Core.CreateRow(sourceLineNumbers, "DatabaseConnectionString");
                row[0] = id;
                row[1] = connectionInfo.ConnectionString;
            }
        }

        private void ParseAccessDatabaseConnectionElement(XmlNode node)
        {
            AccessConnectionInfo connectionInfo = new AccessConnectionInfo();
            string id = null;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "DBQ":
                            connectionInfo.DBQ = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Username":
                            connectionInfo.Username = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Password":
                            connectionInfo.Password = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
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

            if (null == connectionInfo.DBQ)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "DBQ"));
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
                else
                {
                    this.Core.UnsupportedExtensionElement(node, child);
                }
            }

            if (!Core.EncounteredError)
            {
                // create a row in the DatabaseConnectionString table
                Row row = Core.CreateRow(sourceLineNumbers, "DatabaseConnectionString");
                row[0] = id;
                row[1] = connectionInfo.ConnectionString;
            }
        }

        enum MSSQLDatabaseAttributes
        {
            CreateOnInstall = 1,
            DropOnUnInstall = 2,
            DropOnInstall = 4,
            CreateOnUnInstall = 16,
            CheckIfExists = 32
        };

        private void ParseMSSQLDatabaseElement(string componentid, XmlNode node)
        {
            string id = null;
            string name = null;
            string collate = null;
            string purpose = null;
            string connectionstringid = null;
            int attributes = 0;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

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
                        case "Collate":
                            collate = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Purpose":
                            purpose = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "ConnectionId":
                            connectionstringid = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "CreateOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MSSQLDatabaseAttributes.CreateOnInstall;
                            }
                            break;
                        case "CreateOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MSSQLDatabaseAttributes.CreateOnUnInstall;
                            }
                            break;
                        case "DropOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MSSQLDatabaseAttributes.DropOnInstall;
                            }
                            break;
                        case "DropOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MSSQLDatabaseAttributes.DropOnUnInstall;
                            }
                            break;
                        case "CheckIfExists":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MSSQLDatabaseAttributes.CheckIfExists;
                            }
                            break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }

                    if (node.ParentNode.LocalName != "Component")
                    {
                        this.Core.OnMessage(WixErrors.UnexpectedAttribute(sourceLineNumbers, node.Name, attrib.Name));
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

            if (null == connectionstringid)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "ConnectionId"));
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
                        case "MSSQLDatabaseOption":
                            this.ParseMSSQLDatabaseOption(id, child);
                            break;
                        case "MSSQLDatabaseFileSpec":
                            this.ParseMSSQLDatabaseFileSpec(id, child);
                            break;
                        case "MSSQLDataFile":
                        case "MSSQLDataBinaryFile":
                            this.ParseMSSQLDataFile(componentid, connectionstringid, name, child);
                            break;
                        case "ODBCExecute":
                        case "ODBCExecuteBinary":
                        case "ODBCExecuteFile":
                            this.ParseODBCExecute(componentid, connectionstringid, child);
                            break;
                        default:
                            this.Core.UnexpectedElement(node, child);
                            break;
                    }
                }
            }

            // reference the DataSource custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateDatabases_SQLServer_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateDatabases_SQLServer_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateDatabases_SQLServer_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateDatabases_SQLServer_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the MSSQLDatabase table
                Row row = Core.CreateRow(sourceLineNumbers, "MSSQLDatabase");
                row[0] = id;
                row[1] = componentid;
                row[2] = name;
                row[3] = collate;
                row[4] = purpose;
                row[5] = connectionstringid;
                row[6] = attributes;
            }
        }

        private void ParseMSSQLDatabaseOption(string mssqldatabaseid, XmlNode node)
        {
            string id = null;
            string value = null;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Value":
                            value = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
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

            if (null == value)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Value"));
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
                else
                {
                    this.Core.UnsupportedExtensionElement(node, child);
                }
            }

            if (!Core.EncounteredError)
            {
                // create a row in the MSSQLDatabaseOption table
                Row row = Core.CreateRow(sourceLineNumbers, "MSSQLDatabaseOption");
                row[0] = id;
                row[1] = mssqldatabaseid;
                row[2] = value;
            }
        }

        private void ParseMSSQLDatabaseFileSpec(string mssqldatabaseid, XmlNode node)
        {
            string id = null;
            string name = null;
            string filename = null;
            string type = null;
            string size = null;
            string maxsize = null;
            string growthsize = null;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

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
                        case "Filename":
                            filename = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Type":
                            type = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Size":
                            size = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "MaxSize":
                            maxsize = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "GrowthSize":
                            growthsize = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
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

            if (null == filename)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Filename"));
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
                else
                {
                    this.Core.UnsupportedExtensionElement(node, child);
                }
            }

            if (!Core.EncounteredError)
            {
                // create a row in the MSSQLDatabaseFileSpec table
                Row row = Core.CreateRow(sourceLineNumbers, "MSSQLDatabaseFileSpec");
                row[0] = id;
                row[1] = mssqldatabaseid;
                row[2] = name;
                row[3] = filename;
                row[4] = type;
                row[5] = size;
                row[6] = maxsize;
                row[7] = growthsize;
            }
        }

        enum AccessDatabaseAttributes
        {
            CreateOnInstall = 1,
            DropOnUnInstall = 2,
            DropOnInstall = 4,
            CreateOnUnInstall = 16,
            CheckIfExists = 32
        };

        private void ParseAccessDatabaseElement(string componentid, XmlNode node)
        {
            string id = null;
            string dbq = null;
            string connectionstringid = null;
            int attributes = 0;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "DBQ":
                            dbq = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "ConnectionId":
                            connectionstringid = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "CreateOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)AccessDatabaseAttributes.CreateOnInstall;
                            }
                            break;
                        case "CreateOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)AccessDatabaseAttributes.CreateOnUnInstall;
                            }
                            break;
                        case "DropOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)AccessDatabaseAttributes.DropOnInstall;
                            }
                            break;
                        case "DropOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)AccessDatabaseAttributes.DropOnUnInstall;
                            }
                            break;
                        case "CheckIfExists":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)AccessDatabaseAttributes.CheckIfExists;
                            }
                            break;
                        default:
                            this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            break;
                    }

                    if (node.ParentNode.LocalName != "Component")
                    {
                        this.Core.OnMessage(WixErrors.UnexpectedAttribute(sourceLineNumbers, node.Name, attrib.Name));
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

            if (null == connectionstringid)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "ConnectionId"));
            }

            if (null == dbq)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "DBQ"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    switch (child.LocalName)
                    {
                        case "ODBCExecute":
                        case "ODBCExecuteBinary":
                        case "ODBCExecuteFile":
                            this.ParseODBCExecute(componentid, connectionstringid, child);
                            break;
                        default:
                            this.Core.UnexpectedElement(node, child);
                            break;
                    }
                }
            }

            // reference the DataSource custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateDatabases_Access_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateDatabases_Access_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateDatabases_Access_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "CreateDatabases_Access_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the AccessDatabase table
                Row row = Core.CreateRow(sourceLineNumbers, "AccessDatabase");
                row[0] = id;
                row[1] = componentid;
                row[2] = dbq;
                row[3] = connectionstringid;
                row[4] = attributes;
            }
        }

        enum ODBCExecuteAttributes
        {
            ExecuteOnInstall = 1,
            ExecuteOnUnInstall = 2,
            ExecuteOnReInstall = 4,
            EvaluateProperties = 8
        };

        private void ParseODBCExecute(string componentid, string connectionstringid, XmlNode node)
        {
            string id = null;
            string sql = null;
            string filename = null;
            string outputfilename = null;
            string binaryid = null;
            int attributes = 0;
            string condition = null;
            string delimiter = null;
            string type = null;
            string basepath = null;
            YesNoType evaluateproperties = YesNoType.NotSet;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Sql":
                            sql = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Filename":
                            filename = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "OutputFilename":
                            outputfilename = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "BinaryId":
                            binaryid = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "EvaluateProperties":
                            evaluateproperties = this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib);
                            break;
                        case "Delimiter":
                            delimiter = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Type":
                            type = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "BasePath":
                            basepath = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "ConnectionId":
                            if (string.IsNullOrEmpty(connectionstringid))
                            {
                                connectionstringid = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            }
                            else
                            {
                                this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            }
                            break;
                        case "ExecuteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCExecuteAttributes.ExecuteOnInstall;
                            }
                            break;
                        case "ExecuteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCExecuteAttributes.ExecuteOnUnInstall;
                            }
                            break;
                        case "ExecuteOnReInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCExecuteAttributes.ExecuteOnReInstall;
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

            // evaluate properties always defaults to yes
            if (evaluateproperties == YesNoType.Yes)
            {
                attributes |= (int)ODBCExecuteAttributes.EvaluateProperties;
            }

            // evaluate properties cannot be set except for binary content
            // the file only exists after InstallFiles and queries get automatically modularized
            if (binaryid == null && evaluateproperties != YesNoType.NotSet)
            {
                this.Core.OnMessage(WixErrors.UnexpectedElement(sourceLineNumbers, node.Name, "EvaluateProperties"));
            }

            // you can't have a combination of sql, binaryid and filename
            if (sql != null && binaryid != null) this.Core.OnMessage(WixErrors.UnexpectedElement(sourceLineNumbers, node.Name, "BinaryId"));
            if (sql != null && filename != null) this.Core.OnMessage(WixErrors.UnexpectedElement(sourceLineNumbers, node.Name, "Filename"));
            if (filename != null && binaryid != null) this.Core.OnMessage(WixErrors.UnexpectedElement(sourceLineNumbers, node.Name, "BinaryId"));

            if (null == sql && null == binaryid && null == filename)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Sql"));
            }

            if (type != null && delimiter != null)
            {
                this.Core.OnMessage(WixErrors.UnexpectedElement(sourceLineNumbers, node.Name, "Delimiter"));
            }
            
            if (null == connectionstringid)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "ConnectionId"));
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

            // reference the DataSource custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Execute_ODBC_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Execute_ODBC_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Execute_ODBC_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "Execute_ODBC_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the ODBCExecute table
                Row row = Core.CreateRow(sourceLineNumbers, "ODBCExecute");
                row[0] = id;
                row[1] = componentid;
                row[2] = connectionstringid;
                row[3] = sql;
                row[4] = filename;
                row[5] = outputfilename;
                row[6] = binaryid;
                row[7] = condition;
                row[8] = delimiter;
                row[9] = type;
                row[10] = basepath;
                row[11] = attributes;
            }
        }

        enum MSSQLDataFileAttributes
        {
            ExecuteOnInstall = 1,
            ExecuteOnUnInstall = 2,
            ExecuteOnReInstall = 4,
            EvaluateProperties = 8
        };

        private void ParseMSSQLDataFile(string componentid, string connectionstringid, string database, XmlNode node)
        {
            string id = null;
            string filename = null;
            string binaryid = null;
            string table = null;
            string schema = null;
            int attributes = 0;
            string condition = null;
            YesNoType evaluateproperties = YesNoType.NotSet;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Filename":
                            filename = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "BinaryId":
                            binaryid = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Table":
                            table = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Schema":
                            schema = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "ConnectionId":
                            if (string.IsNullOrEmpty(connectionstringid))
                            {
                                connectionstringid = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            }
                            else
                            {
                                this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            }
                            break;
                        case "Database":
                            if (string.IsNullOrEmpty(database))
                            {
                                database = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            }
                            else
                            {
                                this.Core.UnexpectedAttribute(sourceLineNumbers, attrib);
                            }
                            break;
                        case "ExecuteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MSSQLDataFileAttributes.ExecuteOnInstall;
                            }
                            break;
                        case "ExecuteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MSSQLDataFileAttributes.ExecuteOnUnInstall;
                            }
                            break;
                        case "ExecuteOnReInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)MSSQLDataFileAttributes.ExecuteOnReInstall;
                            }
                            break;
                        case "EvaluateProperties":
                            evaluateproperties = this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib);
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

            // evaluate properties always defaults to yes
            if (evaluateproperties == YesNoType.Yes)
            {
                attributes |= (int)ODBCExecuteAttributes.EvaluateProperties;
            }

            // evaluate properties cannot be set except for binary content
            // the file only exists after InstallFiles and queries get automatically modularized
            if (binaryid == null && evaluateproperties != YesNoType.NotSet)
            {
                this.Core.OnMessage(WixErrors.UnexpectedElement(sourceLineNumbers, node.Name, "EvaluateProperties"));
            }

            // you can't have a combination of binaryid and filename
            if (filename != null && binaryid != null) this.Core.OnMessage(WixErrors.UnexpectedElement(sourceLineNumbers, node.Name, "BinaryId"));

            if (null == binaryid && null == filename)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Filename"));
            }

            if (null == connectionstringid)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "ConnectionId"));
            }

            // find unexpected child elements
            foreach (XmlNode child in node.ChildNodes)
            {
                if (XmlNodeType.Element == child.NodeType)
                {
                    switch (child.LocalName)
                    {
                        case "MSSQLDataFileParameter":
                            this.ParseMSSQLDataFileParameter(id, child);
                            break;
                        default:
                            this.Core.UnsupportedExtensionElement(node, child);
                            break;
                    }
                }
                else if (XmlNodeType.CDATA == child.NodeType || XmlNodeType.Text == child.NodeType)
                {
                    condition = child.Value.Trim();
                }
            }

            // reference the DataSource custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataFile_SQLServer_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataFile_SQLServer_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataFile_SQLServer_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataFile_SQLServer_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the MSSQLDataFile table
                Row row = Core.CreateRow(sourceLineNumbers, "MSSQLDataFile");
                row[0] = id;
                row[1] = componentid;
                row[2] = connectionstringid;
                row[3] = database;
                row[4] = schema;
                row[5] = table;
                row[6] = filename;
                row[7] = binaryid;
                row[8] = condition;
                row[9] = attributes;
            }
        }

        private void ParseMSSQLDataFileParameter(string mssqldatafileid, XmlNode node)
        {
            string id = null;
            string value = null;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Value":
                            value = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
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

            if (null == value)
            {
                this.Core.OnMessage(WixErrors.ExpectedAttribute(sourceLineNumbers, node.Name, "Value"));
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
                else
                {
                    this.Core.UnsupportedExtensionElement(node, child);
                }
            }

            if (!Core.EncounteredError)
            {
                // create a row in the MSSQLDataFileParameter table
                Row row = Core.CreateRow(sourceLineNumbers, "MSSQLDataFileParameter");
                row[0] = id;
                row[1] = mssqldatafileid;
                row[2] = value;
            }
        }


        enum ODBCDataSourceAttributes
        {
            CreateOnInstall = 1,
            CreateOnUnInstall = 2,
            DeleteOnInstall = 4,
            DeleteOnUnInstall = 8
        };

        enum ODBCDataSourceType
        {
            User = 0,
            System = 1
        };

        private void ParseODBCDataSource(string componentid, XmlNode node)
        {
            string id = null;
            string driver = null;
            string name = null;
            string value = null;
            int attributes = 0;
            string condition = null;
            ODBCDataSourceType type = ODBCDataSourceType.User;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

            foreach (XmlAttribute attrib in node.Attributes)
            {
                if (0 == attrib.NamespaceURI.Length || attrib.NamespaceURI == this.schema.TargetNamespace)
                {
                    switch (attrib.LocalName)
                    {
                        case "Id":
                            id = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Driver":
                            driver = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Name":
                            name = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Value":
                            value = this.Core.GetAttributeValue(sourceLineNumbers, attrib);
                            break;
                        case "Type":
                            type = (ODBCDataSourceType) Enum.Parse(typeof(ODBCDataSourceType), 
                                this.Core.GetAttributeValue(sourceLineNumbers, attrib), true);
                            break;
                        case "CreateOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.CreateOnInstall;
                            }
                            break;
                        case "CreateOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.CreateOnUnInstall;
                            }
                            break;
                        case "DeleteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.DeleteOnInstall;
                            }
                            break;
                        case "DeleteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.DeleteOnUnInstall;
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

            // reference the DataSource custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the ODBCDataSource table
                Row row = Core.CreateRow(sourceLineNumbers, "ODBCDataSourceConfig");
                row[0] = id;
                row[1] = componentid;
                row[2] = driver;
                row[3] = name;
                row[4] = value;
                row[5] = type.ToString();
                row[6] = condition;
                row[7] = attributes;
            }
        }

        private void ParseMSSQLDataSource(string componentid, XmlNode node)
        {
            string id = null;
            string driver = "SQL Server";
            StringBuilder value = new StringBuilder();
            string name = null;
            int attributes = 0;
            string condition = null;
            ODBCDataSourceType type = ODBCDataSourceType.User;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

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
                        case "Type":
                            type = (ODBCDataSourceType)Enum.Parse(typeof(ODBCDataSourceType),
                                this.Core.GetAttributeValue(sourceLineNumbers, attrib), true);
                            break;
                        case "Network":
                        case "Server":
                        case "Address":
                        case "Database":
                        case "Description":
                            value.AppendFormat("{0}={1};", attrib.LocalName, this.Core.GetAttributeValue(sourceLineNumbers, attrib));
                            break;
                        case "TrustedConnection":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                value.Append("Trusted_Connection=yes;");
                            }
                            break;
                        case "CreateOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.CreateOnInstall;
                            }
                            break;
                        case "CreateOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.CreateOnUnInstall;
                            }
                            break;
                        case "DeleteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.DeleteOnInstall;
                            }
                            break;
                        case "DeleteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.DeleteOnUnInstall;
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

            // reference the DataSource custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the ODBCDataSource table
                Row row = Core.CreateRow(sourceLineNumbers, "ODBCDataSourceConfig");
                row[0] = id;
                row[1] = componentid;
                row[2] = driver;
                row[3] = name;
                row[4] = value.ToString();
                row[5] = type.ToString();
                row[6] = condition;
                row[7] = attributes;
            }
        }

        private void ParseAccessDataSource(string componentid, XmlNode node)
        {
            string id = null;
            string driver = "Microsoft Access Driver (*.MDB)";
            StringBuilder value = new StringBuilder();
            string name = null;
            int attributes = 0;
            string condition = null;
            ODBCDataSourceType type = ODBCDataSourceType.User;

            SourceLineNumberCollection sourceLineNumbers = Preprocessor.GetSourceLineNumbers(node);

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
                        case "Type":
                            type = (ODBCDataSourceType)Enum.Parse(typeof(ODBCDataSourceType),
                                this.Core.GetAttributeValue(sourceLineNumbers, attrib), true);
                            break;
                        case "Username":
                            value.AppendFormat("Uid={0};", this.Core.GetAttributeValue(sourceLineNumbers, attrib));
                            break;
                        case "Password":
                            value.AppendFormat("Pwd={0};", this.Core.GetAttributeValue(sourceLineNumbers, attrib));
                            break;
                        case "DBQ":
                        case "Description":
                            value.AppendFormat("{0}={1};", attrib.LocalName, this.Core.GetAttributeValue(sourceLineNumbers, attrib));
                            break;
                        case "CreateOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.CreateOnInstall;
                            }
                            break;
                        case "CreateOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.CreateOnUnInstall;
                            }
                            break;
                        case "DeleteOnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.DeleteOnInstall;
                            }
                            break;
                        case "DeleteOnUnInstall":
                            if (this.Core.GetAttributeYesNoValue(sourceLineNumbers, attrib) == YesNoType.Yes)
                            {
                                attributes |= (int)ODBCDataSourceAttributes.DeleteOnUnInstall;
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

            // reference the DataSource custom actions since nothing will happen without these
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Immediate_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Immediate_UnInstall");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Deferred_Install");
            this.Core.CreateWixSimpleReferenceRow(sourceLineNumbers, "CustomAction", "DataSource_ODBC_Deferred_UnInstall");

            if (!Core.EncounteredError)
            {
                // create a row in the ODBCDataSource table
                Row row = Core.CreateRow(sourceLineNumbers, "ODBCDataSourceConfig");
                row[0] = id;
                row[1] = componentid;
                row[2] = driver;
                row[3] = name;
                row[4] = value.ToString();
                row[5] = type.ToString();
                row[6] = condition;
                row[7] = attributes;
            }
        }
    }
}
