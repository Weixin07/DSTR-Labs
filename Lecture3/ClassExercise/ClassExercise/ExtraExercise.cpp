#include <iostream>
using namespace std;

//function 1 - function passing by value
int summation(int a, int b) {
	int sum = a + b;

	return sum;
}

//function passing by pointer
void summation1(int* a, int* b, int* sum) {
	*sum = *a + *b;
}

int main() {
	int sum = 0;

	sum = summation(6, 7);
	cout << sum << endl;

	//--------------------------------------------------------------------------------------
	cout << "-----------------------" << endl;
	int a = 6;
	int b = 7;

	summation1(&a, &b, &sum);
	cout << sum << endl;

	return 0;
}

