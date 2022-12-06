#include "BookHelperFunctions.h"
#include "BooksLinkedList.h"
#include <iostream>
#include <string>
#include <array>

Book* BookHelperFunctions::createBook(const std::string &creationPosition, Book* headPointer)
{
	Book *newBook(nullptr);
	std::string bookName("");
	std::string bookISBN("");
	std::string bookEdition("");
	uint16_t	bookCopyNumber(0);
	std::string bookCategory("");
	std::string bookGenre("");

	std::cout << "You are adding a new book to the library " + creationPosition + '\n';
	std::cout << "Enter the book name: ",        std::cin >> bookName;
	std::cout << "Enter the book ISBN: ",        std::cin >> bookISBN;
	std::cout << "Enter the book edition: ",     std::cin >> bookEdition;
	std::cout << "Enter the book copy number: ", std::cin >> bookCopyNumber;
	std::cout << "Enter the book category: ",    std::cin >> bookCategory;
	std::cout << "Enter the book genere: ",      std::cin >> bookGenre;
	std::cout << '\n';
	
	if (nullptr == BooksLinkedList::searchForABook("ISBN", bookISBN, bookCopyNumber, headPointer))
	{
		newBook = new(std::nothrow)Book(bookName, bookISBN, bookEdition, bookCopyNumber, bookCategory, bookGenre);
	}
	else {
		newBook = nullptr;
	}
	return newBook;
}

bool BookHelperFunctions::updateBookDetails(Book * bookToUpdate)
{
	std::string bookName("");
	std::string bookISBN("");
	std::string bookEdition("");
	uint16_t    bookCopyNumber(0);
	std::string bookCategory("");
	std::string bookGenre("");

	std::cout << "You are now updating the details of the book.\n";
	std::cout << "Enter the book name : \n", std::cin >> bookName;
	std::cout << "Enter the ISBN of the book: \n", std::cin >> bookISBN;
	std::cout << "Enter the edition of the book: \n", std::cin >> bookEdition;
	std::cout << "Enter the book copy number: \n", std::cin >> bookCopyNumber;
	std::cout << "Enter the book category: \n", std::cin >> bookCategory;
	std::cout << "Enter the book genere: \n", std::cin >> bookGenre;
	std::cout << '\n';

	bookToUpdate->setISBN(bookISBN);
	bookToUpdate->setEdition(bookEdition);
	bookToUpdate->setName(bookName);
	bookToUpdate->setCopyNumber(bookCopyNumber);
	bookToUpdate->setCategory(bookCategory);
	bookToUpdate->setGenre(bookGenre);

	return true;
}

std::string BookHelperFunctions::getBookISBN()
{
	std::string bookISBN("");
	std::cout << "Please enter the ISBN of the book you want to search for: ";
	std::cin >> bookISBN;
	return bookISBN;
}

std::string BookHelperFunctions::getBookName()
{
	std::string bookName("");
	std::cout << "Please enter the name of the book: ";
	std::cin >> bookName;
	return bookName;
}

std::string BookHelperFunctions::getBookGenre()
{
	std::string genre("");
	std::cout << "You are now searching for books using their genre.\n";
	std::cout << "Enter 1 for Fantasy books or \n2 for Science books or \n3 for Histroical Books or \n4 for Realistic Books or \n5 Fan Books or \n6 for Narrative Books or \n7 for Biography Books or \n8 for Periodicals Books or \n9 for self-Help Books or \n10 for Reference\n: ";
	std::cin >> genre;
	if(genre == "1")
	{
		genre = "Fantasy";
	}
	else if(genre == "2")
	{
		genre= "Science";
	}
	else if(genre == "3")
	{
		genre = "Histrocial";
	}
	else if(genre == "4")
	{
		genre = "Realistic";
	}
	else if(genre== "5")
	{
		genre = "Fan";
	}
	else if(genre == "6")
	{
		genre = "Narrative";
	}
	else if(genre == "7")
	{
		genre = "Biography";
	}
	else if(genre == "8")
	{
		genre = "Periodicals";
	}
	else if(genre == "9")
	{
		genre = "Self-help";
	}
	else if(genre== "10")
	{
		genre = "Reference";
	}
	return genre;
}

std::string BookHelperFunctions::getBookCategory()
{
	std::string category("");
	std::cout << "Enter 1 for fiction books or 2 for non-fiction books: ";
	std::cin >> category;
	if (category == "1")
	{
		category = "Fiction";
	}
	else { category = "Non-Fiction"; }
	return category;
}

uint16_t BookHelperFunctions::getBookCopyNumber()
{
	uint16_t copyNumber(0);
	std::cout << "Please enter the copy number of the book: ";
	std::cin >> copyNumber;
	return copyNumber;
}

unsigned short BookHelperFunctions::findBookIndex(std::array<Book*,3> arrayToCheck)
{
	unsigned short index(0);
	for (unsigned short i(0); i < arrayToCheck.size() - 1; i++)
	{
		if (nullptr == arrayToCheck[i]) {
			index = i;
			break;
		}
	}
	return index;
}

unsigned short BookHelperFunctions::findBookHistoryIndex(std::array<Book*, 10> arrayToCheck)
{
	unsigned short index(0);
	for (unsigned short i(0); i < arrayToCheck.size() - 1; i++)
	{
		if (nullptr == arrayToCheck[i])
		{
			index = i;
			break;
		}
		else if (nullptr != arrayToCheck[i] && 9 == i) {
			arrayToCheck.fill(nullptr);
			index = 0;	// this will only happen if the patron borrowed 10 books and the array is full, then it will reset and start from 0 again
			break;
		}
	}
	return index;
}