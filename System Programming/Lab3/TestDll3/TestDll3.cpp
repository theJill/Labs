#include <iostream>
#include "DLL3.h"

int main()
{
	//create_file_hello_world();
	//start_program();
	if(does_file_exist(R"(D:\University\SystemProgramming\Lab3\TestDll3\)", "hello.txt"))
	{
		std::cout << "File exists." << std::endl;
	}
	else
	{
		std::cout << "File doesn't exist." << std::endl;
	}
}