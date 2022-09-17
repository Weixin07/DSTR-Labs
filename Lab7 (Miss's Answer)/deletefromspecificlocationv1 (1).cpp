#include <iostream>
#include <string>

using namespace std;

int sizeofLinkedlist = 0; //easy for your to control the chosen position from the user

struct car
{
	string bodycolor;
	string brand;
	double price;
	string carName;
	int car_id;
	car* nextaddress;
} *head, * newnode, * current; 

void insertfromend(int car_id, string carName, double price, string carBrand, string carColor)
{
	//create new node
	newnode = new car;
	newnode->car_id = car_id;
	newnode->carName = carName;
	newnode->price = price;
	newnode->brand = carBrand;
	newnode->bodycolor = carColor;
	newnode->nextaddress = NULL;

	//situation 1: list empty
	if (head == NULL)
	{
		head = newnode;
	}
	//situation 2: list not empty
	else
	{
		current = head;
		while (current->nextaddress != NULL)
		{
			current = current->nextaddress;
		}
		current->nextaddress = newnode;
	}

	sizeofLinkedlist++;
}

void DisplayListFromFront()
{
	current = head;

	while (current != NULL)
	{
		cout << current->car_id << " - " << current->carName << " - " << current->brand << " - " << current->bodycolor << " - ";
		cout << "RM " <<current->price << endl;
		current = current->nextaddress;
	}
	cout << "List is ended here!" << endl << endl;
}

void deletefromspecificlocation(int chosenPosition)
{
	//situation 1: if the list is empty / book_id is not appear in the list
	if (head == NULL || chosenPosition > sizeofLinkedlist || chosenPosition < 1)
	{
		cout << "invalid value for the book id. Please choose between 1 - " << sizeofLinkedlist << endl;
		return;
	}
	//situation 2: if the chosen position = 1 (delete from front)
	else if (chosenPosition == 1)
	{
		current = head;
		head = head->nextaddress;
		cout << "Deleted id : " << current->car_id << endl;
		delete current;
	}
	//situation 3: if the book location > 1 and less than the size of list (delete from the middle / end)
	else
	{
		current = head->nextaddress; //second node
		car* previous = head; //first node
		int current_pointer_location = 2;

		while (current != NULL)
		{
			if (current_pointer_location == chosenPosition)
			{
				previous->nextaddress = current->nextaddress;
				cout << "Deleted id : " << current->car_id << endl;
				delete current;
				break;
			}
			previous = current;
			current = current->nextaddress;
		}
	}
	sizeofLinkedlist--;
}

int main()
{
	//declare variables
	string bodycolor;
	string brand;
	double price;
	string carName;
	int car_id = 0;

	//set list start from empty
	head = NULL;

	int decision = 1;
	while (decision != 0)
	{
		car_id++; //car_id=1
		cout << "Enter the Car Name: ";
		getline(cin, carName);
		cout << "Enter the Car Brand: ";
		getline(cin, brand );
		cout << "Enter the Car Color: ";
		getline(cin, bodycolor );
		cout << "Enter the Car Price ";
		cin >> price;
		insertfromend(car_id, carName, price, brand, bodycolor);
		cout << endl;
		cout << "Would you like to add a new car? Type: 1 for Yes, 0 for No. \n";
		cin >> decision; //insert decision
		cin.ignore();
	}

	//display items
	DisplayListFromFront();

	//search and delete based on the user choice
	decision = 1; int book_id;

	while (decision != 0)
	{
		cout << "Do you want to delete any item from the list? 1 - Yes, 0 - No : ";
		cin >> decision;

		if (decision == 1)
		{
			cout << "Which book id you want to delete? Enter your book id here: ";
			cin >> book_id;
			deletefromspecificlocation(book_id);
		}
	}

	return 0;
}