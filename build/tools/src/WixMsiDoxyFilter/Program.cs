using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace WixMsiDoxyFilter
{
    class Program
    {
        static void Usage()
        {
            Console.WriteLine("usage: WixMsiDoxyFilter [filename]");
        }

        static int Main(string[] args)
        {
            MsiProcessor msiProcessor = new MsiProcessor();

            try
            {
                if (args.Length != 1 || string.IsNullOrEmpty(args[0]))
                {
                    Usage();
                    throw new ArgumentException("Missing filename");
                }

                if (!File.Exists(args[0]))
                {
                    throw new FileNotFoundException(String.Format("File not found: {0}", args[0]));
                }

                msiProcessor.Open(args[0]);
                msiProcessor.Process();
                msiProcessor.Close();

                return 0;
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                return -1;
            }

        }
    }
}
