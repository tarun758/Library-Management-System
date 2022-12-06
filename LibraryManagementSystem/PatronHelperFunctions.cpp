#include "PatronHelperFunctions.h"
#include "PatronsLinkedList.h"
#include <string>
#include <iostream>

Patron* PatronHelperFunctions::createPatron(const std::string &creationPosition, Patron* headPointer)
{
	Patron *newPatron(nullptr);						// create the Patron node
	std::string patronName("");
	std::string patronGenderString("");
	std::string patronResidenceAddress("");
	std::string patronPhoneNumber("");
	std::string patronEmailAddress("");

	std::cout << "You are now registering a new patron in the list " + creationPosition + '\n';
	std::cout << "Enter the name of the patron: ", std::cin >> patronName;					
	std::cout << "Is the patron a male or a female: ", std::cin >> patronGenderString;				
	std::cout << "Enter the residence address of the patron: ", std::cin >> patronResidenceAddress;	
	std::cout << "Enter the phone number of the patron: ", std::cin >> patronPhoneNumber;			
	std::cout << "Enter the email address of the patron: ", std::cin >> patronEmailAddress;			
	std::cout << '\n';

	if (nullptr == PatronsLinkedList::searchForAPatron(patronEmailAddress, headPointer)) {
		newPatron = new (std::nothrow) Patron(patronName, patronGenderString, patronResidenceAddress, patronPhoneNumber, patronEmailAddress);
	}
	else {
		newPatron = nullptr;
	}
	return newPatron;
}

std::string PatronHelperFunctions::getEmailAddressOfPatron()
{
	std::string patronEmailAddress("");
	std::cout << "Please enter the email address of the patron: ";
	std::cin  >> patronEmailAddress;
	return patronEmailAddress;
}

std::string PatronHelperFunctions::getNameOfPatron()
{
	std::string patronName("");
	std::cout << "Please enter the name of the patron you are searching for: ";
	std::cin >> patronName;
	return patronName;
}

std::string PatronHelperFunctions::getResidenceAddressOfPatron()
{
	std::string patronResidenceAddress("");
	std::cout << "Please enter the residence address of the patron you are searching for: ";
	std::cin >> patronResidenceAddress;
	return patronResidenceAddress;
}

std::string PatronHelperFunctions::getTelephoneNumberOfPatron()
{
	std::string patronTelephoneNumber("");
	std::cout << "Please enter the telephone number of the patron you are searching for: ";
	std::cin >> patronTelephoneNumber;
	return patronTelephoneNumber;
}

bool PatronHelperFunctions::updatePatronRecord(Patron * patronToUpdate)
{
	std::string patronName("");
	std::string patronGenderString("");
	std::string patronResidenceAddress("");
	std::string patronTelephoneNumber("");

	std::cout << "You are now updating the details of the patron.\n";
	std::cout << "Enter the name of the patron: ", std::cin >> patronName;	
	std::cout << "Is the patron a male or a female: ", std::cin >> patronGenderString;				
	std::cout << "Enter the residence address of the patron: ", std::cin >> patronResidenceAddress;	
	std::cout << "Enter the phone number of the patron: ", std::cin >> patronTelephoneNumber;		
	std::cout << '\n';

	patronToUpdate->setName(patronName);
	patronToUpdate->setGender(patronGenderString);
	patronToUpdate->setResidenceAddress(patronResidenceAddress);
	patronToUpdate->setPhoneNumber(patronTelephoneNumber);

	return true;
}

