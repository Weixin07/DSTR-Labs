//Exercise 1: Learn how to insert to a specific location of the list
//Exercise 2: How to delete the item from the front of the list

#include <iostream>
using namespace std;

//global variable of size
int sizeofLinkedList = 0;

//build a car structure
struct car
{
	int CarID;
	car* nextAdd;
}* head, *tail; //head-> help on finding the first place, tail ->finding the last place

//create newnode function
car* createNewNode(int CarID)
{
	car* newnode = new car;
	newnode->CarID = CarID;
	newnode->nextAdd = NULL; //to indicate that this newnode is still no relationship
	return newnode;
}

//view list function
void viewList()
{
	car* current = head;

	while (current != NULL)
	{
		cout << current->CarID << " , ";
		current = current->nextAdd;
	}
	cout << endl << "End of the list!" << endl;
}

//insert into the specific location
void insertIntoSpecificLocation(int value, int chosenPosition = 1)
{
	//always need to create a newnode with the details first
	car* newnode = createNewNode(value);

	//do the insertion now!
	//situation 1: if list is still empty, head refer to the newnode directly
	if (head == NULL)
	{
		head = tail = newnode;
	}

	//situation 2: if list is not empty, the chosenPosition always give less than / equals to 1, insert to the front
	else if (chosenPosition <= 1)
	{
		newnode->nextAdd = head;
		head = newnode;
	}

	//situation 3: if list is not empty and the chosenPosition always more than 1 and always bigger than the size of linked list
	//insert into the last location
	else if (chosenPosition > sizeofLinkedList)
	{
		tail->nextAdd = newnode;
		tail = newnode;
	}

	//situation 4: if list not empty, and the chosenPosition always more than 1 or less than /equals to the size of linked list
	//insert into the middle of the list
	else
	{
		car* current = head->nextAdd;
		car* prev = head;
		int currentPointerIndex = 2;

		while (chosenPosition != currentPointerIndex)
		{
			prev = current;
			current = current->nextAdd;
			currentPointerIndex++;
		}
		prev->nextAdd = newnode;
		newnode->nextAdd = current;
	}

	::sizeofLinkedList++;
}

//delete item from the front of the list
void deleteFromFrontofList()
{
	//if list is empty, means underflow, so stop the deletion
	if (head == NULL)
	{
		cout << "Underflow happen! Do not delete anything from this list!" << endl;
		return;
	}

	//if the list not empty
	car* current = head;
	head = head->nextAdd;

	if (head == NULL)
	{
		tail = NULL; //delete all the items in the list, so need to make the tail as NULL
	}

	cout << "Deleted car id: " << current->CarID << endl;
	delete current;

	::sizeofLinkedList--;
}

int main()
{
	head = tail = NULL; //ensure all the things are starting from empty!
	int position = 1;

	//insert into specific location : start 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , ends with randomize value based on user choice
	for (int value = 1; value <= 10; value++)
	{
		//if the list still empty - direct assign the new node to the first item
		if (head == NULL)
		{
			insertIntoSpecificLocation(value);
			continue;
		}
		//if list not empty, 
		cout << "Which location you would like to locate the number of " << value << "? Range bet. 1 - "
			<< ::sizeofLinkedList + 1 << " : ";
		cin >> position;
		insertIntoSpecificLocation(value, position);
	}

	viewList();
	cout << "The size of the linked list is " << ::sizeofLinkedList << endl;

	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();
	//deleteFromFrontofList();

	while (head != NULL)
	{
		deleteFromFrontofList();
	}

	viewList();
	cout << "The size of the linked list is " << ::sizeofLinkedList << endl;
	return 0;
}