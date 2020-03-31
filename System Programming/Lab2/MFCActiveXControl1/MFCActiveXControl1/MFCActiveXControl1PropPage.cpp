// MFCActiveXControl1PropPage.cpp: реализация класса страницы свойств CMFCActiveXControl1PropPage.

#include "stdafx.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1PropPage, COlePropertyPage)

// Схема сообщений

BEGIN_MESSAGE_MAP(CMFCActiveXControl1PropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Инициализировать фабрика класса и guid

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1PropPage, "MFCACTIVEXCONT.MFCActiveXContPropPage.1",
	0x3183591, 0x6434, 0x4e92, 0xb8, 0x5a, 0xda, 0x44, 0xab, 0x88, 0xd5, 0x84)

// CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPageFactory::UpdateRegistry -
// Добавление или удаление записей системного реестра для CMFCActiveXControl1PropPage

BOOL CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCACTIVEXCONTROL1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPage - Конструктор

CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPage() :
	COlePropertyPage(IDD, IDS_MFCACTIVEXCONTROL1_PPG_CAPTION)
{
}

// CMFCActiveXControl1PropPage::DoDataExchange - перенос данных между страницей и свойствами

void CMFCActiveXControl1PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// обработчики сообщений CMFCActiveXControl1PropPage
