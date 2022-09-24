//first learning outcome is how to build a single node for a linked list
//second learning outcome is how to add the item to the end of the list
//car example: Car Brand, Car ID, Car Color
#include<iostream>
using namespace std;

struct Car
{
	int CarID;
	string CarBrand;
	string CarColor;

	Car* nextAddress;
	Car* previousAddress;
}*head, * current, * tail;

void displayNode()
//if want reverse printing, just copy the normal printing function and change the head to tail
//and next address become previous address
{
	current = tail;

	while (current != NULL)
	{
		cout << "Car ID : " << current->CarID << endl;
		cout << "Car Brand : " << current->CarBrand << endl;
		cout << "Car Color : " << current->CarColor << endl;
		cout << "Car memory address : " << current << endl;
		cout << endl;
		current = current->previousAddress;
	}
	cout << "List ended here!";
}

void insertToFrontOfList(Car* newnode) {
	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->nextAddress = head;
		head->previousAddress = newnode;
		head = newnode;
	}
}

void insertToEndList(Car* newnode) {
	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->previousAddress = tail;
		tail->nextAddress = newnode;
		tail = newnode;
	}
}

int main()
{
	head = NULL; //always starting from empty list

	//learn how to build a new node
	Car* newnode = new Car; //independent node
	newnode->CarBrand = "Toyota";
	newnode->CarID = 123;
	newnode->CarColor = "Green";
	newnode->nextAddress = NULL;
	newnode->previousAddress = NULL;

	Car* newnode1 = new Car; //independent node
	newnode1->CarBrand = "Perodua";
	newnode1->CarID = 124;
	newnode1->CarColor = "Black";
	newnode1->nextAddress = NULL;
	newnode->previousAddress = NULL;

	Car* newnode2 = new Car; //independent node
	newnode2->CarBrand = "Honda";
	newnode2->CarID = 125;
	newnode2->CarColor = "Red";
	newnode2->nextAddress = NULL;
	newnode->previousAddress = NULL;

	insertToEndList(newnode);
	insertToEndList(newnode1);
	insertToEndList(newnode2);

	Car* newnode3 = new Car; //independent node
	newnode3->CarBrand = "Mercedes";
	newnode3->CarID = 126;
	newnode3->CarColor = "Orange";
	newnode3->nextAddress = NULL;
	newnode3->previousAddress = NULL;

	insertToFrontOfList(newnode3);

	displayNode();
	return 0;
}