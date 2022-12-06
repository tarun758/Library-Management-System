#include "Notifier.h"
#include <iostream>
void Notifier::emptyInput()
{
	std::cout << "Empty input is not allowed. Please provide all the information required.\n";
}

void Notifier::patronDeleteUnsuccessful()
{
	std::cout << "The deletion process was not successful.\n";
}

void Notifier::patronNameNotValid(const std::string &patronName)
{
	std::cout << "The patron name " + patronName + " you have entered is not valid.\n";
}

void Notifier::patronGenderNotValid(const std::string &patronGender)
{
	std::cout << "The gender " + patronGender + " is not valid. Please enter either Male or Female.";
}

void Notifier::patronResidenceAddressNotValid(const std::string &patronResidenceAddress)
{
	std::cout << "The patron residence address " + patronResidenceAddress + " you have entered is not valid.\n";
}

void Notifier::patronPhoneNumberNotValid(const std::string &patronPhoneNumber)
{
	std::cout << "The patron phone number " + patronPhoneNumber + " you have entered is not valid.\n";
}

void Notifier::patronEmailAddressNotFound(const std::string &patronEmailAddress)
{
	std::cout << "The patron email address " + patronEmailAddress + " you have entered could not be found.\n";
}

void Notifier::patronEmailAddressIsUsed(const std::string patronEmailAddress)
{
	std::cout << std::string();
}

void Notifier::patronEmailAddressNotValid(const std::string &patronEmailAddress)
{
	std::cout << "The patron email address " + patronEmailAddress + " you have entered is not valid.\n";
}

void Notifier::noPatronToDeleteAtBeginning()
{
	std::cout << "There are currently no registered patrons to delete at the beginning of the list.\n";
}

void Notifier::noPatronToDeleteAtEnd()
{
	std::cout << "There are currently no registered patrons to delete at the end of the list.\n";
}

void Notifier::patronNotAdded()
{
	std::cout << "The patron is already registered or there is no enough memory to register a new patron. Please contact the IT Department to resolve the problem.\n";
}

void Notifier::patronAtBeginningDeleted()
{
	std::cout << "The patron at the beginning of the list has been deleted successfully.\n";
}

void Notifier::patronAtEndDeleted()
{
	std::cout << "The patron at the end of the list has been deleted successfully.\n";
}

void Notifier::patronRegisteredSuccessfully(const std::string &patronName, const std::string &patronEmailAddress)
{
	std::cout << "The patron " + patronName + " with the email address: " + patronEmailAddress + " has been registered successfully.\n";
}

void Notifier::patronFound()
{
	std::cout << "The patron you searched for has been successfully found.\n";
}

void Notifier::patronNotFound()
{
	std::cout << "The patron you searched for has not been found. Please make sure the entered email is valid.\n";
}

void Notifier::bookNameNotFound(const std::string &bookName)
{
	std::cout << "The book name " + bookName + " you have entered could not be found.";
}

void Notifier::noPatronsRegistered()
{
	std::cout << "\nThere are no registered patrons currently.\n";
}

void Notifier::noBooksAdded()
{
	std::cout << "\nThere are no added books currently.\n";
}


void Notifier::bookIsAlreadyBorrowed(const std::string & bookName)
{
	std::cout << std::string();
}

void Notifier::noBooksRegistered()
{
	std::cout << "There are currently no added books in the list.\n";
}

void Notifier::bookNameNotValid(const std::string &bookName)
{
	std::cout << "The book name " + bookName + " you have entered is not valid.";
}

void Notifier::outOfBoundsInteger()
{
	std::cout << "The number entered is out of bounds. Please choose from the above menu the option number you want: ";
}

void Notifier::invalidInputMainMenu()
{
	std::cout << "Invalid input. Please choose from the above menu the option number you want: ";
}

void Notifier::patronDeletedSuccessfully()
{
	std::cout << "The patron has been successfully deleted.\n";
}
void Notifier::bookAddedSuccessfully(const std::string &name, const std::string &ISBN)
{
	std::cout << "The book with name: " + name + " has been added successfully with an ISBN number of: " + ISBN + "\n";
}  
void Notifier::bookNotAdded()
{
	std::cout << "The book either already exists in the library or there is no enough memory to the new book.\nPlease contact the IT Department to resolve the problem.\n";
}

void Notifier::bookNotFound(const std::string& bookISBN, const std::string& copyNumber)
{
	std::cout << "The book with the given ISBN" << bookISBN << "and copy number" << copyNumber << " could not be found.\n";
}

void Notifier::addBookAtBeginning(const std::string &bookToAdd)
{
	std::cout << bookToAdd + " is successfully added\n";
}

void Notifier::deletePatronUsingEmailAddress(const std::string &patronEmailAddress)
{
	std::cout << patronEmailAddress + " has been deleted \n";
}

void Notifier::bookAtBeginningDeleted() // check this also 
{
	std::cout << "The book at the bginning of the list has been successfully deleted.\n";
}

void Notifier::bookFound()
{
	std::cout << "The book you searched for has been successfully found. Below are the details of the book.\n";
}
void Notifier::bookNameNotFound()
{
	std::cout << "The book you searched for has not been found. Please make sure the entered name is valid.\n";
} 


void Notifier::noBookToDeleteAtBeginning()
{
	std::cout << "There are no books to delete currently at the beginning of the list.\n";
}

void Notifier::bookAtEndDeleted()
{
	std::cout << "The book at the end of the list has been successfully deleted.\n";
}

void Notifier::noBookToDeleteAtEnd()
{
	std::cout << "The are currently no added books to be deleted from the end of list\n";
}

void Notifier::bookDeletedSuccessfully()
{
	std::cout << "The book has been deleted successfully\n";
}

void Notifier::bookDeletedUnSuccessfully()
{
	std::cout << "The book deletion is unsuccessful\n";
}



