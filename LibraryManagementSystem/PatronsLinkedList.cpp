#include "PatronsLinkedList.h"
#include <iostream>
#include "Notifier.h"

// Constructors
PatronsLinkedList::PatronsLinkedList() 
	: headPointer(nullptr), totalNumberOfPatrons(0)
{
	
}

// Destructors
PatronsLinkedList::~PatronsLinkedList()
{
	Patron *nodeToDelete(nullptr);
	while (nullptr != PatronsLinkedList::headPointer)
	{
		nodeToDelete = PatronsLinkedList::headPointer;
		PatronsLinkedList::deletePatronUsingEmailAddress(nodeToDelete->getEmailAddress());
	}
}
void PatronsLinkedList::addPatronSortedAlphabetically(Patron *patronToAdd)
{
	if (nullptr == PatronsLinkedList::headPointer)							 // test if the head pointer of the linked list is empty
	{																		 
		PatronsLinkedList::addPatronAtBeginning(patronToAdd);				 // if it is empty then call the function that adds a node to the beginning
	}																		 
	else																	 // if the head pointer of the linked list is not empty
	{																		 
																		     // traverese the list to find the location of insertion				 
		Patron* currentNode = PatronsLinkedList::headPointer;				 // set a pointer called current to the head pointer of the linked list
		Patron* previousNode = nullptr;										 // set a pointer to null so that it holds the previous node while traversing
		while (nullptr != currentNode)										 
		{																	 
			if (currentNode->getName() >= patronToAdd->getName())			 // to add names alphabateically test if the name is greater than or equal the new name
			{																 
				break;														 // the position is found stop the loop
			}																 
			else															 // if the position is not found then continue looking for it
			{																 
				previousNode = currentNode;									 
				currentNode = currentNode->nextPatronPointer;				 
			}																 
		}																	 
		if (currentNode == PatronsLinkedList::headPointer)					 // if the position has been found and it is to be inserted before the beginning of the linked list
		{																	 
			patronToAdd->nextPatronPointer = PatronsLinkedList::headPointer; 	// set the next pointer of the new patron to point to the head
			PatronsLinkedList::headPointer = patronToAdd;					 // update the head pointer to be the new patron
		}																	 
		else																 // if the position has been found and it is not to be inserted before the beginning
		{																	 
			patronToAdd->nextPatronPointer = currentNode;					 // set the next patron pointer to be the current pointer becasue that where it stopped
			previousNode->nextPatronPointer = patronToAdd;					 // make the previous pointer next patron pointer point to the new patron
		}
	}
	totalNumberOfPatrons++;
}
// Methods
void PatronsLinkedList::addPatronAtBeginning(Patron *patronToAdd)
{
	if (nullptr == PatronsLinkedList::headPointer)
	{
		PatronsLinkedList::headPointer = patronToAdd;
	}
	else
	{
		patronToAdd->nextPatronPointer = PatronsLinkedList::headPointer;
		PatronsLinkedList::headPointer = patronToAdd;
	}
	PatronsLinkedList::totalNumberOfPatrons++;
}

void PatronsLinkedList::addPatronAtEnd(Patron *patronToAdd)
{
	patronToAdd->nextPatronPointer = nullptr;			// Since this is the last node so nothing is after it
	if (nullptr == PatronsLinkedList::headPointer)
	{
		PatronsLinkedList::headPointer = patronToAdd;
	}
	else // The LL is not empty   
	{
		Patron *lastNode = PatronsLinkedList::headPointer;  // Create a temporary node to hold the current head
		while (nullptr != lastNode->nextPatronPointer)	   // Loop throught until nullptr is encountered
		{
			lastNode = lastNode->nextPatronPointer;
		}
		// Now currentHead has reached the last node
		lastNode->nextPatronPointer = patronToAdd;
	}
	PatronsLinkedList::totalNumberOfPatrons++;
}

