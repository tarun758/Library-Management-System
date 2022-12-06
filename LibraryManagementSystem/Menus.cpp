#include "Menus.h"
#include "Validator.h"
#include "IO.h"
#include "Notifier.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>

uint16_t Menus::mainMenu()
{
	system("color 0b");
	std::cout << std::setw(90) << "\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\n";
	std::cout << std::setw(74) << "Welcome to the Library Admin Panel\n";
	std::cout << std::setw(90) << "\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\n\n";
	std::cout << "What would you like to do today?\n";
	std::cout << "1.\tManage Books\n";
	std::cout << "2.\tManage Patrons\n";
	std::cout << "3.\tExit\n";
	std::cout << "Please enter the number of the option you want from the above menu: ";
	std::string staffChoice("");
	return Validator::checkIntegerMaxAndMinValues(staffChoice, 1, 3);
}

uint16_t Menus::manageBooksMenu()
{
	IO::clearScreen();
	std::cout << std::setw(90) << "\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\n";
	std::cout << std::setw(74) << "Welcome to the Books Management Panel\n";
	std::cout << std::setw(90) << "\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\n\n";
	std::cout << "1.  \tAdd a book sorted alphabetically by name.\n";
	std::cout << "2.  \tAdd a book to be the first in the library.\n";
	std::cout << "3.  \tAdd a book to be the last in the library.\n";
	std::cout << "4.  \tUpdate a book's details.\n";
	std::cout << "5.  \tLend a book to a patron (i.e. make a patron borrow a book).\n";
	std::cout << "6.  \tReturn back a borrowed book from a patron.\n";
	std::cout << "7.  \tDelete all the books in the library.\n";
	std::cout << "8.  \tDelete the first book in the library.\n";
	std::cout << "9.  \tDelete the last book in the library.\n";
	std::cout << "10. \tDelete a book in the list using its ISBN and copy number.\n";
	std::cout << "11. \tPrint the details of all the books in the library.\n";
	std::cout << "12. \tSearch for and display a book's details using its name.\n";
	std::cout << "13. \tSearch for and display a book's details using its ISBN.\n";
	std::cout << "14. \tSearch for and display a book's details using a specific category.\n";
	std::cout << "15. \tSearch for and display a book's details using a specific genre.\n";
	std::cout << "16. \tSearch for and display a book's details of the books currently not borrowed.\n";
	std::cout << "17. \tSearch for and display a book's details of the books currently borrowed.\n";
	std::cout << "18. \tReturn to the main menu.\n";
	std::cout << "Please enter the number of the option you want from the above menu: ";
	std::string staffChoice("");
	return Validator::checkIntegerMaxAndMinValues(staffChoice, 1, 18);
}

uint16_t Menus::managePatronsMenu()
{
	IO::clearScreen();
	std::cout << std::setw(90) << "\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\n";
	std::cout << std::setw(74) << "Welcome to the Patrons Management Panel\n";
	std::cout << std::setw(90) << "\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\\\\\\\\////\n\n";
	std::cout << "1.  \tRegister a patron sorted alphabetically by name.\n";
	std::cout << "2.  \tRegister a patron to be the first in the list.\n";
	std::cout << "3.  \tRegister a patron to be the last in the list.\n";
	std::cout << "4.  \tUpdate a patron's record.\n";
	std::cout << "5.  \tDelete the first patron in the list.\n";
	std::cout << "6.  \tDelete the last patron in the list.\n";
	std::cout << "7.  \tDelete a patron in the list using their email address.\n";
	std::cout << "8.  \tDelete all the registered patrons.\n";
	std::cout << "9.  \tPrint the details of all the registered patrons.\n";
	std::cout << "10. \tSearch for and display the details of books currently borrowed by a patron.\n";
	std::cout << "11. \tSearch for and display the details of books borrowed by a patron in the past.\n";
	std::cout << "12. \tSearch for and display the details of a patron using their email address.\n";
	std::cout << "13. \tSearch for and display the details of a patron(s) using their full name.\n";
	std::cout << "14. \tSearch for and display the details of a patron(s) using their residence address.\n";
	std::cout << "15. \tSearch for and display the details of a patron(s) using their telephone number.\n";
	std::cout << "16. \tReturn to the main menu.\n";
	std::cout << "Please enter the number of the option you want from the above menu: ";
	std::string staffChoice("");
	return Validator::checkIntegerMaxAndMinValues(staffChoice, 1, 16);
}
