#include <exception>
#include <iostream>
#include <filesystem>

import remchar;

int main()
{
	try
	{
		remove_character(L',').from_file(L"CountryCodes.txt");
		return 0;
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
}