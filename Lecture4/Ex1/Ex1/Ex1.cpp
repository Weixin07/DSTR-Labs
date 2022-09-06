#include <iostream>
using namespace std;

//grouping of data info
class libraryBook {
	//default access mode - private
		int bookID = 123; //data field

		int getBookID() { //function
			return bookID;
		} 

	public:
		string bookName = "ABC";

		libraryBook() {} //default constructor

		libraryBook(int bookID, string bookName) { //constructor
			this->bookID = bookID;
			this->bookName = bookName;
		}

		void setBookID(int bookID) { //method writing inside the same class
			this->bookID = bookID;
		}

		//void setBookName(string bookName) {
		//	this->bookName = bookName;
		//}

		void displayBookDetails(); //method explicit write into another location header

};

void libraryBook::displayBookDetails() {
	cout << "Book ID: " << getBookID() << endl;
	cout << "Book Name: " << bookName << endl;
}

int main() {
	//using default constructor to build the first object items
	//Using default values
	libraryBook book1; //book id = 123, book name = ABC
	book1.displayBookDetails();

	//Using new values
	book1.setBookID(234); //have to go through a method within the class cuz private
	book1.bookName = "CDF"; //can directly set cuz public
	book1.displayBookDetails();

	//using customized constructors
	//Using new values
	libraryBook book2(567, "Good Book");
	book2.displayBookDetails();

	//Using new values
	book2.setBookID(333); 
	book2.bookName = "Bad Book"; 
	book2.displayBookDetails();

	return 0;
}