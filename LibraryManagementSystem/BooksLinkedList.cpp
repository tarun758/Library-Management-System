#include "BooksLinkedList.h"
#include<iostream>
#include "Notifier.h"
BooksLinkedList::BooksLinkedList()
	: headPointer(nullptr), totalNumberOfBooks(0)
{

}

BooksLinkedList::~BooksLinkedList()
{
	Book *bookToDelete(nullptr);
	while (nullptr != BooksLinkedList::headPointer)
	{
		bookToDelete = BooksLinkedList::headPointer;
		BooksLinkedList::deleteBookUsingISBN(bookToDelete->getISBN(), bookToDelete->getCopyNumber());
	}
}

void BooksLinkedList::addBookSortedAlphabetically(Book *bookToAdd)
{
	if (nullptr == BooksLinkedList::headPointer)		    							// test if the head pointer of the linked list is empty
	{
		BooksLinkedList::addBookAtBeginning(bookToAdd);    								// if it is empty then call the function that adds a node to the beginning
	}
	else												  								// if the head pointer of the linked list is not empty
	{
		// traverese the list to find the location of insertion
		Book* currentNode = BooksLinkedList::headPointer;				// set a pointer called current to the head pointer of the linked list
		Book* previousNode = nullptr;									// set a pointer to null so that it holds the previous node while traversing
		while (nullptr != currentNode)
		{
			if (currentNode->getName() >= bookToAdd->getName())			// to add names alphabateically test if the name is greater than or equal the new name
			{
				break;													// the position is found stop the loop
			}
			else														// if the position is not found then continue looking for it
			{
				previousNode = currentNode;
				currentNode = currentNode->nextBookPointer;
			}
		}
		if (currentNode == BooksLinkedList::headPointer)				// if the position has been found and it is to be inserted before the beginning of the linked list
		{
			bookToAdd->nextBookPointer = BooksLinkedList::headPointer;	// set the next pointer of the new patron to point to the head
			BooksLinkedList::headPointer = bookToAdd;					// update the head pointer to be the new patron
		}
		else															// if the position has been found and it is not to be inserted before the beginning
		{
			bookToAdd->nextBookPointer = currentNode;					// set the next patron pointer to be the current pointer becasue that where it stopped
			previousNode->nextBookPointer = bookToAdd;					// make the previous pointer next patron pointer point to the new patron
		}
		BooksLinkedList::totalNumberOfBooks++;
	}
}

void BooksLinkedList::addBookAtBeginning(Book *bookToAdd)
{
	if (nullptr == BooksLinkedList::headPointer)
	{
		BooksLinkedList::headPointer = bookToAdd;
	}
	else
	{
		bookToAdd->nextBookPointer = BooksLinkedList::headPointer;
		BooksLinkedList::headPointer = bookToAdd;
	}
	BooksLinkedList::totalNumberOfBooks++;
}

void BooksLinkedList::addBookAtEnd(Book *bookToAdd)
{
	bookToAdd->nextBookPointer = nullptr;					// since this is the last node so nothing is after it
	if (nullptr == BooksLinkedList::headPointer)
	{
		BooksLinkedList::headPointer = bookToAdd;
	}
	else // the LL is not empty   
	{
		Book *lastNode = BooksLinkedList::headPointer;	    // Create a temporary node to hold the current head
		while (nullptr != lastNode->nextBookPointer)	   // Loop throught until nullptr is encountered
		{
			lastNode = lastNode->nextBookPointer;
		}
		// Now currentHead has reached the last node
		lastNode->nextBookPointer = bookToAdd;
	}
	BooksLinkedList::totalNumberOfBooks++;
}

