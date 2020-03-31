#include <windows.h>            
#include <tchar.h>
const CLSID clsid_xl_application = { 0x00024500,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46} };
const IID   iid_application = { 0x000208D5,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46} };

int main()
{
	DISPPARAMS no_args = { nullptr, nullptr,0,0 };
	IDispatch* p_xl_app = nullptr;
	DISPPARAMS disp_params;
	VARIANT call_args[1];
	VARIANT v_result;
	DISPID dispid;
	HRESULT hr;

	CoInitialize(nullptr);
	hr = CoCreateInstance(clsid_xl_application, nullptr, CLSCTX_LOCAL_SERVER, iid_application, reinterpret_cast<void**>(&p_xl_app));
	if (SUCCEEDED(hr))
	{
		auto sz_visible = (OLECHAR*)L"Visible";
		hr = p_xl_app->GetIDsOfNames(IID_NULL, &sz_visible, 1, GetUserDefaultLCID(), &dispid);
		if (SUCCEEDED(hr))
		{
			VariantInit(&call_args[0]);
			call_args[0].vt = VT_BOOL;
			call_args[0].boolVal = TRUE;
			DISPID dispid_named = DISPID_PROPERTYPUT;
			disp_params.rgvarg = call_args;
			disp_params.rgdispidNamedArgs = &dispid_named;
			disp_params.cArgs = 1;
			disp_params.cNamedArgs = 1;
			VariantInit(&v_result);
			hr = p_xl_app->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUT, &disp_params, &v_result, nullptr, nullptr);
			auto sz_workbooks = (OLECHAR*)L"Workbooks";
			hr = p_xl_app->GetIDsOfNames(IID_NULL, &sz_workbooks, 1, GetUserDefaultLCID(), &dispid);
			if (SUCCEEDED(hr))
			{
				IDispatch* p_xl_books = nullptr;
				VariantInit(&v_result);
				hr = p_xl_app->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &no_args, &v_result, nullptr, nullptr);
				if (SUCCEEDED(hr))
				{
					p_xl_books = v_result.pdispVal;
					IDispatch* p_xl_book = nullptr;
					auto sz_add = (OLECHAR*)L"Add";
					hr = p_xl_books->GetIDsOfNames(IID_NULL, &sz_add, 1, GetUserDefaultLCID(), &dispid);
					if (SUCCEEDED(hr))
					{
						VariantInit(&v_result);
						hr = p_xl_books->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD | DISPATCH_PROPERTYGET, &no_args, &v_result, nullptr, nullptr);
						if (SUCCEEDED(hr))
						{
							p_xl_book = v_result.pdispVal;
							auto sz_active_sheet = (OLECHAR*)L"ActiveSheet";
							hr = p_xl_app->GetIDsOfNames(IID_NULL, &sz_active_sheet, 1, GetUserDefaultLCID(), &dispid);
							if (SUCCEEDED(hr))
							{
								IDispatch* p_xl_sheet = nullptr;
								VariantInit(&v_result);
								hr = p_xl_app->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &no_args, &v_result, nullptr, nullptr);
								if (SUCCEEDED(hr))
								{
									p_xl_sheet = v_result.pdispVal;
									auto sz_range = (OLECHAR*)L"Range";
									hr = p_xl_sheet->GetIDsOfNames(IID_NULL, &sz_range, 1, GetUserDefaultLCID(), &dispid);
									if (SUCCEEDED(hr))
									{
										IDispatch* p_xl_range = nullptr;
										VariantInit(&v_result);
										call_args[0].vt = VT_BSTR,
											call_args[0].bstrVal = SysAllocString(L"A1");
										disp_params.rgvarg = call_args;
										disp_params.rgdispidNamedArgs = nullptr;
										disp_params.cArgs = 1;
										disp_params.cNamedArgs = 0;
										hr = p_xl_sheet->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET, &disp_params, &v_result, nullptr, nullptr);
										if (SUCCEEDED(hr))
										{
											p_xl_range = v_result.pdispVal;
											auto sz_value = (OLECHAR*)L"Value";
											hr = p_xl_range->GetIDsOfNames(IID_NULL, &sz_value, 1, GetUserDefaultLCID(), &dispid);
											if (SUCCEEDED(hr))
											{
												VariantClear(&call_args[0]);
												call_args[0].vt = VT_BSTR;
												call_args[0].bstrVal = SysAllocString(L"Hello, World!");
												disp_params.rgvarg = call_args;
												disp_params.rgdispidNamedArgs = &dispid_named;
												disp_params.cArgs = 1;
												disp_params.cNamedArgs = 1;
												hr = p_xl_range->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUT, &disp_params, nullptr, nullptr, nullptr);
												p_xl_range->Release();
											}
										}
									}
									p_xl_sheet->Release();
								}
							}
							p_xl_book->Release();
						}
					}
					p_xl_books->Release();
				}
			}
			system("pause");
		}
		VariantInit(&v_result);
		hr = p_xl_app->Invoke(0x0000012e, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &no_args, &v_result, nullptr, nullptr);
		p_xl_app->Release();
	}
	CoUninitialize();

	return 0;
}
