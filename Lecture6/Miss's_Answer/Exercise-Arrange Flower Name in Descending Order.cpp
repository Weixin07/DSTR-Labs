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
		cout << "Flower : " << current->FlowerID;
		cout << " - " << current->FlowerName << endl;
		current = current->nextAdd;
	}
	cout << "End of List!" << endl << endl;
}

//build your function here
void InsertIntoSortedList(int FlowerID, string FlowerName)
{
	Flower* newnode = createNewNode(FlowerID, FlowerName);

	if (head == NULL) //situation 1: list is empty, newnode always become the first node
	{
		head = newnode;
	}
	//situation 2: always the newnode value more than or equal to the head value, use the insert to the front algorithm
	else if (newnode->FlowerName >= head->FlowerName)
	{
		newnode->nextAdd = head;
		head = newnode;
	}
	//situation 3: always the newnode value is more than the head value, therefore always insert to the middle / end of the list
	else
	{
		Flower* current = head->nextAdd;
		Flower* prev = head;

		while (current != NULL)
		{
			if (newnode->FlowerName >= current->FlowerName)
			{
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

	//insert to the sorted list now using the arrays above and display them in descending order in Flower Name.
	for (int i = 0; i < size(flowerid); i++)
	{
		InsertIntoSortedList(flowerid[i], flowername[i]);
	}

	viewList();
	return 0;
}