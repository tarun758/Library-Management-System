#include "Validator.h"
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <string>
#include "IO.h"
#include "Notifier.h"

bool Validator::isStringInteger(std::string &string)
{
	return string.find_first_not_of("0123456789") == std::string::npos;
}

uint16_t Validator::checkIntegerMaxAndMinValues(std::string &userInput, const uint16_t  &min, const uint16_t &max)
{
	while (true)
	{
		std::cin >> userInput;
		if (Validator::isStringInteger(userInput))
		{
			try
			{
				uint16_t returnVal = std::stoi(userInput);
				if (returnVal >= min && returnVal <= max)
				{
					IO::clearScreen();
					return returnVal;
				}
				else
				{
					std::cout << "Invalid input. Please choose from the above menu the option number you want: ";
				}
			}
			catch (const std::exception&)
			{
				Notifier::outOfBoundsInteger();
			}
		}
		else
		{
			Notifier::invalidInputMainMenu();
			IO::clearAndIgnoreAllCharactersFromCIN();
		}
	}
}

bool Validator::isISBNValid(std::string& ISBN)
{
	int count(0), sum(0);
	for (auto chr : ISBN)
	{
		if (chr == ' ' || chr == '-') {
			continue;
		}
		if (chr < '0' || chr > '9') {
			return false;
		}
		if (count & 1) {
			sum += 3 * (chr - '0');
		}
		else {
			sum += chr - '0';
		}
		count++;
	}
	if (13 != count) {
		return false;
	}
	return sum % 10 == 0;
}