bool BooksLinkedList::deleteBookUsingISBN(const std::string &bookISBN, const uint16_t &copyNumber)
{
	bool isDeleteSuccessful(true);
	if (nullptr == BooksLinkedList::headPointer)
	{
		Notifier::noBooksAdded();
		isDeleteSuccessful = false;				// No Book was deleted so return false to the caller
	}
	else
	{
		Book *currentNode{ BooksLinkedList::headPointer }, *previousNode{ nullptr };
		while (nullptr != currentNode)
		{
			if (currentNode->getISBN() == bookISBN && currentNode->getCopyNumber() == copyNumber)
			{
				if (currentNode == BooksLinkedList::headPointer && !currentNode->getIsBorrowed())
				{
					BooksLinkedList::headPointer = BooksLinkedList::headPointer->nextBookPointer;
					std::cout << "Below are the details of the book that will be deleted: \n";
					std::cout << *currentNode;
					delete currentNode;
					isDeleteSuccessful = true;							// Not neccessary but added for clarity
					BooksLinkedList::totalNumberOfBooks--;
				}
				else if(currentNode == BooksLinkedList::headPointer && currentNode->getIsBorrowed()) {
					std::cout << "The book "<< currentNode->getName() << " with ISBN " << currentNode->getISBN() << " and copy number << " <<  currentNode->getCopyNumber() << " can not be deleted since it is borrowed by a patron currently.\n";
					isDeleteSuccessful = false;
				}
				else
				{
					previousNode->nextBookPointer = currentNode->nextBookPointer;
				}
				break;
			}
			else
			{
				previousNode = currentNode;
				currentNode = currentNode->nextBookPointer;
			}
			isDeleteSuccessful = false;
		}
	}
	return isDeleteSuccessful;
}

bool BooksLinkedList::deleteBookAtBeginning()
{
	bool isDeleteSuccessful(true);		// The return value for the caller indicating wether the deletion was successful or not
	if (nullptr == BooksLinkedList::headPointer)
	{
		isDeleteSuccessful = false;		// No patron was deleted so return false to the caller
	}
	else
	{
		Book *currentHead = BooksLinkedList::headPointer;
		if (!currentHead->getIsBorrowed())
		{
			BooksLinkedList::headPointer = BooksLinkedList::headPointer->nextBookPointer;
			// Although printing a message within a function that returns a bool violates the one-input one-output rule, this is an exception.
			std::cout << "Below are the details of the book that will be deleted: \n";
			std::cout << *currentHead;
			delete currentHead;											// free the memory assigned to the patron
			BooksLinkedList::totalNumberOfBooks--;					// decrement the number of total registered patrons
			isDeleteSuccessful = true;									// The patron has been successfully deleted so return true to the caller
		}
		else {
			std::cout << "The book "<< currentHead->getName() << " with ISBN " << currentHead->getISBN() << " and copy number << " <<  currentHead->getCopyNumber() << " can not be deleted since it is borrowed by a patron currently.\n";
		}
	}
	return isDeleteSuccessful;
}

