using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using System.Xml.Schema;
using System.Collections;
using System.IO;
using System.Text.RegularExpressions;

namespace WixExtXsdDoxyFilter
{
    class Program
    {
        static void Usage()
        {
            Console.WriteLine("usage: WixExtXsdDoxyFilter [filename]");
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

                XmlSchema schema = XmlSchema.Read(new XmlTextReader(args[0]), null);
                string _namespace = string.Format("Wix.Extensions.{0}", Path.GetFileNameWithoutExtension(args[0]));
                Console.WriteLine(ProcessNamespace(_namespace, schema));
                return 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return -1;
            }
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

        private static string ProcessNamespace(string name, XmlSchema schema)
        {
            StringBuilder result = new StringBuilder();
            for (int i = schema.Items.Count - 1; i >= 0; i--)
            {
                XmlSchemaObject schemaObject = schema.Items[i];
                if (schemaObject is XmlSchemaAnnotation)
                {
                    result.AppendLine("/*!");
                    result.Append(ProcessAnnotation((XmlSchemaAnnotation)schemaObject));
                    result.AppendLine("*/");
                    schema.Items.RemoveAt(i);
                }
                else if (schemaObject is XmlSchemaSimpleType)
                {
                    schema.Items.RemoveAt(i);
                }
            }

            result.AppendLine(string.Format("namespace {0} {{", name));
            result.Append(Process(schema.Items));
            result.AppendLine("}");

            return result.ToString();
        }

        private static string Process(XmlSchemaObjectCollection collection)
        {
            StringBuilder result = new StringBuilder();
            foreach (XmlSchemaObject schemaObject in collection)
            {
                if (schemaObject is XmlSchemaDocumentation)
                    result.Append(ProcessDocumentation((XmlSchemaDocumentation)schemaObject));
                else if (schemaObject is XmlSchemaElement)
                    result.Append(ProcessElement((XmlSchemaElement)schemaObject));
                else if (schemaObject is XmlSchemaAnnotation)
                    result.Append(ProcessAnnotation((XmlSchemaAnnotation)schemaObject));
                else if (schemaObject is XmlSchemaAttribute)
                    result.Append(ProcessAttribute((XmlSchemaAttribute)schemaObject));
                else if (schemaObject is XmlSchemaSimpleType)
                    result.Append(ProcessSchemaSimpleType((XmlSchemaSimpleType)schemaObject));
                else
                    result.AppendLine(string.Format("Unsupported type: {0}", schemaObject));
            }
            return result.ToString();
        }

        private static string ProcessAttribute(XmlSchemaAttribute schemaAttribute)
        {
            StringBuilder result = new StringBuilder();

            if (schemaAttribute == null)
                return result.ToString();

            result.AppendLine("/*!");
            result.Append(ProcessAnnotation(schemaAttribute.Annotation));
            result.Append(ProcessSchemaType(schemaAttribute.SchemaType));
            result.AppendLine("*/");
            string name = schemaAttribute.SchemaTypeName.Name;

            if (string.IsNullOrEmpty(name)) name = "complextype";
            result.AppendLine(string.Format("{0} {1};", name, schemaAttribute.Name));

            return result.ToString();
        }

        private static string ProcessAppInfo(XmlSchemaAppInfo schemaAppInfo)
        {
            StringBuilder result = new StringBuilder();

            if (schemaAppInfo == null)
                return result.ToString();

            if (! string.IsNullOrEmpty(schemaAppInfo.Source))
            {
                result.AppendLine(schemaAppInfo.Source.Trim());
            }

            List<string> parentRefs = new List<string>(); // list of parents under which this type can be nested

            foreach (XmlNode node in schemaAppInfo.Markup)
            {
                switch (node.Name)
                {
                    case "xse:parent":
                        parentRefs.Add(node.Attributes["ref"].Value);
                        break;
                    default:
                        result.AppendLine(string.Format("Unsupported appinfo node: {0}", node.Name));
                        break;
                }
            }

            if (parentRefs.Count > 0)
            {
                result.AppendLine(string.Format("May be nested under \\b {0}.", string.Join(", \\b ", parentRefs.ToArray())));
            }

            return result.ToString();
        }

        private static string ProcessDocumentation(XmlSchemaDocumentation schemaDocumentation)
        {
            StringBuilder result = new StringBuilder();

            if (schemaDocumentation == null)
                return result.ToString();

            foreach(XmlNode node in schemaDocumentation.Markup)
            {
                result.AppendLine(node.InnerText.Trim());
            }

            return result.ToString();
        }

