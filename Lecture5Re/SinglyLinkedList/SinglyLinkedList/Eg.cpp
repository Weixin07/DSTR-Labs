//1. Building single node for linked-list
//2. Adding item to end of linked-list
//Using car as eg
#include <iostream>
using namespace std;

//Making node structure
struct Car {
	int carID;
	string carBrand;
	string carColour;

	Car* nextAddress;
}*head, * current;

//global pointer
//Car* head;
//Car* current;

void insertToEndList(Car* newNode) {
	//situation 1: List still empty
	if (head == NULL) {
		head = newNode;
	}
	//situation 2: List not empty
	else {
		current = head;

		//finding the last node, then adding the new node after the last node
		while (current->nextAddress != NULL) {
			current = current->nextAddress;
		}
		current->nextAddress = newNode;
	}
}

void displayNode() {
	current = head;

	while (current != NULL) {
		cout << "Car ID: " << current->carID << endl;
		cout << "Car Brand: " << current->carBrand << endl;
		cout << "Car Colour: " << current->carColour << endl;
		cout << "Car Memory Address: " << current << endl;
		cout << endl;

		current = current->nextAddress;
	}
	cout << "List ended here.";
}

int main() {
	head = NULL; //always start from an empty list

	//building a new node
	Car* newNode = new Car;
	newNode->carBrand = "Toyota";
	newNode->carID = 123;
	newNode->carColour = "Green";
	newNode->nextAddress = NULL;

	Car* newNode1 = new Car;
	newNode1->carBrand = "Perodua";
	newNode1->carID = 124;
	newNode1->carColour = "Black";
	newNode1->nextAddress = NULL;

	Car* newNode2 = new Car;
	newNode2->carBrand = "Honda";
	newNode2->carID = 125;
	newNode2->carColour = "Red";
	newNode2->nextAddress = NULL;

	insertToEndList(newNode);
	insertToEndList(newNode1);
	insertToEndList(newNode2);

	displayNode();

	return 0;

}