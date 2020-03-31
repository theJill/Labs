#pragma once
// MFCActiveXControl1Ctrl.h: ���������� ������ �������� ���������� ActiveX ��� CMFCActiveXControl1Ctrl.
// CMFCActiveXControl1Ctrl: ��� ���������� ��. MFCActiveXControl1Ctrl.cpp.
class CMFCActiveXControl1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCActiveXControl1Ctrl)

// �����������
public:
	CMFCActiveXControl1Ctrl();

// ���������������
public://������������� ���������� 
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ����������
protected:
	~CMFCActiveXControl1Ctrl();

	DECLARE_OLECREATE_EX(CMFCActiveXControl1Ctrl)    // ������� ������ � guid
	DECLARE_OLETYPELIB(CMFCActiveXControl1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCActiveXControl1Ctrl)     // �� �������� �������
	DECLARE_OLECTLTYPE(CMFCActiveXControl1Ctrl)		// ������� ��� � ������������� ���������

// ����� ���������
	DECLARE_MESSAGE_MAP()

// ����� ���������� � ��������
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg double TestMyMethod(double param1);

// ����� �������
	DECLARE_EVENT_MAP()

// ���������� � �������� � �� �������
public:
	enum {
		eventidEventHandlerTest = 1L
	};
protected:

	void EventHandlerTest(double radius)
	{
		FireEvent(eventidEventHandlerTest, EVENT_PARAM(VTS_R8), radius);
	}
};