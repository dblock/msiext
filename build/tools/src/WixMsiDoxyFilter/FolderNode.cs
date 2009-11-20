using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;

namespace WixMsiDoxyFilter
{
    public class FolderNode
    {
        // Unique folder name
        string _folderNameInPath;
        
        // All the unique _ids that poing to a path. The value can be replaced by a directory object
        Dictionary<string, string> _ids = new Dictionary<string, string>();
        
        // List of child nodes
        List<FolderNode> _childFolderNodes = new List<FolderNode>();

        // List of _files in this node
        // TODO: replace string with FileInfo object
        List<string> _files = new List<string>();

        public FolderNode(string folderName)
        {
            _folderNameInPath = folderName;
        }

        public FolderNode(string folderName, string directoryId)
        {
            _folderNameInPath = folderName;
            _ids.Add(directoryId, "");
        }

        public string FolderName
        {
            get
            {
                return _folderNameInPath;
            }
        }

        public Dictionary<string,string> IDS
        {
            get
            {
                return _ids;
            }
        }

        public List<FolderNode> ChildFolderNodes
        {
            get
            {
                return _childFolderNodes;
            }
        }

        public List<string> Files
        {
            get
            {
                return _files;
            }
        }

        // Find node given a path
        public FolderNode FindFolderNode(string path)
        {
            string[] separator = { @"\" };
            string[] folders = path.Split( separator, StringSplitOptions.RemoveEmptyEntries);
            FolderNode node = null;

            if (folders.Length > 0 )
            {
                int index = 0;
                node = FindFolderNode(new FolderNode(folders[index]));

                for (; index < folders.Length && node != null; index++)
                {
                    node = node.FindFolderNode(new FolderNode(folders[index]));
                }
            }

            return node;
        }

        public FolderNode FindFolderNode(FolderNode child)
        {
            if (_folderNameInPath == child.FolderName)
                return this;

            foreach (FolderNode node in _childFolderNodes)
            {
               FolderNode found = node.FindFolderNode(child);

               if (found != null) return found;
            }

            return null;
        }

        public void AddDirectoryId(string id)
        {
            _ids.Add(id, id);
        }

        public void AddChildFolderNode(FolderNode child)
        {
            FolderNode node = FindFolderNode(child);

            if (node != null)
            {
                foreach (string key in child.IDS.Keys)
                {
                    node._ids.Add(key, key);
                    break;
                }
            }
            else
            {
                this._childFolderNodes.Add(child);
            }
        }

        public void PrintDirectoryIds(int indent)
        {            
            string tab = "  ";
            string nodelen = "";
            for (int i = 0; i < indent; i++)
            {
                nodelen = nodelen + "   ";
            }

            tab = nodelen + "  ";
            Console.WriteLine(string.Format("{0}NODE: {1}",nodelen, FolderName));

            foreach (string key in _ids.Keys)
            {
                Console.WriteLine("{0}{1}", tab, key);
            }

            foreach (FolderNode node in _childFolderNodes)
            {
                node.PrintDirectoryIds(indent + 1);
            }
        }

        public void PrintChildNodes(int indent)
        {
            string tab = "";
            for (int i = 0; i < indent; i++)
            {
                tab = tab + "\t";
            }

            Console.WriteLine(tab + _folderNameInPath);

            foreach (FolderNode node in _childFolderNodes)
            {
                node.PrintChildNodes(indent + 1);
            }
        }

        public void PrintFolderTree(int indent, string filetab, string foldertab)
        {
            string filespace = " ";
            string folderspace = "";

            for (int i = 0; i < indent; i++)
            {
                filespace = String.Format("{0}    ", filespace);
                folderspace = String.Format("{0}    ", folderspace);
            }

            Console.WriteLine(folderspace + foldertab + _folderNameInPath);

            foreach (string file in Files)
            {
                Console.WriteLine("{0}{1}|- {2}", filespace, filetab, file);                
            }
                                    
            foreach (FolderNode node in _childFolderNodes)
            {
                node.PrintFolderTree(indent + 1, filetab, foldertab);
            }
        }
    }
}
