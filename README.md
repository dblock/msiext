Community MSI Extensions
========================

![msiext](https://github.com/dblock/msiext/raw/master/msiext.gif)

We take our custom actions seriously.

AppSecInc. Community MSI Extensions is a collection of MSI custom actions and WIX extensions that extend Windows installer, originally developped by [Application Security Inc.](http://www.appsecinc.com) for a large Enterprise product, and open-sourced in 2009. The project grew and continues growing incrementally implementing everything that wix didn't have out of the box. All custom actions and extensions are fully unit-tested.

Essentials
----------

* [Download v1.5](https://github.com/dblock/msiext/releases/download/1.5/msiext-1.5.zip)
* [v1.5 Documentation](http://dblock.github.com/msiext/docs/1.5/)
* [Lots of MSI Demos](src/Demos)
* [Need Help? Google Group](https://groups.google.com/group/msiext)
* [Old CodePlex Site](http://msiext.codeplex.com)

Features
--------

### Wix Extensions

* System Tools: deals with copying, moving, deleting files out of sequence, compare versions, execute commands, process template files, copy registry keys, etc.
* Java Tools: deals with jar and unjar.
* Data Sources: deals with generic ODBC and specific MSAccess and MSSQL databases, SQL files, etc. See [this post](http://code.dblock.org/ShowPost.aspx?id=100) for a primer.
* User Privileges: deals with local users and groups.
* Common UI Wix Extension: dialogs for installing Windows services and databases with credentials.

### Immediate Custom Actions

* Manipulating files, folders, registry, services.
* String template and regex processing.
* Active Directory functions.
* ODBC and DMO functions.
* Local users, groups, security and privileges.
* Encryption, decryption, signing.
* Xml file manipulation.
* TcpIp functions.

### Additional Features

* Supports impersonation in all custom actions.

License and Copyright
---------------------

Copyright (c) Application Security Inc. and Contributors.
This project is licensed under the [Eclipse Public License](https://github.com/dblock/msiext/blob/master/LICENSE).