bool BooksLinkedList::deleteBookAtEnd()
{
	bool isDeleteSuccessful(true);
	if (nullptr == BooksLinkedList::headPointer)							// the list is empty
	{
		isDeleteSuccessful = false;											// no book was deleted so return false to the caller
	}
	else if (nullptr == BooksLinkedList::headPointer->nextBookPointer)	// the list contains only node which is the head
	{
		if (!BooksLinkedList::headPointer->getIsBorrowed())
		{
			std::cout << "There is only one book in the list that will be deleted. Below are the details of the book:\n";
			std::cout << *BooksLinkedList::headPointer;			// print the details of the book to be deleted using the overloaded << operator
			delete BooksLinkedList::headPointer;				// free the memory assigned to the book
			BooksLinkedList::headPointer = nullptr;				// make the head pointer point to null since it is empty now
			BooksLinkedList::totalNumberOfBooks--;				// decrement the number of total books
			isDeleteSuccessful = true;							// not neccessary but added for clarity
		}
		else {
			std::cout << "The book "<< BooksLinkedList::headPointer->getName() << " with ISBN " 
			<< BooksLinkedList::headPointer->getISBN() << " and copy number << " 
			<< BooksLinkedList::headPointer->getCopyNumber() << " can not be deleted since it is borrowed by a patron currently.\n";
		}
	}
	else if (nullptr != BooksLinkedList::headPointer->nextBookPointer) // the list contians more than one node so traverse through it untill the last node
	{
		Book *currentNode{ BooksLinkedList::headPointer }, *previousNode{ nullptr };
		while (nullptr != currentNode->nextBookPointer)
		{
			previousNode = currentNode;
			currentNode = currentNode->nextBookPointer;
		}
		if (!currentNode->getIsBorrowed())
		{
			std::cout << "Below are the details of the book that will be deleted: \n";
			std::cout << *currentNode;
			delete currentNode;										// now we are at the end of the list so delete the last node
			previousNode->nextBookPointer = nullptr;
			BooksLinkedList::totalNumberOfBooks--;					// decrement the number of total books
			isDeleteSuccessful = true;								// not neccessary but added for clarity since the value is initialized to true 
		}
		else {
			std::cout << "The book " << currentNode->getName() << " with ISBN " << currentNode->getISBN() << " and copy number << " << 
			currentNode->getCopyNumber() << " can not be deleted since it is borrowed by a patron currently.\n";
		}
	}
	return isDeleteSuccessful;
}
// This function prints details of books using two paramateres, the first being the criterion and the other a value
void BooksLinkedList::printBooksDetails(const std::string &criterion, const std::string &value) const
{
	if (nullptr == BooksLinkedList::headPointer)
	{
		Notifier::noBooksRegistered();
	}
	else
	{
		Book *currentHead = BooksLinkedList::headPointer;
		while (nullptr != currentHead)
		{
			if ("All" == criterion && "" == value)
			{
				std::cout << *currentHead;
			}
			else if ("All" == criterion && "Available" == value)
			{
				if (!currentHead->getIsBorrowed())
				{
					std::cout << *currentHead;
				}
			}
			else if ("All" == criterion && "Borrowed" == value)
			{
				if (currentHead->getIsBorrowed())
				{
					std::cout << *currentHead;
				}
			}
			else if ("Category" == criterion)
			{
				if (currentHead->getCategory() == value)
				{
					std::cout << *currentHead;
				}
			}
			else if ("Genre" == criterion)
			{
				if (currentHead->getGenre() == value)
				{
					std::cout << *currentHead;
				}
			}
			currentHead = currentHead->nextBookPointer;
		}
	}
}

// Returns true if a patron in the linked list exists with the same email provided otherwise false
bool BooksLinkedList::doesBookISBNExist(const std::string &ISBN, Book *headPointer)
{
	bool isFound(true);
	Book *currentHeadPointer(headPointer);
	while (nullptr != currentHeadPointer)
	{
		if (currentHeadPointer->ISBN == ISBN)
		{
			isFound = true;			// not necessary but added for clarity
			break;					// the email address exists so exit the loop
		}
		else
		{
			currentHeadPointer = currentHeadPointer->nextBookPointer;
		}
		isFound = false;			// the email address does not exist so assign false to the return value
	}
	return isFound;
}

// Returns true if the head pointer of the linked list is null otherwise it returns false
bool BooksLinkedList::isHeadEmpty(Book *headPointer) const
{
	return nullptr == headPointer;		// returns true if the headPointer equals to null otherwise returns false
}

Book* BooksLinkedList::searchForABook(const std::string &criterion, const std::string &value, const uint16_t &copyNumber, Book *headPointer)
{
	Book *returnBook{ nullptr };
	Book *currentHead{ headPointer };
	while (nullptr != currentHead)
	{
		if ("ISBN" == criterion)
		{
			if (currentHead->ISBN == value && currentHead->copyNumber == copyNumber)
			{
				returnBook = currentHead;
				break;
			}
			else
			{
				currentHead = currentHead->nextBookPointer;
			}
		}
		else if ("Name" == criterion)
		{
			if (currentHead->name == value && currentHead->copyNumber == copyNumber)
			{
				returnBook = currentHead;
				break;
			}
			else
			{
				currentHead = currentHead->nextBookPointer;
			}
		}
		returnBook = nullptr;		// the book was not found so return null to the caller. Not neccessary but added for clarity
	}
	return returnBook;
}