bool PatronsLinkedList::deletePatronUsingEmailAddress(const std::string &emailAddress)
{
	bool isDeleteSuccessful(true);
	if (nullptr == PatronsLinkedList::headPointer)
	{
		Notifier::noPatronsRegistered();
		isDeleteSuccessful = false;				// No Patron was deleted so return false to the caller
	}
	else
	{
		Patron *currentNode{ PatronsLinkedList::headPointer }, *previousNode{ nullptr };
		while (nullptr != currentNode)
		{
			if (currentNode->getEmailAddress() == emailAddress)
			{
				if (currentNode == PatronsLinkedList::headPointer && currentNode->numberOfBorrowedBooks == 0)
				{
					PatronsLinkedList::headPointer = PatronsLinkedList::headPointer->nextPatronPointer;
					std::cout << "Below are the details of the patron that will be deleted: \n";
					std::cout << *currentNode;
					delete currentNode;
					isDeleteSuccessful = true;							// Not neccessary but added for clarity
					PatronsLinkedList::totalNumberOfPatrons--;
				}
				else if (currentNode == PatronsLinkedList::headPointer && !currentNode->numberOfBorrowedBooks == 0)
				{
					std::cout << "The patron with name of " << currentNode->getName() << " and email address of " << currentNode->getEmailAddress() << " could not be deleted since they are borrowing books currently.\n";
				}
				else
				{
					previousNode->nextPatronPointer = currentNode->nextPatronPointer;
				}
				break;
			}
			else
			{
				previousNode = currentNode;
				currentNode  = currentNode->nextPatronPointer;
			}
			isDeleteSuccessful = false;
		}
	}
	return isDeleteSuccessful;
}
bool PatronsLinkedList::deletePatronAtBeginning()
{
	bool isDeleteSuccessful(true);		// The return value for the caller indicating wether the deletion was successful or not
	if (nullptr == PatronsLinkedList::headPointer)
	{
		isDeleteSuccessful = false;		// No patron was deleted so return false to the caller
	}
	else
	{
		Patron *currentHead = PatronsLinkedList::headPointer;
		// Although printing a message within a function that returns a bool violates the one-input one-output rule, this is an exception.
		if (currentHead->numberOfBorrowedBooks == 0)
		{
			PatronsLinkedList::headPointer = PatronsLinkedList::headPointer->nextPatronPointer;
			std::cout << "Below are the details of the patron that will be deleted: \n";
			std::cout << *currentHead;
			delete currentHead;											// free the memory assigned to the patron
			PatronsLinkedList::totalNumberOfPatrons--;					// decrement the number of total registered patrons
			isDeleteSuccessful = true;								    // The patron has been successfully deleted so return true to the caller
		}
		else {
			std::cout << "The patron with name of " << currentHead->getName() << " and email address of " << currentHead->getEmailAddress() << " could not be deleted since they are borrowing books currently.\n";
		}
	}
	return isDeleteSuccessful;
}
bool PatronsLinkedList::deletePatronAtEnd()
{
	bool isDeleteSuccessful(true);
	if (nullptr == PatronsLinkedList::headPointer)							// the list is empty
	{
		isDeleteSuccessful = false;											// no patron was deleted so return false to the caller
	}
	else if (nullptr == PatronsLinkedList::headPointer->nextPatronPointer)	// the list contains only node which is the head
	{
		std::cout << "There is only one patron in the list that will be deleted. Below are the details of the patron:\n";
		std::cout << *PatronsLinkedList::headPointer;	// print the details of the patron to be deleted using the overloaded << operator
		if (PatronsLinkedList::headPointer->numberOfBorrowedBooks == 0)
		{
			delete PatronsLinkedList::headPointer;		// free the memory assigned to the patron
			PatronsLinkedList::headPointer = nullptr;	// make the head pointer point to null since it is empty now
			PatronsLinkedList::totalNumberOfPatrons--;	// decrement the number of total patrons
			isDeleteSuccessful = true;					// not neccessary but added for clarity
		}
		else {
			std::cout << "The patron with name of " << PatronsLinkedList::headPointer->getName() 
			<< " and email address of " << PatronsLinkedList::headPointer->getEmailAddress() 
			<< " could not be deleted since they are borrowing books currently.\n";
		}
	}
	else if (nullptr != PatronsLinkedList::headPointer->nextPatronPointer) // the list contians more than one node so traverse through it untill the last node
	{
		Patron *currentNode{ PatronsLinkedList::headPointer }, *previousNode{ nullptr };
		while (nullptr != currentNode->nextPatronPointer)
		{
			previousNode = currentNode;
			currentNode  = currentNode->nextPatronPointer;
		}
		// now we are at the end of the list so delete the last node
		if (currentNode->numberOfBorrowedBooks == 0)
		{
			std::cout << "Below are the details of the patron that will be deleted: \n";
			std::cout << *currentNode;
			delete currentNode;
			previousNode->nextPatronPointer = nullptr;
			PatronsLinkedList::totalNumberOfPatrons--;				// decrement the number of total patrons
			isDeleteSuccessful = true;								// not neccessary but added for clarity since the value is initialized to true 
		}
		else
		{
			std::cout << "The patron with name of " << currentNode->getName() 
			<< " and email address of " << currentNode->getEmailAddress() << " could not be deleted since they are borrowing books currently.\n";
		}
	}
	return isDeleteSuccessful;
}
// This function prints details of registered patrons using two paramateres, the first being the criterion and the other a value
void PatronsLinkedList::printPatronsDetails(const std::string &criterion, const std::string &value) const
{
	if (nullptr == PatronsLinkedList::headPointer)
	{
		Notifier::noPatronsRegistered();
	}
	else
	{
		Patron *currentHead = PatronsLinkedList::headPointer;
		while (nullptr != currentHead)
		{
			if ("All" == criterion && "" == value)
			{
				std::cout << *currentHead;
			}
			else if ("EmailAddress" == criterion)
			{
				if (currentHead->getEmailAddress() == value)
				{
					std::cout << *currentHead;
				}
			}
			else if ("Name" == criterion)
			{
				if (currentHead->getName() == value)
				{
					std::cout << *currentHead;
				}
			}
			else if ("ResidenceAddress" == criterion)
			{
				if (currentHead->getResidenceAddress() == value)
				{
					std::cout << *currentHead;
				}
			}
			else if ("TelephoneNumber" == criterion)
			{
				if (currentHead->getPhoneNumber() == value)
				{
					std::cout << *currentHead;
				}
			}
			currentHead = currentHead->nextPatronPointer;
		}
	}
}


