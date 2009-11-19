namespace AppSecInc.Wix.Extensions
{
    using System;
    using System.Reflection;
    using Microsoft.Tools.WindowsInstallerXml;

    /// <summary>
    /// Provides a set of common dialogs used in AppSecInc installers.
    /// </summary>
    public sealed class CommonUiExtension : WixExtension
    {
        private Library library;

        /// <summary>
        /// Gets the library associated with this extension.
        /// </summary>
        /// <param name="tableDefinitions">The table definitions to use while loading the library.</param>
        /// <returns>The library for this extension.</returns>
        public override Library GetLibrary(TableDefinitionCollection tableDefinitions)
        {
            if (null == this.library)
            {
                this.library = LoadLibraryHelper(Assembly.GetExecutingAssembly(), "AppSecInc.Wix.Extensions.Data.CommonUi.wixlib", tableDefinitions);
            }

            return this.library;
        }

        /// <summary>
        /// Gets the default culture.
        /// </summary>
        /// <value>The default culture.</value>
        public override string DefaultCulture
        {
            get { return "en-us"; }
        }
    }
}
