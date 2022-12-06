#pragma once
#include <string>
class Notifier final
{
private:
	// Constructors
	Notifier() = delete;
	Notifier(const Notifier& notifier) = delete;
public:
	// Methods
	static void emptyInput();
	
	static void bookNameNotValid(const std::string &bookName);
	static void bookNameNotFound(const std::string &bookName);
	static void noPatronsRegistered();
	static void noBooksAdded();
	static void bookIsAlreadyBorrowed(const std::string &bookName);
	static void noBooksRegistered();
	static void patronDeleteUnsuccessful();
	static void patronNameNotValid(const std::string &patronName);
	static void patronGenderNotValid(const std::string &patronGender);
	static void patronResidenceAddressNotValid(const std::string &patronResidenceAddress);
	static void patronPhoneNumberNotValid(const std::string &patronPhoneNumber);
	static void patronEmailAddressNotValid(const std::string &patronEmailAddress);
	static void patronEmailAddressNotFound(const std::string &patronEmailAddress);
	static void patronEmailAddressIsUsed(const std::string patronEmailAddress);
	static void noPatronToDeleteAtBeginning();
	static void noPatronToDeleteAtEnd();
	static void patronNotAdded();
	static void patronAtBeginningDeleted();
	static void patronAtEndDeleted();
	static void patronRegisteredSuccessfully(const std::string &patronName, const std::string &patronEmailAddress);
	static void patronFound();
	static void patronNotFound();
	static void outOfBoundsInteger();
	static void invalidInputMainMenu();
	static void patronDeletedSuccessfully();
	static void deletePatronUsingEmailAddress(const std::string &patronEmailAddress);
	
	  // tarun 
	static void bookAddedSuccessfully(const std::string &name, const std::string &ISBN);
	static void bookNotAdded();
	static void bookNotFound(const std::string & bookISBN, const std::string& copyNumber);
	static void addBookAtBeginning(const std::string &bookToAdd);
	static void bookAtBeginningDeleted();
	static void bookFound();
	static void bookNameNotFound();
	static void noBookToDeleteAtBeginning();
	static void bookAtEndDeleted();
	static void noBookToDeleteAtEnd();
	static void bookDeletedSuccessfully();
	static void bookDeletedUnSuccessfully();
};