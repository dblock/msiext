#pragma once
#include <Global.h>
#include <Version/Version.h>
#include <Exception/Exception.h>
#include <String/StringUtils.h>
#include <AtlCom/CoInitialize.h>
#include <shlobj.h>
#include <File/File.h>
#include <Xml/Xml.h>
#include <ODBC/ODBC.h>

#ifdef min
#undef min // tclap uses std::min which complains in tclap/cmdline.h
#endif

#include <tclap/cmdline.h>
