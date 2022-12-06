#pragma once
#include <string>
class IO
{
private:
	IO() = delete;
	IO(const IO &IO) = delete;
public:
	// Properties
	static std::string OSName;
	static void doNothing();
	static void clearScreen();
	static void clearAndIgnoreAllCharactersFromCIN();
};

