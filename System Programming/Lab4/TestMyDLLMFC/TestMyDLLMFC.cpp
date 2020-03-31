#include <windows.h>
#include <iostream>

typedef int(__stdcall* f_funci)();

int main()
{
	const auto h_proc_id = LoadLibrary(TEXT("D:\\Labs\\System Programming\\Lab4\\x64\\Debug\\MyDLLMFC.dll"));

	if (!h_proc_id) {
		std::cout << "could not load the dynamic library\n" << GetLastError() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Dll found!!!!" << std::endl;

	const auto funci =  (f_funci)(GetProcAddress(h_proc_id, "send_message_number"));
	if (!funci) {
		std::cout << "could not locate the function\n" << GetLastError() << std::endl;
		FreeLibrary(h_proc_id);
		return EXIT_FAILURE;
	}
	std::cout << "send_message_number found " << std::endl;

	const auto x = (funci)();
	std::cout << "send_message_number returned " << x << std::endl;
	FreeLibrary(h_proc_id);
	return EXIT_SUCCESS;
}