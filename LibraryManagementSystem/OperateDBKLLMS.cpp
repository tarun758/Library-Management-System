#include <iostream>
#include "OperateDBKLLMS.h"
#include "Patron.h"
#include "Book.h"
#include "PatronHelperFunctions.h"
#include "PatronsLinkedList.h"
#include "BooksLinkedList.h"
#include "BookHelperFunctions.h"
#include "Validator.h"
#include "Notifier.h"
#include "Menus.h"
#include "IO.h"

PatronsLinkedList patronsLinkedList;
BooksLinkedList booksLinkedList;

int OperateDBKLLMS::start()
{
	int returnValue(0);
	register uint16_t librarianChoiceMainMenu(0);		// takes the input of the user 
	register bool	  continueExecuting(true);			// specifies whether the program will continue executing or stop
	std::string		  searchCriterion("");				// specifies the search criterion for searching and printing deatials of patrons
	std::string		  patronCreationPosition("");       // specifies the patron creation position at the list
	std::string		  bookCreationPosition("");
	while (continueExecuting)							// continue execute as long as continueExecuting remains true
	{
		IO::clearScreen();								// clear the screen everytime the loop executes, this is needed here to clean the console after the first iteration
		librarianChoiceMainMenu = Menus::mainMenu();	// store the input of the user by calling the function which prints the main menu and asks for input while validating t
		switch (librarianChoiceMainMenu)
		{
		case 1:											// the curly brackets are needed becasue there are local variables declared within the case statement
		{
			uint16_t librarianChoiceBooksMenu = Menus::manageBooksMenu();
			while (18 != librarianChoiceBooksMenu)	// continue executing while the user does not input the exit menu number
			{
				switch (librarianChoiceBooksMenu)
				{
					case 1:
					{
						bookCreationPosition = "sorted alphabetically.";
						Book *bookToAdd		 = BookHelperFunctions::createBook(bookCreationPosition, booksLinkedList.headPointer);
						if (nullptr != bookToAdd)
						{
							booksLinkedList.addBookSortedAlphabetically(bookToAdd);
							Notifier::bookAddedSuccessfully(bookToAdd->getName(), bookToAdd->getISBN());
						}
						else
						{
							Notifier::bookNotAdded();
						}
						break;
					}
					case 2:
					{
						bookCreationPosition = "at the beginning.";
						Book *bookToAdd		 = BookHelperFunctions::createBook(bookCreationPosition, booksLinkedList.headPointer);
						if (nullptr != bookToAdd)
						{
							booksLinkedList.addBookAtBeginning(bookToAdd);
							Notifier::bookAddedSuccessfully(bookToAdd->getName(), bookToAdd->getISBN());
						}
						else
						{
							Notifier::bookNotAdded();
						}
						break;
					}
					case 3:
					{
						bookCreationPosition = "at the end.";
						Book *bookToAdd	     = BookHelperFunctions::createBook(patronCreationPosition, booksLinkedList.headPointer);
						if (nullptr != bookToAdd)
						{
							booksLinkedList.addBookAtEnd(bookToAdd);
							Notifier::bookAddedSuccessfully(bookToAdd->getName(), bookToAdd->getISBN());
						}
						else
						{
							Notifier::bookNotAdded();
						}
						break;
					}
					case 4:
					{
						std::string bookISBN = BookHelperFunctions::getBookISBN();
						uint16_t copyNumer   = BookHelperFunctions::getBookCopyNumber();
						Book *bookToUpdate   = booksLinkedList.searchForABook("ISBN", bookISBN, copyNumer, booksLinkedList.headPointer);

						if (nullptr != bookToUpdate && !bookToUpdate->getIsBorrowed())
						{
							std::cout << "The current details of the book: " << *bookToUpdate;
							BookHelperFunctions::updateBookDetails(bookToUpdate);
						}
						else if (nullptr != bookToUpdate && bookToUpdate->getIsBorrowed())
						{
							std::cout << "You can not update the book currently becasue it is borrowed by a patron.\n";
						}
						else
						{
							Notifier::bookNotFound(bookISBN, std::to_string(copyNumer));
						}
						break;
					}
					case 5:
					{
						std::string emailAddress  = PatronHelperFunctions::getEmailAddressOfPatron();
						Patron *patronToLendABook = patronsLinkedList.searchForAPatron(emailAddress, patronsLinkedList.headPointer);
						if (nullptr != patronToLendABook)
						{
							if (3 == patronToLendABook->numberOfBorrowedBooks)
							{
								std::cout << "The patron has already borrowed 3 books!";
							}
							else 
							{
								std::string bookISBN   = BookHelperFunctions::getBookISBN();
								uint16_t    copyNumber = BookHelperFunctions::getBookCopyNumber();
								Book*       bookToLend = booksLinkedList.searchForABook("ISBN", bookISBN, copyNumber, booksLinkedList.headPointer);
								if (nullptr != bookToLend && !bookToLend->getIsBorrowed())
								{
									bookToLend->setIsBorrowed(true);
									short index = BookHelperFunctions::findBookIndex(patronToLendABook->borrowedBooks);
									patronToLendABook->borrowedBooks[index] = bookToLend;
									patronToLendABook->numberOfBorrowedBooks++;
									std::cout << "The book has been lend to the patron successfully.\n";
								}
								else if (nullptr != bookToLend && bookToLend->getIsBorrowed())
								{
									std::cout << "The book is already borrowed!\n";
								}
								else
								{
									Notifier::bookNotFound(bookISBN, std::to_string(copyNumber));
								}
							}
						}
						else
						{
							Notifier::patronNotFound();
						}
						break;
					}
					case 6:
					{
						std::string emailAddress		= PatronHelperFunctions::getEmailAddressOfPatron();
						Patron*     patronToReturnABook = patronsLinkedList.searchForAPatron(emailAddress, patronsLinkedList.headPointer);
						if (nullptr != patronToReturnABook)
						{
							if (0 == patronToReturnABook->numberOfBorrowedBooks)
							{
								std::cout << "The patron is not currently borrowing any books!\n";
							}
							else {
								std::cout << "Below are the borrowed book(s) of the patron:\n";
								patronToReturnABook->printBorrowedBooks();
								unsigned short bookIndex(0);
								std::cout << "Enter the number of the book (1, 2, or 3) the patron wants to return: ", std::cin >> bookIndex;
								patronToReturnABook->numberOfBorrowedBooks--;
								patronToReturnABook->borrowedBooks[bookIndex - 1]->setIsBorrowed(false);
								Book* bookToReturn = patronToReturnABook->borrowedBooks[bookIndex - 1];
								patronToReturnABook->borrowedBooks[bookIndex - 1] = nullptr;
								// add the returned book to the list of borrowed books history
								unsigned short bookHistroyIndex = BookHelperFunctions::findBookHistoryIndex(patronToReturnABook->borrowedBooksHistory);
								patronToReturnABook->borrowedBooksHistory[bookHistroyIndex] = bookToReturn;
							}	
						}
						else {
							Notifier::patronNotFound();
						}
						break;
					}
					case 7:
					{
						if (nullptr == booksLinkedList.headPointer)
						{
							Notifier::noBooksRegistered();
						}
						else
						{
							booksLinkedList.~BooksLinkedList();
						}
						break;
					}
					case 8:
					{
						if (booksLinkedList.deleteBookAtBeginning())
						{
							Notifier::bookAtBeginningDeleted();
						}
						else
						{
							Notifier::noBookToDeleteAtBeginning();
						}
						break;
					}
					case 9:
					{
						if (booksLinkedList.deleteBookAtEnd())
						{
							Notifier::bookAtEndDeleted();
						}
						else
						{
							Notifier::noBookToDeleteAtEnd();
						}
						break;
					}
					case 10:
					{
						std::string bookISBN = BookHelperFunctions::getBookISBN();
						uint16_t copyNumber = BookHelperFunctions::getBookCopyNumber();
						if (booksLinkedList.deleteBookUsingISBN(bookISBN, copyNumber))
						{
							Notifier::bookDeletedSuccessfully();
						}
						else
						{
							Notifier::bookDeletedUnSuccessfully();
						}
						break;
					}
					case 11:
					{
						searchCriterion = "All";
						booksLinkedList.printBooksDetails(searchCriterion);
						break;
					}
					case 12:
					{
						std::string bookName = BookHelperFunctions::getBookName();
						uint16_t copyNumber = BookHelperFunctions::getBookCopyNumber();
						Book *book = booksLinkedList.searchForABook("Name", bookName, copyNumber, booksLinkedList.headPointer);
						if (nullptr != book)
						{
							Notifier::bookFound();
							std::cout << *book;
						}
						else
						{
							Notifier::bookNameNotFound();
						}
						break;
					}
					case 13:
					{
						std::string bookISBN = BookHelperFunctions::getBookISBN();
						uint16_t copyNumber  = BookHelperFunctions::getBookCopyNumber();
						Book *book = booksLinkedList.searchForABook("ISBN", bookISBN, copyNumber, booksLinkedList.headPointer);
						if (nullptr != book)
						{
							Notifier::bookFound();
							std::cout << *book;
						}
						else
						{
							Notifier::bookNotFound(bookISBN, std::to_string(copyNumber));
						}
						break;
					}
					case 14:
					{
						searchCriterion = "Category";
						std::string bookCategory = BookHelperFunctions::getBookCategory();
						if(bookCategory == "")
						{
							std::cout<<"Invalid Category";
						}
						else
						{
							booksLinkedList.printBooksDetails(searchCriterion, bookCategory);
						}
						break;
					}
					case 15:
					{
						searchCriterion = "Genre";
						std::string bookGenre = BookHelperFunctions::getBookGenre();
						if(bookGenre == "")
						{
							std::cout<<"Invalid Genre";
						}
						else
						{
							booksLinkedList.printBooksDetails(searchCriterion, bookGenre);
						}
						break;
					}
					case 16:
					{
						searchCriterion = "All";
						booksLinkedList.printBooksDetails(searchCriterion, "Available");
						break;
					}
					case 17:
					{
						searchCriterion = "All";
						booksLinkedList.printBooksDetails(searchCriterion, "Borrowed");
						break;
					}
				}
				IO::doNothing();
				librarianChoiceBooksMenu = Menus::manageBooksMenu();
			}
			if (18 == librarianChoiceBooksMenu)
			{
				break; // breaks out from the switch statement and not the inner while loop
			}
		}
		case 2:
		{
			uint16_t librarianChoiceManagePatronsMenu = Menus::managePatronsMenu();
			while (librarianChoiceManagePatronsMenu != 16)	// continue executing the submenu as long as the input is not 12
			{
				switch (librarianChoiceManagePatronsMenu)
				{
					case 1:
					{
						patronCreationPosition = "sorted alphabetically.\n";
						Patron *patronToAdd = PatronHelperFunctions::createPatron(patronCreationPosition, patronsLinkedList.headPointer); // the function returns null if it no memory was allocated
						if (nullptr != patronToAdd)																// if the return of the function was not a null pointer 
						{
							patronsLinkedList.addPatronSortedAlphabetically(patronToAdd);
							Notifier::patronRegisteredSuccessfully(patronToAdd->getName(), patronToAdd->getEmailAddress());
							patronsLinkedList.totalNumberOfPatrons++;
						}
						else
						{
							Notifier::patronNotAdded(); // the function returned a nullptr so no memory was allocated
						}
						break;
					}
					case 2:
					{
						patronCreationPosition = "at the beginning.\n";
						Patron *patronToAdd = PatronHelperFunctions::createPatron(patronCreationPosition, patronsLinkedList.headPointer);
						if (nullptr != patronToAdd)
						{ 
							patronsLinkedList.addPatronAtBeginning(patronToAdd); 
							Notifier::patronRegisteredSuccessfully(patronToAdd->getName(), patronToAdd->getEmailAddress());
						} 
						else
						{
							Notifier::patronNotAdded();
						}
						break;
					}
					case 3:
					{
						patronCreationPosition = "at the end.\n";
						Patron *patronToAdd = PatronHelperFunctions::createPatron(patronCreationPosition, patronsLinkedList.headPointer);
						if (nullptr != patronToAdd)
						{
							patronsLinkedList.addPatronAtEnd(patronToAdd);
							Notifier::patronRegisteredSuccessfully(patronToAdd->getName(), patronToAdd->getEmailAddress());
						}
						else
						{
							Notifier::patronNotAdded();
						}
						break;
					}
					case 4:
					{
						std::string emailAddress = PatronHelperFunctions::getEmailAddressOfPatron();
						Patron *patronToUpdate = patronsLinkedList.searchForAPatron(emailAddress, patronsLinkedList.headPointer);
						if (nullptr != patronToUpdate)
						{
							std::cout << "The current details of the patron: " << *patronToUpdate;
							PatronHelperFunctions::updatePatronRecord(patronToUpdate); 
						}
						else
						{
							Notifier::patronEmailAddressNotFound(emailAddress);
						}
						break;
					}
					case 5:
						if (patronsLinkedList.deletePatronAtBeginning()) // If the function returned true then the deletetion was successful
						{
							     // notify the user that the deletion was successful
						}
						else								     		 // The function returned false so the deletion was unsuccessful
						{
							Notifier::noPatronToDeleteAtBeginning();	 // notify the user that the deletion was unsuccessful
						}
						break;
					case 6:
						if (patronsLinkedList.deletePatronAtEnd())	// if the patron at the end was deleted successfully then
						{
							Notifier::patronAtEndDeleted();		    // notify the user that the deletion was successful
						}
						else
						{
							Notifier::noPatronToDeleteAtEnd();	    // notify the user that the deltion was unsuccessful
						}
						break;
					case 7:
					{
						std::string patronEmailAddress = PatronHelperFunctions::getEmailAddressOfPatron();
						if (patronsLinkedList.deletePatronUsingEmailAddress(patronEmailAddress))
						{
							
						}
						else
						{
							Notifier::patronDeleteUnsuccessful();
						}
						break;
					}
					case 8:
					{
						patronsLinkedList.~PatronsLinkedList();
						break;
					}
					case 9:
					{
						searchCriterion = "All";
						patronsLinkedList.printPatronsDetails(searchCriterion);
						break;
					} 
					case 10:
					{
						std::string emailAddress = PatronHelperFunctions::getEmailAddressOfPatron();
						Patron *patron = patronsLinkedList.searchForAPatron(emailAddress, patronsLinkedList.headPointer);
						if (nullptr != patron)
						{
							Notifier::patronFound();
							if (0 == patron->numberOfBorrowedBooks)
							{
								std::cout << "The patron is not borrowing any books currently.\n";
							}
							else
							{
								std::cout << "Below are the book(s) borrowed by the patron.\n";
								patron->printBorrowedBooks();
							}
						}
						else
						{
							Notifier::patronNotFound();
						}
						break;
					}
					case 11:
					{
						std::string emailAddress = PatronHelperFunctions::getEmailAddressOfPatron();
						Patron* patron = patronsLinkedList.searchForAPatron(emailAddress, patronsLinkedList.headPointer);
						if (nullptr != patron)
						{
							Notifier::patronFound();
							std::cout << "Below are the book(s) that were borrowed by the patron.\n";
							patron->printBorrowedBooksHistory();
						}
						else
						{
							Notifier::patronNotFound();
						}
						break;
					}
					case 12:
					{
						std::string emailAddress = PatronHelperFunctions::getEmailAddressOfPatron();
						Patron* patron           = patronsLinkedList.searchForAPatron(emailAddress, patronsLinkedList.headPointer);
						if (nullptr != patron)
						{
							searchCriterion = "EmailAddress";
							patronsLinkedList.printPatronsDetails(searchCriterion, emailAddress);
						}
						else
						{
							Notifier::patronNotFound();
						}
						break;
					}
					case 13:
					{
						std::string patronName = PatronHelperFunctions::getNameOfPatron(); // TODO
						searchCriterion		   = "Name";
						patronsLinkedList.printPatronsDetails(searchCriterion, patronName);		// since there might be multiple patrons with the same name
						break;
					}
					case 14:
					{
						std::string patronResidenceAddress = PatronHelperFunctions::getResidenceAddressOfPatron();
						searchCriterion = "ResidenceAddress";
						patronsLinkedList.printPatronsDetails(searchCriterion, patronResidenceAddress);
						break;
					}
					case 15:
					{
						std::string patronTelephoneNumber = PatronHelperFunctions::getTelephoneNumberOfPatron();
						searchCriterion = "TelephoneNumber";
						patronsLinkedList.printPatronsDetails(searchCriterion, patronTelephoneNumber);
						break;
					}
				}
				IO::doNothing();
				librarianChoiceManagePatronsMenu = Menus::managePatronsMenu();
			}
			if (16 == librarianChoiceManagePatronsMenu)
			{
				break;
			}
		}
		case 3:
			continueExecuting = false;
			returnValue = EXIT_SUCCESS;		// We could return 0 here and tell the caller of the function that it ran successfully, but it violates the one-input one-output rule.
			break;
		default:
			continueExecuting = false;
			returnValue = EXIT_FAILURE;		// We could return nonzero here and tell the caller of the function that it did not run successfully, but it violates the one-input one-output rule.
			break;
		}
	}
	return returnValue;
}
