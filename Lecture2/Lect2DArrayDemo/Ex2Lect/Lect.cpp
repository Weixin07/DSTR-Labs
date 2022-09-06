#include <iostream>
using namespace std;

int main() {
	//Declare a 2D array
	string flowerinfo[3][4]; //3 flowers - id, name, type, color

	//reading in (input) data
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 4; col++) {
			cout << "Enter flower details: " << col << ": ";
			cin >> flowerinfo[row][col];
		}
	}

	//DIsplaying out data
	for (int row = 0; row < 3; row++) {
		cout << endl;
		cout << flowerinfo[row][0] << " - " << flowerinfo[row][1] << " - ";
		cout << flowerinfo[row][2] << " - " << flowerinfo[row][3];
		cout << endl;
	}

	return 0;
}