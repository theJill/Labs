#include "windows.h"
#include <iostream>

typedef int(_cdecl* f_sum)(int num1, int num2);
typedef int(_cdecl* f_multiply)(int num1, int num2);
typedef double(_cdecl* f_divide)(int num1, int num2);

int main()
{
	const auto h_proc_id = LoadLibrary(TEXT("D:\\Labs\\System Programming\\Lab4\\x64\\Debug\\CalcDll.dll"));

	if (!h_proc_id) {
		std::cout << "Could not load the dynamic library\n" << GetLastError() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Dll found!!!!" << std::endl;

	const auto sum = reinterpret_cast<f_sum>(GetProcAddress(h_proc_id, "sum"));
	const auto multiply = reinterpret_cast<f_multiply>(GetProcAddress(h_proc_id, "multiply"));
	const auto divide = reinterpret_cast<f_divide>(GetProcAddress(h_proc_id, "divide"));
	if (!sum || !multiply || !divide) {
		std::cout << "Could not locate the functions\n" << GetLastError() << std::endl;
		FreeLibrary(h_proc_id);
		return EXIT_FAILURE;
	}
	std::cout << "Functions found." << std::endl;

	const auto sum_result = sum(1, 1);
	const auto multiply_result = multiply(2, 2);
	const auto divide_result = divide(5, 2);
	std::cout << "1+1=" << sum_result << std::endl << "2*2=" << multiply_result << std::endl
		<< "5/2=" << divide_result << std::endl;
	FreeLibrary(h_proc_id);
	return EXIT_SUCCESS;
}