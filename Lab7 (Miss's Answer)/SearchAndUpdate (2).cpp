#include <iostream>
#include <string>

using namespace std;

struct book
{
	string title;
	string author;
	string book_details;
	int book_id;
	book* nextAdd;
} *head, * newnode, * current;


bool returnDuplicateResult(string bookname)
{
	current = head;
	while (current != NULL)
	{
		if (bookname == current->title)
		{
			return true;
		}
		current = current->nextAdd;
	}
	return false;
}

int insertfromFront(int book_id, string title, string author, string book_details)
{
	//search item (title) -> return boolean
	if (returnDuplicateResult(title))
	{
		cout << "Book Name already appear in the list! Please choose other book name! " << endl;
		return 0;
	}

	//create new node
	newnode = new book;
	newnode->book_id = book_id; //assign the value to new node
	newnode->title = title;
	newnode->author = author;
	newnode->book_details = book_details;
	newnode->nextAdd = NULL;

	//insert new node
	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->nextAdd = head;
		head = newnode;
	}
	return 1;
}

void DisplayListFromFront()
{
	current = head;

	while (current != NULL)
	{
		cout << current->book_id << " - " << current->title << " - " << current->author << " - ";
		cout << current->book_details << endl;
		current = current->nextAdd;
	}
	cout << "List is ended here!" << endl << endl;
}

void deletefromEnd()
{
	//1. ask whether head is empty or not?
	if (head == NULL)
	{
		cout << "The list is still empty!" << endl;
		return;
	}

	//2. if list is not empty? 
	current = head;
	book* prev = NULL;
	while (current->nextAdd != NULL) //if still not the last node, move until reach to last node.
	{
		prev = current;
		current = current->nextAdd;
	}

	//situation 1: the list still have many nodes
	if (prev != NULL)
	{
		prev->nextAdd = NULL;
	}
	//situation 2: the list left only 1 node
	else
	{
		head = NULL; //tail is optional if you did not use the tail
	}

	cout << "The deleted value is " << current->book_id << endl;
	delete current;
}

//search a book and edit its details
void searchAndUpdate(string bookname)
{
	//situation 1: ensure the list is not empty, so if really empty, then return
	if (head == NULL)
	{
		cout << "Technical Issue! Unable to search due to list is empty!" << endl;
		return;
	}

	//situation 2: if list not empty, then start search and update
	current = head;//start from first node

	while (current != NULL)
	{
		if (bookname == current->title)
		{
			cout << "Book of " << bookname << " was found!";
			cout << endl << "Enter a new details for that book: ";
			getline(cin, current->book_details);
			DisplayListFromFront();
			return;
		}
		current = current->nextAdd;
	}
	cout << "THe book you entered is not inside the list! Please recheck your book title again!" << endl;
}


int main()
{
	string title;
	string author;
	string book_details;
	int book_id = 0;

	head = NULL;

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
		int value = insertfromFront(book_id, title, author, book_details);
		if (value == 0)
		{
			book_id--;
		}
		cout << endl;
		cout << "Would you like to add a book? Type: 1 for Yes, 0 for No. \n";
		cin >> decision; //insert decision
		cin.ignore();
	}

	//display items
	DisplayListFromFront();

	//invoke the search function and update if the user wish to edit any details
	decision = 1; string bookname;
	while (decision != 0)
	{
		cout << "Do you want to edit any book details or not? 1 - Yes, 2 - No : ";
		cin >> decision;
		cin.ignore();

		if (decision == 1)
		{
			cout << "Which book you want to search? Enter your book name here : ";
			getline(cin, bookname);
			searchAndUpdate(bookname);
		}
	}
	return 0;
}