// Returns true if a patron in the linked list exists with the same email provided otherwise false
bool PatronsLinkedList::doesPatronEmailExist(const std::string emailAddress, Patron *headPointer)
{
	bool isFound(true);
	Patron *currentHeadPointer = headPointer;
	while (nullptr != currentHeadPointer)
	{
		if (currentHeadPointer->emailAddress == emailAddress)
		{
			isFound = true;			// not necessary but added for clarity
			break;					// the email address exists so exit the loop
		}
		else
		{
			currentHeadPointer = currentHeadPointer->nextPatronPointer;
		}
		isFound = false;			// the email address does not exist so assign false to the return value
	}
	return false;
}

// Returns true if the head pointer of the linked list is null otherwise it returns false
bool PatronsLinkedList::isHeadEmpty(Patron *headPointer) const
{
	return nullptr == headPointer;		// returns true if the headPointer equals to null otherwise returns false
}

Patron* PatronsLinkedList::searchForAPatron(const std::string &emailAddress, Patron *headPointer)
{
	Patron *returnPatron{ nullptr };
	Patron *currentHead{ headPointer };
	while (nullptr != currentHead)
	{
		if(currentHead->emailAddress == emailAddress)  
		{
			returnPatron = currentHead;
			break;
		}
		else
		{
			currentHead = currentHead->nextPatronPointer;
		}
		returnPatron = nullptr;		// the patron was not found so return null to the caller. Not neccessary but added for clarity
	}
	return returnPatron;
}