#include "IO.h"
#include <iostream>

#if defined(_WIN32)
std::string IO::OSName = "WindowsOS";
#elif defined(macintosh) || defined(Macintosh)
std::string Notifier::OSName = "MacOS";
#endif

void IO::doNothing()
{
	std::cout << "\nPlease press any key to continue.";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getc(stdin);
}
void IO::clearScreen()
{
	if (IO::OSName == "WindowsOS")
	{
		system("cls");
	}
	else if ("Macintosh" == IO::OSName || "macintosh" == IO::OSName)
	{
		system("clear");
	}
}

void IO::clearAndIgnoreAllCharactersFromCIN()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
