#include <iostream>
using namespace std;

int main() {
	int hours, minutes, seconds, decision = 0;
	char separator1, separator2;

	do {
		cout << "Please enter your elapsed time (HH:MM:SS format): ";
		cin >> hours >> separator1 >> minutes >> separator2 >> seconds;

		while (cin.fail() || hours < 0 || minutes < 0 || minutes > 60 || seconds < 0 || seconds > 60 || separator1 != ':' || separator2 != ':') {
			cin.clear(); //remove the input operation
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!" << endl;
			cout << "Please enter your elapsed time (HH:MM:SS format): ";
			cin >> hours >> separator1 >> minutes >> separator2 >> seconds;
		}

		int ElapsedTime = ( hours * 60 * 60 ) + ( minutes * 60) + seconds;
		cout << "Elapsed time is: " << ElapsedTime << " seconds." << endl;

		cout << endl << "Do you want to reset the time? 1: Yes, Others: No" << endl;
		cin >> decision;
	} while (decision == 1);

	return 0;
}