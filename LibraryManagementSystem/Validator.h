#pragma once
#include <string>
#include <regex>
class Validator final
{
private:
	// Constructors
	Validator() = delete;
	Validator(const Validator& validator) = delete;
public:
	static const std::string VALID_NAME_PATTERN;
	static const std::string VALID_ISBN_REGEX;
	static const std::string VALID_EMAIL_ADDRESS_PATTERN;
	static const std::string VALID_PHONE_NUMBER_REGEX;
	static const std::string VALID_BOOK_NAME;

	// Methods
	static bool isEmailAddressValid(std::string &emailAddress);
	static bool isPatronNameValid(std::string &name);
	static bool isPhoneNumberValid(std::string &phoneNumber);
	static bool isBookNameValid(std::string &bookName);

	static bool isStringInteger(std::string &string);
	static uint16_t checkIntegerMaxAndMinValues(std::string &userInput, const uint16_t &min, const uint16_t &max);
	static void toUpperCase(std::string &string);
	static void toLowerCase(std::string &string);

	static bool isISBNValid(std::string &ISBN);
};
