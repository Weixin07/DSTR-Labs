#include <iostream>
using namespace std;


int main() {
	int billy[] = { 16,2,77,40,12071,51 };
	
	int n = size(billy);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		cout << billy[i] << " + ";
		sum += billy[i];
	}

	cout << " is " << sum;

	return 0;
}