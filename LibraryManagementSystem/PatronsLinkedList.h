#pragma once
#include "Patron.h"
class PatronsLinkedList final
{
private:
	// Properties
	Patron* headPointer;
	size_t  totalNumberOfPatrons;
public:
	// Constructors
	PatronsLinkedList();			// Creates a linked list
	// Destructors
	~PatronsLinkedList();			// Deletes a linked list
	// Relationships
	friend class OperateDBKLLMS;	// Allows accessing the headPointer and totalNumberOfPatrons private data members

	// Methods
	void addPatronSortedAlphabetically(Patron *patronToAdd);
	void addPatronAtBeginning(Patron *patronToAdd);			 // Add a new patron to the beginning of the linked list
	void addPatronAtEnd(Patron *patronToAdd);
	bool deletePatronUsingEmailAddress(const std::string &emailAddress);
	bool deletePatronAtBeginning();					       // Delete a patron's record
	bool deletePatronAtEnd();
	void printPatronsDetails(const std::string &criterion, const std::string &value = "") const;
	static bool doesPatronEmailExist(const std::string emailAddress, Patron *headPointer);	//
	static Patron *searchForAPatron(const std::string &emailAddress, Patron *headPointer);
	bool isHeadEmpty(Patron *headPointer) const;
};