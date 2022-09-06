#include <iostream>
using namespace std;

int main()
{

	int billy[] = { 16,2,77,40,12071,51 };

	int n = size(billy);
	int i, j;
	int temp;

	//to sort
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (billy[i] > billy[j])
			{
				temp = billy[i];
				billy[i] = billy[j];
				billy[j] = temp;
			}
		}
	}

	//display
	cout << "Sorted numbers:" << endl;

	for (i = 0; i < n; i++)
		if (i == n - 1) {
			cout << billy[i];
		}
		else {
			cout << billy[i] << ", ";
		}

	cout << endl;


	return 0;

}