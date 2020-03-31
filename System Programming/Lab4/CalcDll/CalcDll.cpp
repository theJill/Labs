// CalcDll.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "CalcDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

__declspec(dllexport) int sum(int num1, int num2);
__declspec(dllexport) int multiply(int num1, int num2);
__declspec(dllexport) double divide(int num1, int num2);

int sum(const int num1, const int num2)
{
	return num1 + num2;
}

int multiply(const int num1, const int num2)
{
	return num1 * num2;
}

double divide(const int num1, const int num2)
{
	return static_cast<double>(num1) / num2;
}

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CCalcDllApp

BEGIN_MESSAGE_MAP(CCalcDllApp, CWinApp)
END_MESSAGE_MAP()


// CCalcDllApp construction

CCalcDllApp::CCalcDllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CCalcDllApp object

CCalcDllApp theApp;


// CCalcDllApp initialization

BOOL CCalcDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
