#pragma once
// MFCActiveXControl1Ctrl.h: объявление класса элемента управления ActiveX для CMFCActiveXControl1Ctrl.
// CMFCActiveXControl1Ctrl: про реализацию см. MFCActiveXControl1Ctrl.cpp.
class CMFCActiveXControl1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCActiveXControl1Ctrl)

// Конструктор
public:
	CMFCActiveXControl1Ctrl();

// Переопределение
public://согласованное управление 
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Реализация
protected:
	~CMFCActiveXControl1Ctrl();

	DECLARE_OLECREATE_EX(CMFCActiveXControl1Ctrl)    // Фабрика класса и guid
	DECLARE_OLETYPELIB(CMFCActiveXControl1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCActiveXControl1Ctrl)     // ИД страницы свойств
	DECLARE_OLECTLTYPE(CMFCActiveXControl1Ctrl)		// Введите имя и промежуточное состояние

// Схемы сообщений
	DECLARE_MESSAGE_MAP()

// Схемы подготовки к отправке
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg double TestMyMethod(double param1);

// Схемы событий
	DECLARE_EVENT_MAP()

// Подготовка к отправке и ИД событий
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