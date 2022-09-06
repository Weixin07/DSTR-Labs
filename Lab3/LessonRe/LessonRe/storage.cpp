//Learn the difference between stack and heap
//Especially the automation part

#include <iostream>
using namespace std;

int* ptr = NULL;

//function 1: To see what happens if we create an item in stack using a function
void createStackItem() {
	int value = 9;
	ptr = &value;
	cout << ptr << endl;
	cout << *ptr << endl;
}

//function 2: To see what happens if we create an item in heap using a function
void createHeapItem() {
	int* value = new int(19);
	ptr = value;
	cout << ptr << endl;
	cout << *ptr << endl;
}

int main() {
	createStackItem();
	cout << ptr << endl;
	cout << *ptr << endl; //supposedly you can't gain access to the value anymore, it would be deleted || but perhaps new ver they changed the concept

	createHeapItem();
	cout << ptr << endl;
	cout << *ptr << endl;
	
	delete ptr;
	cout << ptr << endl;  	//after some time, the pointer would only be deleted by the system because the pointer is in stack, which is handled by the system
	//cout << *ptr << endl; //as we can see, the object is fully deleted and we don't have access to it anymore

	ptr = new int[8]; //refers to a new array in heap
	ptr[0] = 9;
	cout << ptr[0] << endl;
	cout << ptr << endl;
	return 0;
}