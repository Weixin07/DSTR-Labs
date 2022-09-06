#include <iostream>
using namespace std;

void updateEachColumnWith1(int * array1, int count) {
	for (int index = 0; index < count; index++) {
		array1[index] = array1[index] + 1;
	}
}

int main() {
	int colcount;
	int a[10]; //static array

	int count;
	cout << "Enter the amount of data you want to store in an array: ";
	cin >> count;

	//int a[count]; //invalid way to write a dynamic array
	int* array1 = new int[count]; //dynamic array to be saved in heap storage
	
	//how to read a data to a dynamic array
	for (int index = 0; index < count; index++) {
		cout << "Enter value " << index + 1 << ": ";
		//First method: Array indexting methond
		//cin >> array1[index];
		//Second method: Using pointer to access to each array content
		cin >> *(array1 + index);
	}

	//To display
	for (int index = 0; index < count; index++) {
		cout << array1[index] << ", ";
	}
	cout << endl;

	updateEachColumnWith1(array1, count); //function by passing using references/pointer
	for (int index = 0; index < count; index++) {
		cout << array1[index] << ", ";
	}

	return 0;
}