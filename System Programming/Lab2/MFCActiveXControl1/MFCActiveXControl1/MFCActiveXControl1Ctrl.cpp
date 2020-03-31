// MFCActiveXControl1Ctrl.cpp: реализация класса CMFCActiveXControl1Ctrl элемента ActiveX.
// regsvr32 ”<.ocx file path>”
#include "stdafx.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1Ctrl.h"
#include "MFCActiveXControl1PropPage.h"
#include "afxdialogex.h"
#define DISPID_TEST_METHOD (1025315)
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1Ctrl, COleControl)

// Схема сообщений
BEGIN_MESSAGE_MAP(CMFCActiveXControl1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// Схема подготовки к отправке
BEGIN_DISPATCH_MAP(CMFCActiveXControl1Ctrl, COleControl)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	
	
	
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "TestMyMethod", DISPID_TEST_METHOD, TestMyMethod, VT_R8, VTS_R8)
END_DISPATCH_MAP()

// Схема событий
BEGIN_EVENT_MAP(CMFCActiveXControl1Ctrl, COleControl)




	EVENT_CUSTOM_ID("EventHandlerTest", eventidEventHandlerTest, EventHandlerTest, VTS_R8)
END_EVENT_MAP()

// Страницы свойств
// TODO: при необходимости добавьте дополнительные страницы свойств.  Не забудьте увеличить значение счетчика.
BEGIN_PROPPAGEIDS(CMFCActiveXControl1Ctrl, 1)
	PROPPAGEID(CMFCActiveXControl1PropPage::guid)
END_PROPPAGEIDS(CMFCActiveXControl1Ctrl)

// Инициализировать фабрику класса и guid
IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1Ctrl, "MFCACTIVEXCONTRO.MFCActiveXControCtrl.1",
	0x863bad7d, 0x4716, 0x4e61, 0x82, 0x8e, 0xe9, 0xdd, 0x2f, 0x5d, 0xea, 0x76)

// Введите ИД и версию библиотеки
IMPLEMENT_OLETYPELIB(CMFCActiveXControl1Ctrl, _tlid, _wVerMajor, _wVerMinor)

// ИД интерфейса
const IID IID_DMFCActiveXControl1 = { 0xB91D0FDA, 0xAC52, 0x4F3B, { 0xB7, 0x7F, 0xBB, 0x24, 0x80, 0x7, 0xFA, 0xA9 } };
const IID IID_DMFCActiveXControl1Events = { 0x36E919C2, 0x6F8A, 0x4533, { 0x9C, 0x75, 0x1C, 0xEB, 0x5, 0xB6, 0xF4, 0x2E } };

// Сведения о типах элементов управления
static const DWORD _dwMFCActiveXControl1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCActiveXControl1Ctrl, IDS_MFCACTIVEXCONTROL1, _dwMFCActiveXControl1OleMisc)

// CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry -
// Добавление или удаление записей системного реестра для CMFCActiveXControl1Ctrl

BOOL CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: убедитесь, что элементы управления следуют правилам модели изолированных потоков.
	// Дополнительные сведения см. в MFC TechNote 64.
	// Если элемент управления не соответствует правилам модели изоляции, то
	// необходимо модифицировать приведенный ниже код, изменив значение 6-го параметра с
	// afxRegApartmentThreading на 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCACTIVEXCONTROL1,
			IDB_MFCACTIVEXCONTROL1,
			afxRegApartmentThreading,
			_dwMFCActiveXControl1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}

// CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl - Конструктор
CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl()
{
	InitializeIIDs(&IID_DMFCActiveXControl1, &IID_DMFCActiveXControl1Events);
	// TODO: Инициализируйте здесь данные экземпляра элемента управления.
}

// CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl - Деструктор
CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl()
{
	// TODO: Выполните здесь очистку данных экземпляра элемента управления.
}

// CMFCActiveXControl1Ctrl::OnDraw - функция рисования
void CMFCActiveXControl1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;
	// TODO: Замените следующий код собственным кодом рисования.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMFCActiveXControl1Ctrl::DoPropExchange - поддержка сохранения
void CMFCActiveXControl1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);
	// TODO: Вызывать функции PX_ для каждого постоянного настраиваемого свойства.
}

// CMFCActiveXControl1Ctrl::OnResetState - сброс элемента управления к состоянию по умолчанию
void CMFCActiveXControl1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // Сбрасывает значения по умолчанию, найденные в DoPropExchange
	// TODO: Сбросьте здесь состояние любого другого элемента управления.
}

// CMFCActiveXControl1Ctrl::AboutBox - показывает пользователю панель "О программе"
void CMFCActiveXControl1Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCACTIVEXCONTROL1);
	dlgAbout.DoModal();
}

// обработчики сообщений CMFCActiveXControl1Ctrl
double CMFCActiveXControl1Ctrl::TestMyMethod(double param1)
{
	return 3.14* pow(param1, 2);
}