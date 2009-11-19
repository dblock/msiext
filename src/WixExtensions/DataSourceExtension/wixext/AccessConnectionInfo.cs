using System;
using System.Collections.Generic;
using System.Text;

namespace AppSecInc.Wix.Extensions
{
    /// <summary>
    /// An Access connection info string
    /// </summary>
    public class AccessConnectionInfo
    {
        public string DBQ;
        public string Username;
        public string Password;

        public AccessConnectionInfo()
        {

        }

        /// <summary>
        /// Get the connection string
        /// </summary>
        public string ConnectionString
        {
            get
            {
                StringBuilder sb = new StringBuilder("Driver={Microsoft Access Driver (*.mdb)};");
                sb.AppendFormat("DBQ={0};", DBQ);
                if (! string.IsNullOrEmpty(Username))
                {
                    sb.AppendFormat("Uid={0};Pwd={1};", Username, Password);
                }

                return sb.ToString();
            }
        }
    }
}
