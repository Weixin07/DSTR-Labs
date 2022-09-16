//Ex 1: Learn how to insert to a specific location of the list
//Exercise 2: How to delete the item from the front of the list
#include <iostream>
using namespace std;

//global variable of size
int sizeOfLinkedList = 0;

//build a car structure
struct car {
	int carID;
	car* nextAddress;
}*head, *tail; 
//head: to help finding the first place
//tail: to help finding the last place

//create new node function
car* createNewNode(int carID) {
	car* newNode = new car;
	newNode->carID = carID;
	newNode->nextAddress = NULL; //to indicate that the new node has no relationship yet

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

//insert into the specific location
void insertIntoSpecificLocation(int value, int chosenPosition = 1) {
	//always create a new node with details first
	car* newNode = createNewNode(value);

	//insertion
	//Situation 1: if list empty, head refer to new node
	if (head == NULL) {
		head = tail = newNode; //the tail is for situation 3, cuz if not stated, the system can't find the tail and place it there
	}
	
	//Situation 2: if list not empty, the chosen position always give less than/ equal to 1, insert to the front
	else if (chosenPosition <= 1) {
		newNode->nextAddress = head;
		head = newNode;
	}
	
	//Situation 3: if list not empty, the chosen position always more than 1 and bigger than size of linked list, insert into last location
	else if (chosenPosition > sizeOfLinkedList) {
		tail->nextAddress = newNode;
		tail = newNode;
	}
	
	//Situation 4: if list not empty, the chosen position always more than 1, less than size of linked list, insert into the middle of list
	else {
		car* current = head->nextAddress;
		car* previous = head;

		int currentPointerIndex = 2; //because normal people usually in the middle's starting is 2
	
		while (chosenPosition != currentPointerIndex) {
			previous = current;
			current = current->nextAddress;
			currentPointerIndex++;
		}
		previous->nextAddress = newNode;
		newNode->nextAddress = current;
	}
	::sizeOfLinkedList++;
}

//delete from front of the list
void deleteFromFrontOfList() {
	if (head == NULL) {
		cout << "Underflow happened here! Do not delete anything from this this!" << endl;
		return; //to end function
	}//must put this if statement else the system can't find any data(if the list is data), this condition is called underflow
	
	//if the list isn't empty
	car* current = head;
	head = head->nextAddress;
	
	if (head == NULL) {
		tail = NULL; //delete all of the items in the list, so need to state tail as NULL value to ensure that the list is empty
	}

	cout << "Deleted car ID: " << current->carID << endl;
	delete current;

	::sizeOfLinkedList--;
}

int main() {
	head = tail = NULL; //to ensure everything will start from empty
	int position = 1;

	//insert into specific location: start 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ends with randomized value based on user's choice
	for (int value = 1; value <= 10; value++) {
		//Situation 1: if list still empty - direct assign the new node to the first item
		if (head == NULL) {
			insertIntoSpecificLocation(value);
			continue; //continue the for loop
		}
		//Situation 2: If list is not empty
		cout << "Which location would you like to place the number of " << value << "? Range between 1 - " << ::sizeOfLinkedList + 1 << " : ";
		cin >> position;
		insertIntoSpecificLocation(value, position);
	}

	viewList();

	cout << "The size of linked list is " << ::sizeOfLinkedList << "." << endl << endl;
	
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();
	//deleteFromFrontOfList();

	while (head != NULL) {
		deleteFromFrontOfList();
	}

	viewList();

	cout << "The size of linked list is " << ::sizeOfLinkedList << "." << endl << endl;

	return 0;
}

