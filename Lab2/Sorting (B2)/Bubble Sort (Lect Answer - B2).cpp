#include <iostream>

using namespace std;

int main()
{
	//output: arrange become ascending order with the example answer
	//final answer e.g. 2, 3, 16, 40, 51, 55, 66, 77, 12071
	//can search any of the sort algorithm to arrange them

	//Bubble Sort Algorithm:
	// 1. declare a variable named "temp" for swapping purpose
	// 2. declare a boolean variables to determine when should stop the loop (stop the loop when all numbers in correct order)
	// 3. set boolean variable to true (assume all in correct order)
	// 4. swap the billy's values
	// 		4.1 use first loop to determine the round time (while)
	//      4.2 use another loop to compare the current read value with the next value (for)
	//		4.3 if current read value more than next value, swap both of them and set the boolean variable to false 
	//			(false means not in correct order)
	//		4.4 if boolean variable is equals to true, stop the loop using break
	//      4.5 reset the boolean variable to become true again
	// 5. Last, display all numbers in ascending order
	
	int billy[] = { 2 , 3 , 16 , 40 , 51 , 55 , 66 , 77 , 12071 }; //make it dynamic
	int temp = 0;
	bool stopLoopAnswer = true;
	int roundNumber = 1;

	while (true) //dont know when should stop?
	{
		for (int index = 0; index < size(billy) - 1; index++) //until last second element
		{
			if (billy[index] > billy[index + 1]) //4 > 3
			{
				temp = billy[index + 1]; //temp = 3 
				billy[index + 1] = billy[index]; //next value 3 replaced by 4
				billy[index] = temp; //current value 4 replaced by 3 using temp value
				stopLoopAnswer = false;
			}
		}

		if (stopLoopAnswer == true) //confirm to stop the bubble loop or not
		{
			break;
		}
		stopLoopAnswer = true;
		roundNumber++;
	}

	for (int index = 0; index < size(billy); index++) //until last elements
	{
		if (index != size(billy) - 1)
			cout << billy[index] << " , ";
		else
			cout << billy[index] << endl;
	}
	cout << endl << "This data set using bubble sort to sort in how many round? " << roundNumber << endl << endl;
	return 0;
}