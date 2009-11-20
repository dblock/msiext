using System;
using System.Collections;
using System.Collections.Specialized;
using System.Collections.Generic;
using System.Text;

using Microsoft.Deployment.WindowsInstaller;

namespace WixMsiDoxyFilter
{
    class MsiProcessor
    {
        Database _targetDb = null;

        // ID, Path view
        Dictionary<string, string> _directories = new Dictionary<string, string>();     

        //Installation Tree
        FolderNode _rootNode = null;

        // http://msdn.microsoft.com/en-us/library/aa372057.aspx
        // These folders are treated differently by msiexec
        string[] SpecialFolders =
        {
            "AdminToolsFolder",
            "AppDataFolder",
            "CommonAppDataFolder",
            "CommonFiles64Folder",
            "CommonFilesFolder",
            "DesktopFolder",
            "FavoritesFolder",
            "FontsFolder",
            "LocalAppDataFolder",
            "MyPicturesFolder",
            "PersonalFolder",
            "ProgramFiles64Folder",
            "ProgramFilesFolder",
            "ProgramMenuFolder",
            "SendToFolder",
            "StartMenuFolder",
            "StartupFolder",
            "System16Folder",
            "System64Folder",
            "SystemFolder",
            "TempFolder",
            "TemplateFolder",
            "WindowsFolder",
            "WindowsVolume"
        };

        string MakeId(string id)
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

        public void Open(string path)
        {
            _targetDb = new Database(path, DatabaseOpenMode.ReadOnly);            
        }

        public void Close()
        {
            if (_targetDb != null)
            {
                _targetDb.Close();
            }
        }

        public void Process()
        {
            if (_targetDb == null) throw new NullReferenceException("MSI database object is null. Call Open before calling Process.");

            string appName = System.IO.Path.GetFileNameWithoutExtension(_targetDb.FilePath);

            string pageId = string.Format("{0}_msi_wxs", MakeId(appName));
            Console.WriteLine(string.Format(@"/*! \page {0} {1}", pageId, appName));

            // Process Summary Information
            ProcessSummaryInformation();

            // Collect folder information
            _rootNode = new FolderNode("ROOT");
            ProcessFolderInformation("TARGETDIR");
            //_rootNode.PrintChildNodes(0);

            PopulateFiles(_rootNode, 0);
            Console.WriteLine(@"\section {0}_installation_tree Installation Tree", MakeId(appName));
            Console.WriteLine(@"\code");
            _rootNode.PrintFolderTree(0, @"   ", @"\---");
            Console.WriteLine(@"\endcode");

            Console.WriteLine(@"*/");
        }

        int _filecount = 0;
        void PopulateFiles(FolderNode node, int indent)
        {
            string tab = "  ";
            string nodelen = "";
            for (int i = 0; i < indent; i++)
            {
                nodelen = nodelen + "   ";
            }

            tab = nodelen + "  ";
            // Console.WriteLine(nodelen + "NODE: " + node.FolderName);

            foreach (string directoryId in node.IDS.Keys)
            {
                // Console.WriteLine(tab + "Directory ID: {0}", directoryId);
                List<String> files = ProcessComponentFileInformation(directoryId);
                foreach (string file in files)
                {
                    if (!String.IsNullOrEmpty(file))
                    {
                        // Console.WriteLine(tab + "   Adding File ID: {0}", file);
                        node.Files.Add(file);
                        _filecount++;
                    }
                }
            }

            foreach( FolderNode folder in node.ChildFolderNodes)
            {
                PopulateFiles(folder, indent + 1);
            }
        }
        
