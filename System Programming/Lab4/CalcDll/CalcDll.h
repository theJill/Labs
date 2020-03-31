// CalcDll.h : main header file for the CalcDll DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCalcDllApp
// See CalcDll.cpp for the implementation of this class
//

class CCalcDllApp : public CWinApp
{
public:
	CCalcDllApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
