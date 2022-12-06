#pragma once
#include "Book.h"
class BookHelperFunctions
{
public:

	static Book* createBook(const std::string &creationPosition, Book* headPointer);
	static std::string getBookISBN();
	static std::string getBookName();
	static std::string getBookGenre();
	static std::string getBookCategory();
	static bool updateBookDetails(Book *bookToUpdate);
	static unsigned short findBookIndex(std::array<Book*, 3> arrayToCheck);
	static unsigned short findBookHistoryIndex(std::array<Book*, 10> arrayToChec);
	static uint16_t getBookCopyNumber();


private:

};

