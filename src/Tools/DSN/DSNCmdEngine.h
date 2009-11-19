#pragma once

class DSNCmdEngine
{
public:
    //! command line parameters
    TCLAP::CmdLine _cmd;
	//! remove banner
	TCLAP::SwitchArg _nologo;
    //! operation to perform
    TCLAP::UnlabeledValueArg<std::wstring> _operation;
    //! DSN parameters
    TCLAP::UnlabeledMultiArg<std::wstring> _params;
    //! system vs. user DSN
    TCLAP::SwitchArg _system;
    TCLAP::SwitchArg _user;
    //! driver
    TCLAP::ValueArg<std::wstring> _driver;
public:
    DSNCmdEngine(int argc, wchar_t * argv[]);
    //! execute per command line args
    void Execute();
};
