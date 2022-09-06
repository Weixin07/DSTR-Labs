#include <iostream>
#include <cstdlib>

using namespace std;

extern int startingNo = 1;
extern int endingNo = 100;
extern int answerInput = 0;
//extern int correctAnswer;

void pickAnswer() {
	int correctAnswer;

	for (int index = 0; index < 1; index++) {
		correctAnswer = (rand() % 100) + 1;
		cout << correctAnswer << endl;
	}
}

void topicDisplay() {
	cout << "Guess a number between " << startingNo << " to " << endingNo << "." << endl;
}

void answer() {
	int a, b = 0;

	cout << "Your answer: ";
	cin >> answerInput;

	a = answerInput - startingNo;
	b = endingNo - answerInput;

	//cout << a << b;

	if (answerInput > startingNo || answerInput < endingNo) {

		cout << "Please enter a number between " << startingNo << " to " << endingNo << "." << endl;
		
	}
	else {
		if (a > b) {
			if (answerInput > startingNo) {
				if (answerInput < endingNo) {
					startingNo = answerInput;
				}
			}
		}
		else {
			if (answerInput > startingNo) {
				if (answerInput < endingNo) {
					endingNo = answerInput;
				}
			}
		}
	}


}

int main() {
	cout << "Guess Number Game Started Now!" << endl << "----------------------------------------------" << endl;

	pickAnswer();
	topicDisplay();
	answer();
	//topicDisplay();
	//cout << correctAnswer;

	return 0;
}