//exercise 1: parenthesis balancing exercise using Array implementation

#include <iostream>
using namespace std;

class stack //using array
{
	//push, pop, isEmpty, peek, display
	char stack[100];
	int n = 100;
	int top = -1;

public:
	bool isEmpty() {
		if (top == -1) { 
			return true; 
		}
		else {
			return false;
		}
	}

	void push(char value){
		if (top >= n - 1) {
			cout << "Stack Overflow! Unable to use this stack to check the validity now." << endl;
		}
		else {
			top++; //indicate that there is something that should add on to the stack
			stack[top] = value;
		}
	}

	void pop() {
		if (isEmpty()) {
			cout << "Right parenthesis is more than left parenthesis. The equation is inbalance." << endl;
			exit(1);
		}

		cout << "Pop Value: " << stack[top] << endl;
		stack[top] = '\0'; //NULL in char
		top--;
	}


};

int main()
{
	stack s1;
	string equation = "";

	cout << "Enter an equation: " << endl;
	cin >> equation;

	//parenthese checking after get the equation from the user
	for (int i = 0; i < equation.length(); i++) {
		if (equation[i] == '(') {

			s1.push('(');
		}
		else { 
			s1.pop(); 
		}
	return 0;
	}

	if (s1.isEmpty()) {
		cout << "The equation is balaned!" << endl;
	}
	else {
		cout << "Left parenthesis looks like more than right parenthesis. Imbalance equation!" << endl;
	}

	return 0;
}