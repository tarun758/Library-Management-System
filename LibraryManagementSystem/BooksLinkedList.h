#pragma once
#include "Book.h"
class BooksLinkedList
{
private:
	Book* headPointer;
	size_t totalNumberOfBooks;

public:
	BooksLinkedList();
	~BooksLinkedList();
	friend class OperateDBKLLMS;
	friend class BookHelperFunctions;

	// Methods
	void addBookSortedAlphabetically(Book* bookToAdd);
	void addBookAtBeginning(Book* bookToAdd);
	void addBookAtEnd(Book* bookToAdd);
	bool deleteBookUsingISBN(const std::string &ISBN, const uint16_t &copyNumber);
	bool deleteBookAtBeginning();
	bool deleteBookAtEnd();
	void printBooksDetails(const std::string &criterion, const std::string &value = "") const;
	static bool doesBookISBNExist(const std::string &bookISBN, Book *headPointer);
	static Book *searchForABook(const std::string &criterion, const std::string &value, const uint16_t &copyNumber, Book *headPointer);
	bool isHeadEmpty(Book *headPointer) const;

};

