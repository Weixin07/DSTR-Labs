//exercise 2: parenthesis balancing exercise using linked list implementation

#include <iostream>
using namespace std;

class stack //using double linked list based stack
{
	struct stacknode
	{
		char character; //{
		stacknode* next;
		stacknode* previous;
	}*top, * bottom;

public:
	stack()
	{
		top = bottom = NULL;
	}

	//push, pop, isEmpty
	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}

	void push(char character)
	{
		stacknode* newnode = new stacknode;
		newnode->character = character;
		newnode->next = NULL;
		newnode->previous = NULL;

		if (top == NULL)
			top = bottom = newnode;
		else
		{
			newnode->next = top;
			top->previous = newnode;
			top = newnode;
		}
	}

	void pop()
	{
		if (isEmpty())
		{
			cout << "Right Parathesis looks like more than left parenthesis. Imbalance equation!" << endl;
			exit(1);
		}

		stacknode* current = top;
		top = top->next;

		if (top != NULL)
			top->previous = NULL;
		else
			bottom = NULL;

		delete current;
	}
};

int main()
{
	stack s1;
	string equation = "";

	cout << "Enter an equation: ";
	cin >> equation;

	//parenthese checking after get the equation from the user
	//((a+b(c)-g+((v-i))) - left parenthesis more
	//((a+b(c)-g+((v-i)))) - correct
	//((a+b(c)-g+((v-i))))) - right parenthesis more

	//read char by char in equation, if found left parenthesis, then push it, else if found right parenthesis, then pop it
	//for remaining chars, just ignore
	for (int i = 0; i < equation.length(); i++)
	{
		if (equation[i] == '(')
		{
			s1.push('(');
		}
		else if (equation[i] == ')')
		{
			s1.pop();
		}
	}

	//after read finish the equation
	if (s1.isEmpty())
	{
		cout << "The equation is balance! " << endl;
	}
	else //still find left parenthesis in the stack - means error
	{
		cout << "Left Parathesis looks like more than right parenthesis. Imbalance equation!" << endl;
	}
	return 0;
}