//Exercise 2: Learn how to insert to the sorted list
#include <iostream>
using namespace std;

//create struct flower - Flower id, Flower Name
struct Flower
{
	int FlowerID;
	string FlowerName;
	Flower* nextAdd;
} *head;

//create a newnode function
Flower* createNewNode(int FlowerID, string FlowerName)
{
	//put everything inside the heap - therefore pointer need arrow to access the car structure which not belong to this pointer
	//because it is only an agent
	Flower* newnode = new Flower;
	newnode->FlowerID = FlowerID;
	newnode->FlowerName = FlowerName;
	newnode->nextAdd = NULL;

	return newnode;
}

//view list function
void viewList()
{
	Flower* current = head;
	while (current != NULL)
	{
		cout << "Flower Id : " << current->FlowerID << endl;
		cout << "Flower Name : " << current->FlowerName << endl;
		current = current->nextAdd;
	}
	cout << "End of List!" << endl << endl;
}

//build your function here
void InsertIntoSortedList(int FlowerID, string FlowerName)
{
	Flower* newnode = createNewNode(FlowerID, FlowerName);

	if (head == NULL) {
		head = newnode;
	}

	else if (newnode->FlowerName >= head->FlowerName) {
		newnode->nextAdd = head;
		head = newnode;
	}
	else {
		Flower* current = head->nextAdd; 
		Flower* prev = head; 

		while (current != NULL) {
			if (newnode->FlowerName >= current->FlowerName) {
				break;
			}
			prev = current;
			current = current->nextAdd;
		}
		prev->nextAdd = newnode;
		newnode->nextAdd = current;
	}
}

int main()
{
	int flowerid[5] = { 12, 15, 17, 34, 27 };
	string flowername[5] = { "White Lotus", "Green grass", "Red Rose", "White Rose", "Yellow Sunflower" };

	//insert to the sorted list now using the arrays above and display them in descending order.
	InsertIntoSortedList(flowerid[0], flowername[0]);
	InsertIntoSortedList(flowerid[1], flowername[1]);
	InsertIntoSortedList(flowerid[2], flowername[2]);
	InsertIntoSortedList(flowerid[3], flowername[3]);
	InsertIntoSortedList(flowerid[4], flowername[4]);
	viewList();

	return 0;
}