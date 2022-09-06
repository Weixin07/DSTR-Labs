#include <iostream>
using namespace std;

int a = 9;

//Method 1 - Using pointers and functions to move data
void add1(int* p) {
	*p = *p + 1;
}

//Method 2 - Using functions only 
int add1withReturn(int p) {
	p = p + 1;
	return p;
}

int main()
{
	int a = 7;
	int* b = NULL;

	b = &a; //To get location of A

	
	cout << &a << endl; //displaying the memory address of A
	cout << b << endl; //displaying the memory address of A
	cout << &b << endl; //displaying the memory address of B
	cout << *b << endl;; //displaying the value stored in a, where b is appointed to point to

	b = &::a; //getting the address of global variable A instead (:: means gloabal)
	cout << *b << endl;
	cout << b << endl;

//-----------------------------------------------------------------------------------------------------------------------------------------------------
	cout << "------------------------------------------" << endl;

	int x = 9;
	int y = 10;

	int* pointer1 = &x; //x address
	int* pointer2 = &y; //y address

	cout << pointer1 << "-" << pointer2 << endl;
	cout << x << "-" << y << endl;

	pointer1 = pointer2; //save address of y into pointer 1 too

	cout << pointer1 << "-" << pointer2 << endl;

	*pointer1 = 56; //can change value of variable through pointer too
	cout << x << "-" << y << endl;

//----------------------------------------------------------------------------------------------------------------------------------------------------
	cout << "------------------------------------------------" << endl;

	//Passing p into a function
	//Method 1: using Pointers
	//Functions by referencing (by pointing and getting values)
	int p = 10;
	add1(&p); //function is at the top
	cout << p << endl;

	//Method 2: Using Returns (Not really relatable to this class, but only used as an example)
	//Functions by value (by copying the values)
	p = add1withReturn(p);
	cout << p << endl;

	return 0;
}

