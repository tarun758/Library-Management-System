#pragma once
#include <string>
#include "Book.h"
#include <vector>
#include <array>
class Patron final
{ 
private:
    Patron(const Patron& patron) = delete;  // Delete the copy constructor
    // Properties
    std::string name;                            // Stores the name of a given Patron instance  
    std::string gender;                          // Stores the gender of a given Patron instance
    std::string residenceAddress;                // Stores the patron's residence address
    std::string phoneNumber;                     // Stores the the phone number of a given Patron instance
    std::string emailAddress;                    // Stores the email address of a given Patron instance
    std::array <Book*, 3> borrowedBooks;         // Stores the borrowed books by a patron
    std::array <Book*, 10> borrowedBooksHistory; // Stores the last 10 borrowed books of a patron.
    short numberOfBorrowedBooks;                 // Stores the number of borrowed books
    Patron *nextPatronPointer;                   // A pointer to the next patron node
    static uint32_t totalNumberOfPatrons;        // Stores the total number of Patron object instances created
    
    // Operator Overloading
    friend std::ostream& operator<<(std::ostream &outputStream, const Patron &patron);
    
    // Relationships
    friend class PatronsLinkedList;                 // Allows PatronsLinkedList to access the private members of this class
    friend class OperateDBKLLMS;
public:
    // Properties
    static const uint32_t MAX_NUMBER_OF_PATRONS;    // Specifies the maximum number of Patrons that can be registered 
    
    // Constructors
    Patron();                                 
    Patron(const std::string &name, const std::string &gender, const std::string &residenceAddress, 
           const std::string &phoneNumber, const std::string &emailAddress);    // The only valid constructor allowed
    
    // Destructor
    ~Patron();    // Releases memory resources
    
    // Setters
    void setName(const std::string &name);                            // Sets the name of a given Patron instance
    void setGender(const std::string &gender);                        // Sets the gender of a given Patron instance
    void setResidenceAddress(const std::string &residenceAddress);    // Sets the residence address of a given Patron instance
	void setPhoneNumber(const std::string &phoneNumber);              // Sets the phone number of a given Patron instance
    void setEmailAddress(const std::string &emailAddress);            // Sets the email address of a given Patron instance

    // Geters
    std::string getName()	            const;    // Returns the name of a given Patron instance
    std::string getGender()             const;    // Returns the gender of a given Patron instance
    std::string getResidenceAddress()   const;    // Returns the residence address of a given Patron instance
    std::string getPhoneNumber()        const;    // Returns the phone number of a given Patron instance
    std::string getEmailAddress()       const;    // Returns the email address of a given Patron instance
    static uint32_t getTotalNumberOfPatrons();    // Returns the total number of Patrons registered
   
    // Methods
    
    short printBorrowedBooks() const;            // History of the patron's book borrowing 
    short printBorrowedBooksHistory() const;
};