#pragma once

// MFCActiveXControl1PropPage.h: ���������� ������ �������� ������� CMFCActiveXControl1PropPage.


// CMFCActiveXControl1PropPage: ��� ���������� ��. MFCActiveXControl1PropPage.cpp.

class CMFCActiveXControl1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCActiveXControl1PropPage)
	DECLARE_OLECREATE_EX(CMFCActiveXControl1PropPage)

// �����������
public:
	CMFCActiveXControl1PropPage();

// ������ ����������� ����
	enum { IDD = IDD_PROPPAGE_MFCACTIVEXCONTROL1 };

// ����������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����� ���������
protected:
	DECLARE_MESSAGE_MAP()
};

