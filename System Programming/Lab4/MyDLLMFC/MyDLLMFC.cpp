// MyDLLMFC.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "MyDLLMFC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

__declspec(dllexport) int square_int(int param);
__declspec(dllexport) int send_message_number();

int square_int(const int param)
{

	return param * param;
}

int send_message_number()
{

	return 100;
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

// CMyDLLMFCApp

BEGIN_MESSAGE_MAP(CMyDLLMFCApp, CWinApp)
END_MESSAGE_MAP()


// CMyDLLMFCApp construction

CMyDLLMFCApp::CMyDLLMFCApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMyDLLMFCApp object

CMyDLLMFCApp theApp;


// CMyDLLMFCApp initialization

BOOL CMyDLLMFCApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