        private static string ProcessElement(XmlSchemaElement schemaElement)
        {
            StringBuilder result = new StringBuilder();
            if (schemaElement == null)
                return result.ToString();

            result.AppendLine("/*!");
            result.AppendLine(ProcessAnnotation(schemaElement.Annotation));
            if (schemaElement.SchemaType != null)
            {
                result.AppendLine(ProcessAnnotation(schemaElement.SchemaType.Annotation));
                schemaElement.SchemaType.Annotation = null;
            }
            result.AppendLine("*/");            

            result.AppendLine(string.Format("class {0} {{", schemaElement.Name));
            result.AppendLine("public:");
            result.Append(Process(schemaElement.Constraints));
            result.Append(ProcessSchemaType(schemaElement.SchemaType));
            result.AppendLine("};");

            return result.ToString();
        }

        private static string ProcessSchemaType(XmlSchemaType schemaType)
        {
            StringBuilder result = new StringBuilder();
            if (schemaType == null)
                return result.ToString();

            result.Append(ProcessAnnotation(schemaType.Annotation));

            if (schemaType is XmlSchemaComplexType)
                result.Append(ProcessSchemaComplexType((XmlSchemaComplexType) schemaType));
            else if (schemaType is XmlSchemaSimpleType)
                result.Append(ProcessSchemaSimpleType((XmlSchemaSimpleType) schemaType));
            else
                result.AppendLine(string.Format("Unsupported schema type: {0}", schemaType));

            return result.ToString();
        }

        private static string ProcessSchemaComplexType(XmlSchemaComplexType schemaType)
        {
            StringBuilder result = new StringBuilder();
            if (schemaType == null)
                return result.ToString();

            if (schemaType.ContentModel != null)
            {
                if (schemaType.ContentModel is XmlSchemaSimpleContent)
                    result.Append(ProcessSchemaSimpleContent((XmlSchemaSimpleContent)schemaType.ContentModel));
                else
                    result.AppendLine(string.Format("Unsupported content model: {0}", schemaType.ContentModel));
            }

            result.Append(Process(schemaType.Attributes));
            return result.ToString();
        }

        private static string ProcessSchemaSimpleContent(XmlSchemaSimpleContent schemaContent)
        {
            StringBuilder result = new StringBuilder();
            result.Append(ProcessAnnotation(schemaContent.Annotation));

            if (schemaContent.Content is XmlSchemaSimpleContentExtension)
                result.Append(ProcessSchemaSimpleContentExtension((XmlSchemaSimpleContentExtension)schemaContent.Content));
            else
                result.AppendLine(string.Format("Unsupport content extension: {0}", schemaContent.Content));
            return result.ToString();
        }

        private static string ProcessSchemaSimpleContentExtension(XmlSchemaSimpleContentExtension schemaContentExtension)
        {
            StringBuilder result = new StringBuilder();
            //if (schemaContentExtension.Annotation != null)
            //{
            //    result.AppendLine("May have nested data.");
            //    result.Append(ProcessAnnotation(schemaContentExtension.Annotation));
            //}
            result.Append(Process(schemaContentExtension.Attributes));
            return result.ToString();
        }

        private static string ProcessSchemaSimpleType(XmlSchemaSimpleType schemaType)
        {
            StringBuilder result = new StringBuilder();
            if (schemaType == null)
                return result.ToString();

            if (schemaType.Content is XmlSchemaSimpleTypeRestriction)
                result.Append(ProcessSchemaSimpleTypeRestriction((XmlSchemaSimpleTypeRestriction)schemaType.Content));
            else
                result.AppendLine(string.Format("Unsupported schema content type: {0}", schemaType.Content));
            return result.ToString();
        }

        private static string ProcessSchemaSimpleTypeRestriction(XmlSchemaSimpleTypeRestriction schemaRestriction)
        {
            StringBuilder result = new StringBuilder();
            result.Append(ProcessAnnotation(schemaRestriction.Annotation));
            List<string> tokens = new List<string>();
            foreach (XmlSchemaObject facet in schemaRestriction.Facets)
            {
                if (facet is XmlSchemaEnumerationFacet)
                    tokens.Add(((XmlSchemaEnumerationFacet)facet).Value);
                else
                    result.AppendLine(string.Format("Unsupported facet type: {0}", facet));
            }

            if (tokens.Count > 0)
            {
                result.AppendLine(string.Format("One of \\b {0}.", string.Join(", \\b ", tokens.ToArray())));
            }
            return result.ToString();
        }

        private static string ProcessAnnotation(XmlSchemaAnnotation schemaAnnotation)
        {
            StringBuilder result = new StringBuilder();
            if (schemaAnnotation == null)
                return result.ToString();

            foreach (XmlSchemaObject schemaObject in schemaAnnotation.Items)
            {
                if (schemaObject is XmlSchemaAppInfo)
                    result.Append(ProcessAppInfo((XmlSchemaAppInfo)schemaObject));
                else if (schemaObject is XmlSchemaDocumentation)
                    result.Append(ProcessDocumentation((XmlSchemaDocumentation)schemaObject));
                else
                    result.AppendLine(string.Format("Unsupported annotation type: {0}", schemaObject));
            }

            return result.ToString();
        }
    }
}
