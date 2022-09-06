#include <iostream>
using namespace std;

int sumValues(int billy[], int n) {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += billy[i];
	}

	return sum;
}

string determinePlusEqualSign(int billy[], int n) {
	string plusOrEqual;

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			plusOrEqual = " = ";
		}
		else {
			plusOrEqual = " + ";
		}
	}

	return plusOrEqual;
}

void displaySentence(string plusOrEqual) {
	int billy[] = { 16,2,77,40,12071,51 };
	int n = size(billy);

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << billy[i] << plusOrEqual;
		}
		else {
			cout << billy[i] << plusOrEqual;
		}
	}
}

int main() {
	int billy[] = { 16,2,77,40,12071,51 };
	int n = size(billy);

	displaySentence(determinePlusEqualSign(billy, n));

	cout << sumValues(billy, n);

	return 0;
}


