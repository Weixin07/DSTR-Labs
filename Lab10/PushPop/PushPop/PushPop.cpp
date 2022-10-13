#include <iostream>
#include <string>
using namespace std;

struct stacknode
{
	char character;
	stacknode* next;
	stacknode* previous;
} *top, * bottom;

stacknode* createnode(char character) { //* / + - ^
	stacknode* newnode = new stacknode;
	newnode->character = character;
	newnode->next = NULL;
	newnode->previous = NULL;
	return newnode;
}

void push(char character) {
//call the createnode()
	stacknode* newnode = createnode(character);

	//push to the stack
	if (top == NULL)
		top = bottom = newnode;
	else {
		newnode->next = top;
		top->previous = newnode;
		top = newnode;
	}
}

void pop(){ //delete from front, display the +/-*^ to the postfix equation
	if (top == NULL)
		return;

	stacknode* temp = top;
	top = top->next;

	if (top == NULL) //break the connection between last item and its previous item
		bottom = NULL;
	else {
		top->previous = NULL;
	}

	//delete
	if(temp->character != '(') //for operator +/-*^ to display, but ignore to display if we meet '('
		cout << temp->character;

	delete temp;
}

//for the right parenthesis to work for popping the overall operators from the stack, until meet the '(' and stop the pop function
void checkleftparenthesis() {
	stacknode* temp = top;

	while (temp != NULL && temp->character != '(') { // stop the loop until meet the left '('
		pop();
		temp = top;
	}
	pop(); //then do the last pop function to remove the '('
}


int main()
{
	//stack should start from empty
	top = bottom = NULL;

	string equation = "";
	cout << "Enter your infix equation here: ";
	cin >> equation;

	//display the postfix equation
	cout << endl;
	cout << "The postfix equation for " << equation << " is ";

	//use for loop read 1 by 1 char and convert them
	for (int i = 0; i < equation.length(); i++) {
	//situation 1: if meet A-Z,l a-z, just display to the screen
		if ((equation[i] >= 'A' && equation[i] <= 'Z') ||(equation[i] >= 'a' && equation[i] <= 'z')) {
			cout << equation[i];
		}
		//situation 2: if char = '(', then push to the stack directly
		else if (equation[i] == '(') {
			push(equation[i]);
		}
		//situation 3: if char = ')', then call the checkleftparenthesis() that we have
		else if (equation[i] == ')') {
			checkleftparenthesis();
		}
		//situation 4: + - 
		else if (equation[i] == '+' || equation[i] == '-') { //low priority
			while (top != NULL) {
				if (top->character == '/' || top->character == '*' || top->character == '^' || top->character == '+' || top->character == '-') {
					pop();
				}
				else {
					break;
				}
			}
			push(equation[i]);
		}
		//situation 5: / * ^
		else if (equation[i] == '/'|| equation[i] == '*'){//medium priority
			while (top != NULL) {
				if (top->character == '/' || top->character == '*' || top->character == '^') {
					pop();
				}
				else {
					break;
				}
			}
			push(equation[i]);
		}
		else {//high priority
			while (top != NULL) {
				if ( top->character == '^') {
					pop();
				}
				else {
					break;
				}
			}
			push(equation[i]);
		}
	}

	//before end, make sure all the stack items already pop out and display
	while(top != NULL) {
		pop();
	}









	return 0;
}
