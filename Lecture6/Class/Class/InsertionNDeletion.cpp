//Learn how to insert to the sorted list
#include <iostream>
using namespace std;

//create struct car
struct car {
	int carID;
	car* nextAddress;
} *head;

//create new node
car* createNewNode(int carID) {
	//puts evething inside the heap - therefore pointer need arrows to access the car structure which does not belong to this pointer
	//because it is only an agent
	car* newNode = new car;
	newNode->carID = carID;
	newNode->nextAddress = NULL;

	return newNode;
}

//view list function
void viewList() {
	car* current = head;

	while (current != NULL) {
		cout << "Car ID: " << current->carID << endl;
		current = current->nextAddress;
	}

	cout << "End of List!" << endl << endl;
}

//insert into the sorted list function
void insertIntoSortedList(int carID) {
	car* newNode = createNewNode(carID); //always ask the create function to prepare the node first

	//time to insert the new node

	//situation 1: list is empty, new node always becomes the first node
	if (head == NULL) { 
		head = newNode;
	}

	//situation 2: the new node value lesser or equal to the head value, use the insert to the front algorithm
	else if (newNode->carID <= head->carID) {
		newNode->nextAddress = head;
		head = newNode;
	}

	//situation 3: always the new node value is more than the head value, therefore always insert to the middle/end of the list
	else {
		car* current = head->nextAddress; //start from second node cuz first node already checked in situation 2
		car* previous = head; //keep previous address for insert purposes

		while (current != NULL) {
			if (newNode->carID <= current->carID) {
				break; //stop loop cuz found insertion place
			}

			//else if still more than the current value? keep looping until found the location to insert/end of list
			previous = current;
			current = current->nextAddress;
		}
		//assigning the new node to the list
		previous->nextAddress = newNode;
		newNode->nextAddress = current;
	}
}

int main() {
	head = NULL; //always start with an empty list

	insertIntoSortedList(75); //always make sure that this is the first node - Situation 1
	insertIntoSortedList(55); //always becomes the first node even already have a list - Situation 2
	insertIntoSortedList(25); //Situation 2
	insertIntoSortedList(100); //always insert into end of list - Situation 3
	insertIntoSortedList(65); //always insert into middle of list - Situation 3
	insertIntoSortedList(95); //Situation 3
	insertIntoSortedList(37); //Situation 3

	viewList();

	return 0;
}