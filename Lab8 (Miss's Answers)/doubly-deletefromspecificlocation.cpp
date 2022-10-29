#include <iostream>
#include <string>

using namespace std;

struct book
{
	string title;
	string author;
	string book_details;
	int book_id;
	book* nextaddress;
	book* prevaddress; //doubly linked list - use this to keep the previous address
} *head, * newnode, * current, * tail; //tail used for insertion and deletion at the end of the list

void insertfromEnd(int book_id, string title, string author, string book_details)
{
	//create new node
	newnode = new book;
	newnode->book_id = book_id;
	newnode->title = title;
	newnode->author = author;
	newnode->book_details = book_details;
	newnode->nextaddress = NULL;
	newnode->prevaddress = NULL; //changes for doubly

	//situation 1: list empty
	if (head == NULL)
	{
		head = tail = newnode; //changes for doubly
	}
	//situation 2: list not empty
	else
	{
		newnode->prevaddress = tail;
		tail->nextaddress = newnode;
		tail = newnode;
	}
}

void DisplayListFromFront() //original printing
{
	current = head;

	while (current != NULL)
	{
		cout << current->book_id << " - " << current->title << " - " << current->author << " - ";
		cout << current->book_details << endl;
		current = current->nextaddress;
	}
	cout << "List is ended here!" << endl << endl;
}

void deletefromspecificlocation()
{

}

int main()
{
	string title;
	string author;
	string book_details;
	int book_id = 0;

	head = current = tail = NULL; // changes: need to make sure the tail also start from NULL value

	int decision = 1;
	while (decision != 0)
	{
		book_id++; //book_id=1
		cout << "Enter the Book Name: ";
		getline(cin, title);
		cout << "Enter the Book Author Name: ";
		getline(cin, author);
		cout << "Enter the Book Details: ";
		getline(cin, book_details);
		//insertfromfront(book_id, title, author, book_details);
		insertfromEnd(book_id, title, author, book_details);
		cout << endl;
		cout << "Would you like to add a book? Type: 1 for Yes, 0 for No. \n";
		cin >> decision; //insert decision
		cin.ignore();
	}

	//display items
	DisplayListFromFront();


	return 0;
}