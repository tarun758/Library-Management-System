#pragma once
#include <string>
const std::string EMPTYSTR = std::string();
class Book
{
private:
	// Constructors
	Book(const Book& book) = delete;

	// Properties
	std::string name;						 // Specifies the name of a given Book instance
	std::string ISBN;						 // Specifies the ISBN of a given Book instance
	std::string edition;					 // Specifies the edition of a given Book instance
	uint16_t    copyNumber;					 // Specifies the copy number of a given Book instance
	std::string category;					 // Specifies the category of a given Book instance
	std::string genre;						 // Specifies the genre of a given Book instance 
	bool		isBorrowed;					 // Specifies whether a book is borrowed or not
	Book        *nextBookPointer;
	static uint32_t totalNumberOfBooks;		 // Keeps track of the number of Book instances created
	
	// Operator Overloading
	friend std::ostream& operator<<(std::ostream& os, const Book &book);
	friend class BooksLinkedList;
public:
	// Constructors
	Book();
	Book(const std::string& name, 
		 const std::string& ISBN,
		 const std::string& edition,
		 const uint16_t& copyNumber,
		 const std::string& category,
		 const std::string& genre); 	
	
	// Destructor
	~Book();    

	// Setters
	void setName(const std::string& name);
	void setISBN(const std::string& ISBN);
	void setEdition(const std::string& edition);
	void setCopyNumber(const uint16_t& copyNumber);
	void setCategory(const std::string& category);
	void setGenre(const std::string& genre);
	void setIsBorrowed(const bool& isBorrowed);

	// Getters:
	std::string getName()		const;
	std::string getISBN()		const;
	std::string getEdition()	const;
	uint16_t    getCopyNumber() const;
	std::string getCategory()	const;
	std::string getGenre()		const;
	bool		getIsBorrowed()	const;
	static int	getTotalNumberOfBooks();
	
	// Methods
	std::string toString() const;						// Prints the information of a book
	static void printTotalNumberOfBooks();				// Prints the total number of books
};