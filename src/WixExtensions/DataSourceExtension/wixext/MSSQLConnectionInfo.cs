using System;
using System.Collections.Generic;
using System.Text;

namespace AppSecInc.Wix.Extensions
{
    public enum ODBCConnectionProtocol
    {
        Unspecified = 0,
        Tcp,
        Np,
        Rpc,
        Lpc,
        Spx,
        Vines,
        Adsp
    };

    /// <summary>
    /// An MSSQL conncetion info string
    /// </summary>
    public class MSSQLConnectionInfo
    {
        public string IpAddress;
        public int Port = 1433;
        public ODBCConnectionProtocol Protocol = ODBCConnectionProtocol.Tcp;
        public string InstanceName;
        public bool TrustedAuth = false;
        public string Username;
        public string Password;
        public string Database;
        public string AppName;
        public string NamedPipe;

        public MSSQLConnectionInfo()
        {

        }

        /// <summary>
        /// Get the connection string
        /// </summary>
        public string ConnectionString
        {
            get
            {
                StringBuilder sb = new StringBuilder();
                sb.Append("Driver={SQL Server};Server=");
                switch (Protocol)
                {
                    case ODBCConnectionProtocol.Unspecified:
                        break;
                    default:
                        sb.AppendFormat("{0}:", Protocol.ToString().ToLower());
                        break;
                }

                if (Protocol == ODBCConnectionProtocol.Np && string.IsNullOrEmpty(NamedPipe))
                {
                    sb.AppendFormat("\\\\{0}\\pipe", IpAddress);

                    if (!string.IsNullOrEmpty(InstanceName) && InstanceName != "MSSQLSERVER")
                    {
                        sb.AppendFormat("\\MSSQL${0}", InstanceName);
                    }

                    sb.Append("\\sql\\query");
                }
                else if (Protocol == ODBCConnectionProtocol.Np && !string.IsNullOrEmpty(NamedPipe))
                {
                    sb.Append(NamedPipe);
                }
                else
                {
                    sb.AppendFormat("{0},{1}", IpAddress, Port);
                }

                sb.Append(";");

                if (!string.IsNullOrEmpty(Database)) sb.AppendFormat("Database={0};", Database);
                if (!string.IsNullOrEmpty(AppName)) sb.AppendFormat("App={0};", AppName);
                if (TrustedAuth)
                {
                    sb.Append("Trusted_Connection=Yes;");
                }
                else
                {
                    sb.AppendFormat("Uid={0};Pwd={1};", Username, Password);
                }

                return sb.ToString();
            }
        }
    }
}