        List<string> ProcessComponentFileInformation(string directoryId)
        {
            List<string> files = new List<string>();

            View componentView = _targetDb.OpenView(String.Format(@"Select Component from Component where Directory_ = '{0}'", directoryId));
            componentView.Execute();

            Record componentRecord = componentView.Fetch();

            while (componentRecord != null)
            {
                View fileView = _targetDb.OpenView("Select FileName from File where File.Component_ = '{0}'", componentRecord["Component"]);
                fileView.Execute();

                Record fileRecord = fileView.Fetch();
                while (fileRecord != null)
                {
                    string fileName = fileRecord["FileName"].ToString();
                    int barLocation = fileName.IndexOf("|");

                    if (barLocation >= 0 && fileName.Length > barLocation - 1)
                    {
                        fileName = fileName.Substring(barLocation + 1);
                    }

                    files.Add(fileName);                    

                    fileRecord.Close();
                    fileRecord = fileView.Fetch();
                }

                fileView.Close();
                componentRecord.Close();
                componentRecord = componentView.Fetch();
            }

            componentView.Close();

            return files;
        }

        public void ProcessSummaryInformation()
        {
            string appName = System.IO.Path.GetFileNameWithoutExtension(_targetDb.FilePath);

            Console.WriteLine(@"\section {0} Summary Information", string.Format("{0}_msi_wxs_summaryinfo", MakeId(appName)));

            Console.WriteLine(String.Format(@"\li Subject: {0}", _targetDb.SummaryInfo.Subject));
            Console.WriteLine(String.Format(@"\li Author: {0}", _targetDb.SummaryInfo.Author));
            Console.WriteLine(String.Format(@"\li Comments: {0}", _targetDb.SummaryInfo.Comments));
            Console.WriteLine(String.Format(@"\li Title: {0}", _targetDb.SummaryInfo.Title));
            Console.WriteLine(String.Format(@"\li Character count: {0}", _targetDb.SummaryInfo.CharacterCount));
            Console.WriteLine(String.Format(@"\li Code page: {0}", _targetDb.SummaryInfo.CodePage.ToString()));            
            Console.WriteLine(String.Format(@"\li MSI created using: {0}", _targetDb.SummaryInfo.CreatingApp));
            Console.WriteLine(String.Format(@"\li Time created: {0}", _targetDb.SummaryInfo.CreateTime.ToString()));
            Console.WriteLine(String.Format(@"\li Keywords: {0}", _targetDb.SummaryInfo.Keywords));            
            Console.WriteLine(String.Format(@"\li Last Saved By: {0}", _targetDb.SummaryInfo.LastSavedBy));
            Console.WriteLine(String.Format(@"\li Last Save Time: {0}", _targetDb.SummaryInfo.LastSaveTime.ToString()));
            Console.WriteLine(String.Format(@"\li Pages: {0}", _targetDb.SummaryInfo.RevisionNumber));
            Console.WriteLine(String.Format(@"\li Minimum Windows Installer version: {0}", _targetDb.SummaryInfo.PageCount.ToString()));
            // Console.WriteLine(String.Format(@"\li Security: {0}", _targetDb.SummaryInfo.Security.ToString()));
            Console.WriteLine(String.Format(@"\li Template: {0}", _targetDb.SummaryInfo.Template));
            // Console.WriteLine(String.Format(@"\li Word Count: {0}", _targetDb.SummaryInfo.WordCount.ToString()));
            Console.WriteLine("");
        }
        
        // Read MSDN on how the directory value is stored.
        // http://msdn.microsoft.com/en-us/library/aa368295(VS.85).aspx
        // TODO: TARGETDIR???
        public string ExtractFolderName(string folderName)
        {
            // null of empty - return blank
            if (string.IsNullOrEmpty(folderName))
                return "";

            // case "."
            if (folderName.IndexOf(".") == 0 && folderName.Length == 1)
            {
                return folderName;                
            }

            // case ".:CommonFi|Common Files" OR "myizysv3|Common Files:Something" OR "logs:logs"
            if (folderName.Contains(":"))
            {
                string[] splits = folderName.Split(new char[] { ':' }, StringSplitOptions.RemoveEmptyEntries);
                
                if (splits.Length != 2)
                {
                    throw new ApplicationException(String.Format("Incorrect value {0}", folderName));
                }

                // case "."
                if (splits[0] == ".")
                    return ".";

                // case "myizysv3|Common Files"
                if (splits[0].IndexOf("|") > 0)
                {
                    return splits[0].Substring((splits[0].IndexOf("|") + 1)); 
                }
                
                // case "logs"
                return splits[0];
            }

            // case "ACTIVEX|ActiveXViewer" OR "logs"
            if (folderName.IndexOf("|") > 0)
            {
                return folderName.Substring((folderName.IndexOf("|") + 1)); 
            }
            
            // case "logs"
            return folderName;
        }

