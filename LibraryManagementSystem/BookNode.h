#pragma once
#include "Book.h"
class BookNode
{
public:
	// Properties
	Book bookNode;
	Book *nextBookNode;
	//Book *previousBookNode;    // for now leave this

	// Constructor
	BookNode();
private:

};

