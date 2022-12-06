#include "Patron.h"
#include <iostream>
#include <stdint.h>

// Properties
const uint32_t Patron::MAX_NUMBER_OF_PATRONS = UINT32_MAX;
uint32_t Patron::totalNumberOfPatrons = 0;

// Constructor 
Patron::Patron() 
	: name(std::string()), gender(std::string()), residenceAddress(std::string()), phoneNumber(std::string()), emailAddress(std::string()), numberOfBorrowedBooks(0), nextPatronPointer(nullptr)
{
	borrowedBooks.fill(nullptr);
	borrowedBooksHistory.fill(nullptr);
	totalNumberOfPatrons++;
};
Patron::Patron(const std::string &name, 
			   const std::string &gender,
			   const std::string &residenceAddress, 
			   const std::string &phoneNumber,
			   const std::string &emailAddress) 
	: name(name), gender(gender), residenceAddress(residenceAddress), phoneNumber(phoneNumber), emailAddress(emailAddress), numberOfBorrowedBooks(0), nextPatronPointer(nullptr)
{
	borrowedBooks.fill(nullptr);
	borrowedBooksHistory.fill(nullptr);
	totalNumberOfPatrons++;
}

// Destrutor 
Patron::~Patron()
{
	totalNumberOfPatrons--;
}

// Operator Overloading
std::ostream& operator<<(std::ostream &outputStream, const Patron &patron)
{
	return outputStream                 
					<< "\n*******************************\n"
					<< "Name: "                     << patron.getName()             << '\n'
					<< "Gender: "                   << patron.getGender()           << '\n'
					<< "Residence Address: "        << patron.getResidenceAddress() << '\n'
					<< "Phone Number: "             << patron.getPhoneNumber()      << '\n'
					<< "Email Address: "            << patron.getEmailAddress()     << '\n'
					<< "Number of borrowed books: " << patron.numberOfBorrowedBooks << '\n'
					<< "\n*******************************\n";
}

// Setters 
void Patron::setName(const std::string &name)
{
	this->name = name;
}
void Patron::setGender(const std::string &gender)
{
	this->gender = gender;
}
void Patron::setResidenceAddress(const std::string &residenceAddress)
{
	this->residenceAddress = residenceAddress;
}
void Patron::setPhoneNumber(const std::string &phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
void Patron::setEmailAddress(const std::string &emailAddress)
{
	this->emailAddress = emailAddress;
}

// Getters 
std::string Patron::getName() const	
{ 
	return this->name;
}
std::string Patron::getGender() const
{
	return this->gender;
}
std::string Patron::getResidenceAddress() const
{
	return this->residenceAddress;
}
std::string Patron::getPhoneNumber() const	
{ 
	return this->phoneNumber;
}
std::string Patron::getEmailAddress() const
{
	return this->emailAddress;
}

short Patron::printBorrowedBooks() const
{
	short numberOfBooksPrinted(0);
	for (int i(0); i <= borrowedBooks.size() - 1; i++)
	{
		if (nullptr != borrowedBooks[i])
		{
			std::cout << "Book Number " << i + 1 << ":\n";
			std::cout << *borrowedBooks[i];
			numberOfBooksPrinted++;
		}
	}
	return numberOfBooksPrinted;
}
short Patron::printBorrowedBooksHistory() const {
	short numberOfBooksPrinted(0);
	for (int i(0); i <= borrowedBooksHistory.size() - 1; i++)
	{
		if (nullptr != borrowedBooksHistory[i])
		{
			std::cout << "Book Number " << i + 1 << ":\n";
			std::cout << *borrowedBooksHistory[i];
			numberOfBooksPrinted++;
		}
	}
	return numberOfBooksPrinted;
}
uint32_t Patron::getTotalNumberOfPatrons()
{
	return totalNumberOfPatrons;
}
