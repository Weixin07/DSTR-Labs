#include <iostream>
#include <string>

using namespace std;

//title, author, book details, book id
struct book
{
	string title;
	string author;
	string bookDetails;
	int bookID;

	book* nextAddress;
}*head, * tail, * current, * newNode;

void insertfromfront(int bookID, string title, string author, string bookDetails)
{
	//create new node
	newNode = new book;
	newNode->bookID = bookID;
	newNode->title = title;
	newNode->author = author;
	newNode->bookDetails = bookDetails;
	newNode->nextAddress = NULL;

	//insert new node
	if (head == NULL) {
		head = tail = newNode;
	}
	else {
		newNode->nextAddress = head;
		head = newNode;
	}
}

void DisplayList()
{
	current = head;

	while (current != NULL) {
		cout << endl << current->bookID << "-" << current->title << endl;
		cout << current->author << endl;
		cout << "'" << current->bookDetails << "'" << endl << endl;
		current = current->nextAddress;
	}

	cout << "List ends here!" << endl;
}

//Method 1: Without Tail
void deletefromendwithouttail()
{
	//Ask whether the list is empty or not
	if (head == NULL) {
		cout << "The list is still empty!" << endl;
		return;
	}

	//If list isn't empty
	current = head;
	book* prev = NULL;

	while (current->nextAddress != NULL) //If not the last node, move until the last node
	{
		prev = current;
		current = current->nextAddress;
	}

	//Situation 1: THe list still has many nodes (Optional = for tails only)
	if (prev != NULL) {
		prev->nextAddress = NULL;
		tail = prev; //move tail to the previous node before deleting the last node;
	}

	//Situation 2: The list left only 1 node (optional = for tails only)
	else {
		head = tail = NULL;
	}
	cout << "The deleted value is " << current->bookID << endl;
	delete current;
}

//Method 2: Not Encouranged - Delete with tail is not efficient because still need 0(n) to find previous point
// https://www.freecodecamp.org/news/big-o-notation-why-it-matters-and-why-it-doesnt-1674cfa8a23c/
//Unless its a double linked list because they already have a previous and next address
//In a double linked list, the while loop is not neccessary
void deletefromendwithtail()
{
	//Check whether the list is empty or not
	if (head == NULL) {
		cout << "The list is still empty!" << endl;
		return;
	}
	//If not empty, then proceed to delete
	if (head != tail) { //Situation 1: still have many nodes in the linked list
		current = head;

		while (current->nextAddress != tail) {
			current = current->nextAddress;
		}
		current->nextAddress = NULL;
		cout << "Deleted Item: " << tail->bookID << endl;
		delete tail;
		tail = current;
	}
	else { //Situation 2: left only 1 node in the list
		cout << "Deleted Item: " << tail->bookID << endl;
		delete tail;
		head = tail = NULL;

	}
}

//search function
bool searchBasedOnBookID(int bookID) {
	current = head;

	while (current != NULL) {
		if (current->bookID == bookID) {
			return true;
		}
		current = current->nextAddress;
	}
	return false;	
}

int main()
{
	string title;
	string author;
	string bookDetails;
	int bookID = 0;

	head = current = NULL;

	int decision = 1;
	while (decision != 0)
	{
		bookID++; //book_id=1
		cout << "Enter the Book Name: ";
		getline(cin, title);
		cout << "Enter the Book Author Name: ";
		getline(cin, author);
		cout << "Enter the Book Details: ";
		getline(cin, bookDetails);

		insertfromfront(bookID, title, author, bookDetails);
		cout << endl;
		cout << "Would you like to add a book? Type: 1 for Yes, 0 for No. \n";
		cin >> decision;
		cin.ignore();
		cout << endl;
	}

	//display items
	DisplayList();

	decision = 1;
	while (decision != 0) {
		cout << "Do you want to search something from the list? 1-Yes, 0-No: " << endl;
		cin >> decision;

		if (decision == 1) {
			cout << "Which book do you wish to search?" << endl;
			cin >> decision;

			if (searchBasedOnBookID(decision)) {
				cout << "Book item of " << decision << " is in the list!" << endl << endl;
			}
			else {
				cout << "Book item of " << decision << " is NOT in the list!" << endl << endl;
			}
		}
	}

	//delete from the end
	decision = 1;

	while (decision != 0) {
		cout << "Do you wish to delete anything from the list? 1 - Yes, 0 - No" << endl;
		cin >> decision;

		if (decision == 1) {
			deletefromendwithouttail();
		}
		cout << endl;
	}

	DisplayList();
	return 0;
}