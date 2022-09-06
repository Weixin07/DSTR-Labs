#include <iostream>
using namespace std;

int main() {

	int num[10];
	int temporary;

	cout << "Enter 10 numbers: " << endl;

	for (int i = 0; i < size(num); i++) {
	
		cin >> temporary;

		if (temporary < 0 || temporary > 15) {
			cout << "Please input a number within 15.";
		}
		else {
			cin >> num[i];
		}

	cout << "The numbers in the array are:" << endl;

	for (int i = 0; i < size(num); i++) {
		cout << num[i] << ", ";
	}

	return 0;
}