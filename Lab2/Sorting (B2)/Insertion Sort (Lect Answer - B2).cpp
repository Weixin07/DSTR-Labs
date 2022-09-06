/******************************************************************************

							  Online C++ Compiler.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	//output: arrange become ascending order with the example answer
	//final answer e.g. 2, 3, 16, 40, 51, 55, 66, 77, 12071
	//can search any of the sort algorithm to arrange them

	int billy[] = { 2, 3, 16, 77, 40, 12071, 51,  55, 66 }; //make it dynamic
	int temp = 0;
	int roundNumber = 1;
	int length = sizeof(billy) / sizeof(int);

	for (int index = 1; index < length; index++)
	{
		int key = billy[index];//take value
		int previndex = index;
		while (previndex > 0 && billy[previndex - 1] > key)
		{
			billy[previndex] = billy[previndex - 1];
			previndex--;
		}
		billy[previndex] = key;
		roundNumber++;
	}

	for (int index = 0; index < length; index++)
	{
		if (index != length - 1)
			cout << billy[index] << " , ";
		else
			cout << billy[index] << endl;
	}
	cout << endl << "This data set using bubble sort to sort in how many round? " << roundNumber << endl << endl;
	return 0;
}