        int _iterationcount = 0;
        public void ProcessFolderInformation(string parentDirectoryId)
        {
            View directoryView = _targetDb.OpenView(String.Format("Select Directory, Directory_Parent, DefaultDir from Directory where Directory_Parent = '{0}'", parentDirectoryId));
            directoryView.Execute();

            Record directoryRecord = directoryView.Fetch();
            while (directoryRecord != null)
            {
                string directoryId = directoryRecord["Directory"].ToString();
                string directoryParent = directoryRecord["Directory_Parent"].ToString();
                string directoryName = directoryRecord["DefaultDir"].ToString();

                // Check if it is a special folder
                bool isSpecialFolder = false;

                foreach (string specialFolder in SpecialFolders)
                {
                    if ((directoryId == specialFolder) || (directoryId.IndexOf(specialFolder) == 0 && directoryId.IndexOf(".") == specialFolder.Length))
                    {
                        if (!_directories.ContainsKey(directoryId))
                        {
                            isSpecialFolder = true;
                            _directories.Add(directoryId, String.Format("[{0}]",specialFolder));                            
                            _rootNode.AddChildFolderNode(new FolderNode(String.Format("[{0}]", specialFolder), directoryId));
                            break;
                        }
                    }
                }
               
                if (!isSpecialFolder)
                {
                    string parentPath = "";

                    _directories.TryGetValue(parentDirectoryId, out parentPath);

                    string path = ExtractFolderName(directoryName);

                    if (!String.IsNullOrEmpty(parentPath))
                    {
                        if (path == ".")
                        {
                            path = parentPath;
                        }
                        else
                        {
                            path = parentPath + "\\" + path;
                        }
                    }

                    // Add to the id, path view
                    if (!_directories.ContainsKey(directoryId))
                    {
                        // Console.WriteLine("Adding: {0} \t {1}", directoryId, folderName);
                        _directories.Add(directoryId, path);
                    }

                    //Add to tree view
                    FolderNode parentOrPeerNode = null;
                    if (!String.IsNullOrEmpty(path))
                    {                                                    
                        string nodePath = System.IO.Path.GetDirectoryName(path);
                        
                        if (!String.IsNullOrEmpty(nodePath))
                        {
                            parentOrPeerNode = _rootNode.FindFolderNode(nodePath);
                        }
                        else
                        {
                            parentOrPeerNode = _rootNode.FindFolderNode(path);
                        }

                        //Get the last entry in the path string (not necessarily a file name)
                        path = System.IO.Path.GetFileName(path);
                        if (parentOrPeerNode != null)
                        {
                            parentOrPeerNode.AddChildFolderNode(new FolderNode(path, directoryId));
                        }
                        else
                        {
                            _rootNode.AddChildFolderNode(new FolderNode(path, directoryId));
                        }
                    }
                }

                _iterationcount++;
                //Console.WriteLine("-----------------------------------");
                //Console.WriteLine("ITERATION" + _iterationcount);
                //_rootNode.PrintChildNodes(0);
                //_rootNode.PrintDirectoryIds(0);
                //Console.WriteLine("-----------------------------------\n");

                ProcessFolderInformation(directoryId);

                directoryRecord.Close();
                directoryRecord = directoryView.Fetch();
            }

            directoryView.Close();
        }

    }
}
