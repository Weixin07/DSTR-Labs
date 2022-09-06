//here is the final code from me for duplicate number question.


#include <iostream>
using namespace std;



int main()
{
    //step 1: create 10 cols array
    int array1[10];

    //step 2: read the 10 values,
    for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
    {
        do
        {
            cout << "Enter value " << i + 1 << " : ";
            cin >> array1[i];
        } while (array1[i] < 1 || array1[i] > 15);



        for (int j = 0; j < i; j++)
        {
            //step 3: compare with the previous cols.. if the prev cols already have same number, so make give the true value in the array2
            if (array1[i] == array1[j] && i != 0)
            {
                i--;
                break;
            }
        }
    }



    //step 4: display only the values which is not the true answer in the array2.
    for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
    {
        cout << array1[i] << ", ";
    }



    return 0;
}