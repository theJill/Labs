#pragma once

// MFCActiveXControl1.h: главный файл заголовка для MFCActiveXControl1.DLL

#if !defined( __AFXCTL_H__ )
#error "включить afxctl.h до включения этого файла"
#endif

#include "resource.h"       // основные символы


// CMFCActiveXControl1App: про реализацию см. MFCActiveXControl1.cpp.

class CMFCActiveXControl1App : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

