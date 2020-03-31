#include <ctime>
#include <fstream>
#include <Windows.h>
#include <tchar.h>

extern "C++" __declspec(dllexport) void create_file_hello_world()
{
	std::ofstream outfile("hello.txt");
	outfile << "Hello, world!" << std::endl;
	outfile.close();
}

extern "C++" __declspec(dllexport) void start_program()
{
	STARTUPINFO startup_info;
	PROCESS_INFORMATION process_information;
	ZeroMemory(&startup_info, sizeof startup_info);
	startup_info.cb = sizeof startup_info;
	ZeroMemory(&process_information, sizeof process_information);
	if (CreateProcess(_T("D:\\University\\SystemProgramming\\Lab1\\Lab1\\Debug\\Lab1.exe"),
		nullptr, nullptr, nullptr, FALSE,
		NULL, nullptr, nullptr, &startup_info, &process_information))
	{
		WaitForSingleObject(process_information.hProcess, INFINITE);
		CloseHandle(process_information.hProcess);
		CloseHandle(process_information.hThread);
	}
}

extern "C++" __declspec(dllexport) bool does_file_exist(const std::string directory, const std::string file_name)
{
	const auto path = directory + file_name;
	const std::ifstream input_file(path.c_str());
	return input_file.is_open();
}

extern "C++" __declspec(dllexport) BOOL edr_center_text(HDC hdc, PRECT prc, LPCWSTR p_str)
{
	SIZE size;
	const int length = wcslen(p_str);
	GetTextExtentPoint32(hdc, p_str, length, &size);
	return TextOut(hdc, (prc->right - prc->left - size.cx) / 2,
		(prc->bottom - prc->top - size.cy) / 2,
		p_str, length);
}

extern "C" __declspec(dllexport) time_t __stdcall get_time()
{
	return time(nullptr);
}