//Exercise 1: Learn how to insert to the sorted list
//Exercise 2: how to calculate the size of the linked list(2 ways)
#include <iostream>
using namespace std;

//global variable - size
int sizeofLinkedList = 0; //way 1

//create struct car - car id
struct car
{
	int CarID;
	car* nextAdd;
} *head;

//create a newnode function
car* createNewNode(int CarID)
{
	//put everything inside the heap - therefore pointer need arrow to access the car structure which not belong to this pointer
	//because it is only an agent
	car* newnode = new car;
	newnode->CarID = CarID;
	newnode->nextAdd = NULL;

	return newnode;
}

//view list function
void viewList()
{
	car* current = head;
	while (current != NULL)
	{
		cout << "Car Id : " << current->CarID << endl;
		current = current->nextAdd;
	}
	cout << "End of List!" << endl << endl;
}

//insert into the sorted list function
void InsertIntoSortedList(int CarID)
{
	car* newnode = createNewNode(CarID); //always ask the create function to prepare the new node first

	//time to insert the newnode
	if (head == NULL) //situation 1: list is empty, newnode always become the first node
	{
		head = newnode;
	}
	//situation 2: always the newnode value lesser or equal to the head value, use the insert to the front algorithm
	else if (newnode->CarID <= head->CarID)
	{
		newnode->nextAdd = head;
		head = newnode;
	}
	//situation 3: always the newnode value is more than the head value, therefore always insert to the middle / end of the list
	else
	{
		car* current = head->nextAdd; //start check with second node
		car* prev = head; //keep previous add for insert purpose

		while (current != NULL)
		{
			if (newnode->CarID <= current->CarID) //if lesser than the current value
			{
				break; //stop the loop because found the insertion place now.
			}
			//else if still more than the current value? keep looping until the end of the list/ until find the location to insert
			prev = current;
			current = current->nextAdd;
		}
		//assign the newnode to the list now!
		prev->nextAdd = newnode;
		newnode->nextAdd = current;
	}

	::sizeofLinkedList++; //use scope operator to ensure the variable will refer to the global variable section
}

//create function to check the size
int size() //way 2
{
	car* current = head;
	int linkedlistsize = 0;
	while (current != NULL)
	{
		linkedlistsize++;
		current = current->nextAdd;
	}
	return linkedlistsize;
}

int main()
{
	head = NULL; //start with empty list
	InsertIntoSortedList(75); //always make this is the first node (situation 1)
	InsertIntoSortedList(55); //always become the first node even already have a list (situation 2)
	InsertIntoSortedList(35); //always become the first node even already have a list (situation 2)
	InsertIntoSortedList(85); //always insert to the end of list with situation 3
	InsertIntoSortedList(65); //always insert to the middle of list with situation 3
	InsertIntoSortedList(95); //always insert to the end of list with situation 3
	InsertIntoSortedList(37); //always insert to the middle of list with situation 3 (second node)
	viewList();
	cout << endl << "The size of linked list now is " << ::sizeofLinkedList << endl;
	cout << endl << "The size of linked list now is " << size()<< endl;
	return 0;
}