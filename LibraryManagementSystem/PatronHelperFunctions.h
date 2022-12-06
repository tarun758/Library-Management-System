#pragma once
#include "Patron.h"

class PatronHelperFunctions
{
private:
	PatronHelperFunctions() = delete;
	PatronHelperFunctions(const PatronHelperFunctions& patronHelperFunctions) = delete;
public:
	static Patron* createPatron(const std::string &creationPosition, Patron* headPointer);    // Registers a patron and adds
	static std::string getEmailAddressOfPatron();
	static std::string getNameOfPatron();
	static std::string getResidenceAddressOfPatron();
	static std::string getTelephoneNumberOfPatron();
	static bool updatePatronRecord(Patron *patronToUpdate);
};