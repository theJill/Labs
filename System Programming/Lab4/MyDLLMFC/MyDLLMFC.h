// MyDLLMFC.h : main header file for the MyDLLMFC DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyDLLMFCApp
// See MyDLLMFC.cpp for the implementation of this class
//

class CMyDLLMFCApp : public CWinApp
{
public:
	CMyDLLMFCApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
