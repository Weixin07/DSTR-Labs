//Exercise 1: Read N number of the random number (bet 1 - 100)
//from the system and store in a dynamic array
//
//to get the random number: 
//#include <cstdlib>
//#include <ctime>
//srand(time(NULL)); -> for make sure everytime has differ random number based on time stream
//(rand() % 100) + 1; -> formula to get the random number between 1 - 100.
//
//Exercise 2: after done exercise 1, use the random number to determine 
//which number(s) is/are belongs to even number that drop in the range between 20 - 30 , 
//and display how many of them
//e.g.1 => 2,55, 23, 12,33 - final result = 0 items
//e.g.2 => 22, 24, 25, 26, 31 - final result = 3 items

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int count;
	cout << "Enter the amount of data you want to store in an array: ";
	cin >> count;

	int* array1 = new int[count];
	int* arrayFor2030 = new int[count];

	srand(time(NULL));
	for (int index = 0; index < count; index++) {
		int b;

		b = (rand() % 100) + 1;
		
		*(array1 + index) = b;
	}

	for (int index = 0; index < count; index++) {
		cout << array1[index] << ", ";
	}
	cout << endl;

	//Q2
	cout << "The random number drop in between 20 ~ 30 are: ";
	int count1 = 0;

	for (int index = 0; index < count; index++) {
		if ((array1[index] % 2 == 0) && (array1[index]>=20) && (array1[index] <= 30)) {
			cout << array1[index] << ", ";
			count1++;
		}
	}
	cout << endl;
	cout << "THe final random number dropped in the bet 20~30 is " << count1 << endl;

	return 0;
}