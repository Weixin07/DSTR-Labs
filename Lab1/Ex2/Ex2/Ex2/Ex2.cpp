#include <iostream>
#include <string>

using namespace std;

int main() {

	int hours, minutes, seconds;
	char separator;

	cout << "Please input the elapse time (HH:MM:SS): ";
	cin >> hours >> separator >> minutes >> separator >> seconds;

	//Adding input validation
	if (hours < 0) {
		cout << "Please input a valid hour.";
	}
	else if (minutes < 0 || minutes >59) {
		cout << "Please input a valid minute.";
	}
	else if (seconds < 0 || seconds > 59) {
		cout << "Please input a valid second.";
	}
	else {
		cout << "Time format is correct.";

		int elapsedTime = (hours * 60 * 60) + (minutes * 60) + seconds;
		cout << "The elapsed time is " << elapsedTime << " seconds." << endl;
	}

	return 0;
}