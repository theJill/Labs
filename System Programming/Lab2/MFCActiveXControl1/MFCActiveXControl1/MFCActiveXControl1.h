#pragma once

// MFCActiveXControl1.h: ������� ���� ��������� ��� MFCActiveXControl1.DLL

#if !defined( __AFXCTL_H__ )
#error "�������� afxctl.h �� ��������� ����� �����"
#endif

#include "resource.h"       // �������� �������


// CMFCActiveXControl1App: ��� ���������� ��. MFCActiveXControl1.cpp.

class CMFCActiveXControl1App : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

