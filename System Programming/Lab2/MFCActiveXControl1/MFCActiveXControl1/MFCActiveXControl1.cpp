// MFCActiveXControl1.cpp: реализаци€ CMFCActiveXControl1App и регистраци€ DLL.

#include "stdafx.h"
#include "MFCActiveXControl1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CMFCActiveXControl1App theApp;

const GUID CDECL _tlid = { 0xE63C779A, 0x845, 0x47F5, { 0xA0, 0x7B, 0x5D, 0x5C, 0x6, 0xDB, 0xE, 0x1 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;

// CMFCActiveXControl1App::InitInstance - инициализаци€ DLL

BOOL CMFCActiveXControl1App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: ƒобавьте здесь свой код инициализации модул€.
	}

	return bInit;
}

// CMFCActiveXControl1App::ExitInstance - завершение DLL

int CMFCActiveXControl1App::ExitInstance()
{
	// TODO: ƒобавьте здесь свой код завершени€ работы модул€.

	return COleControlModule::ExitInstance();
}

// DllRegisterServer - добавл€ет записи в системный реестр

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}

// DllUnregisterServer - удал€ет записи из системного реестра

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}