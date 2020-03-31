#pragma once

// MFCActiveXControl1PropPage.h: объявление класса страницы свойств CMFCActiveXControl1PropPage.


// CMFCActiveXControl1PropPage: про реализацию см. MFCActiveXControl1PropPage.cpp.

class CMFCActiveXControl1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCActiveXControl1PropPage)
	DECLARE_OLECREATE_EX(CMFCActiveXControl1PropPage)

// Конструктор
public:
	CMFCActiveXControl1PropPage();

// Данные диалогового окна
	enum { IDD = IDD_PROPPAGE_MFCACTIVEXCONTROL1 };

// Реализация
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

