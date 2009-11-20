using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace SlnDependencyReorder
{
    class Program
    {
        static int Main(string[] args)
        {
            try
            {
                if (args.Length < 1)
                {
                    Console.WriteLine("syntax: SlnDependencyReorder.exe [Project.sln]");
                    return -1;
                }

                StreamReader slnreader = File.OpenText(args[0]);
                List<string> dependencies = null;
                while (!slnreader.EndOfStream)
                {
                    string line = slnreader.ReadLine();
                    if (line.Trim() == "ProjectSection(ProjectDependencies) = postProject")
                    {
                        Console.WriteLine(line);
                        dependencies = new List<string>();
                    }
                    else if (line.Trim() == "EndProjectSection" && dependencies != null)
                    {
                        foreach (string dependency in dependencies)
                        {
                            Console.WriteLine(dependency);
                        }
                        Console.WriteLine(line);
                        dependencies = null;
                    }
                    else if (dependencies != null)
                    {
                        dependencies.Insert(0, line);
                    }
                    else
                    {
                        Console.WriteLine(line);
                    }
                }

                return 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: {0}", ex.Message);
                return -1;
            }
        }
    }
}
