#pragma once

#include <Ntsecapi.h>
#include <Sddl.h>
#include <Tlhelp32.h>
#include <LmAccess.h>
#include <LmErr.h>
#define SECURITY_WIN32
#include <security.h>

#include "Sid.h"
#include "Account.h"
#include "LocalGroup.h"
#include "Privilege.h"
#include "LoggedOnUser.h"
#include "ImpersonatedUser.h"
#include "LSAPolicy.h"
#include "LSAUnicodeString.h"
#include "Process.h"
#include "ProcessToken.h"
