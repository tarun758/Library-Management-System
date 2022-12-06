#include "Book.h"
#include <iostream>
#include <string>

// Static Proprties
uint32_t Book::totalNumberOfBooks = 0; // Keeps track of the number of Book objects created

// Constructors
Book::Book() 
	: name(std::string()), ISBN(std::string()), edition(std::string()), copyNumber(0), category(std::string()), genre(std::string()), isBorrowed(false), nextBookPointer(nullptr)
{
	totalNumberOfBooks++;
}

Book::Book(const std::string &name,
		   const std::string &ISBN,
		   const std::string &edition,
		   const uint16_t &copyNumber,
		   const std::string &category,
		   const std::string &genre)
	: name(name), ISBN(ISBN), edition(edition), copyNumber(copyNumber), category(category), genre(genre), isBorrowed(false), nextBookPointer(nullptr)
{
	totalNumberOfBooks++;
}

Book::~Book()
{
	totalNumberOfBooks--;
}

std::ostream& operator<<(std::ostream& outputStream, const Book& book)
{
	std::string isBorrowed = book.getIsBorrowed() ? "Yes" : "No";
	return outputStream 
			  << "*******************************"
		      << "\nName: "           << book.getName()
		      << "\nISBN: "           << book.getISBN()
		      << "\nEdition: "        << book.getEdition()
		      << "\nCopy Number: "    << book.getCopyNumber()
		      << "\nCategory: "       << book.getCategory()
		      << "\nGenre: "          << book.getGenre()
		      << "\nIs it borrowed: " << isBorrowed
		      << "\n*******************************\n";
}		      

// Setters
void Book::setName(const std::string &name)
{
	this->name = name;
}
void Book::setISBN(const std::string &ISBN)
{
	this->ISBN = ISBN;
}
void Book::setEdition(const std::string &edition)
{									    
	this->edition = edition;		    
}									    
void Book::setCopyNumber(const uint16_t &copyNumber)
{
	this->copyNumber = copyNumber;
}
void Book::setCategory(const std::string &category)
{
	this->category = category;
}
void Book::setGenre(const std::string &genre)
{
	this->genre = genre;
}
void Book::setIsBorrowed(const bool &isBorrowed)
{
	this->isBorrowed = isBorrowed;
}

// Getters
std::string Book::getName()	const	
{ 
	return this->name; 
}
std::string Book::getISBN() const	
{ 
	return this->ISBN; 
}
std::string Book::getEdition() const
{
	return this->edition;
}
uint16_t Book::getCopyNumber() const
{
	return this->copyNumber;
}
std::string Book::getCategory() const	
{ 
	return this->category; 
}
std::string Book::getGenre() const	
{ 
	return this->genre; 
}
bool Book::getIsBorrowed() const 
{ 
	return this->isBorrowed; 
}
int Book::getTotalNumberOfBooks()
{
	return totalNumberOfBooks;
}

// Methods
std::string Book::toString() const
{
	std::string isItBorrowed = this->isBorrowed ? "Yes" : "No";
	
	return "Name: "             + this->name + 
		   "\nISBN: "           + this->ISBN +
		   "\nCategory: "       + this->category +
		   "\nGenre: "          + this->genre + 
		   "\nIs it borrowed: " + isItBorrowed;
}

void Book::printTotalNumberOfBooks() 
{
	std::cout << "The total number of books in the library is: " << totalNumberOfBooks << std::endl;
}
