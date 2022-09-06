#include <iostream>
using namespace std;

int main()
{
	int numbers[5];
	int n = 5;
	int i;

	for (i = 0; i < n; i++)
	{
		cout << "Enter your number " << i + 1 << ": ";
		cin >> numbers[i];
	}

	int sum = 0;

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << numbers[i] << " = ";
		}
		else {
			cout << numbers[i] << " + ";
		}
		sum += numbers[i];
	}

	cout << sum;

	return 0;

}