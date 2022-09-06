#include <iostream>
#include <string>

using namespace std;

int main() {

	//To display
	cout << "Hello \t World!\n" << endl; //\t is to place a tab space, \n is to skip to next line, endl is to end the line.

	//To read input
	string name;
	cout << "Please input your name:";
	cin >> name;
	cout << "My name is " << name << endl;

	//Reading input but ignoring the spaces in between strings
	//cin.ignore() is only for numbers
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //if there's no max(), it will only ignore one space
	cout << "Please input your name:";
	getline(cin, name);
	cout << "My full name is " << name << endl;

	//To not immediately stop/give it a breathing moment (this is for vs only?)
	system("pause");

	//If Else
	int number = 14;
	if (number > 5 && number < 12) {
		cout << "The number is between 6 to 11. \n";
	}
	else {
		cout << "The number is out of the range of 6 to 11. \n";
	}

	if (number == 10 || number == 11) {
		cout << "The number is 10 or 11. \n";
	}
	else {
		cout << "hehe \n";
	}


	//Switch
	switch (number) {
	case 1:
		cout << "1";
		break;
	case 2:
		cout << "2";
		break;
	default:
		cout << "Not 1 nor 2.";
		//break is not neccessary as default is already the last statement
	}

	//For Loop
	for (int i = 0; i < number; i++) {
		cout << i << endl;
	}

	//While Loop
	int i = 1;
	while (i < number) {
		cout << i << endl;
		i++; //important to cout first so the index starts from 0 instead of 1
	}

	//Do-While Loop
	i = 0;
	do {
		cout << i << endl;
		i++;
	} while (i < number);

	return 0;
}

//The Usual Format:
//#include <iostream>

//using namespace std;

//int main() {

//	return 0;
//}