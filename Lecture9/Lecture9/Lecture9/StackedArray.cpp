//Learn how to use array to implement stack concept
//Case Study: Arrange Student TP Number using Stack
#include <iostream>
using namespace std;

//create static array for stack - array with cols 100 spaces
string stack[100]; //tp01, tp02
int n = 100; //indexing, but the first always equals to 0, and last is 99

//top is the index number indicate which is the top
int top = -1; //start -1 because index start from 0 (which means -1 equals nothing)

bool isEmpty() //check whether the list is empty? - underflow?
{
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

void push(string value) { //tp01, tp02, tp03
    //check whether list is full ot not
    if (top >= n - 1) {
        cout << "Stack Overflow!" << endl;
    }
    else {
        top++; //indicate that there is something that should add on to the stack
        stack[top] = value;
    }
}

void pop() {
    //check whether list is empty
    if (isEmpty()) {
        cout << "Stack is underflow!" << endl;
        return;
    }
    
    cout << "Pop Value: " << stack[top] << endl;
    stack[top] = "";
    top--;

}

void displayitemsInStack()  //reverse printing in the array so that you can get the top to the bottom items
{
    if (isEmpty()) {
        cout << "Stack is empty and no item would be displayed." << endl;
        return;
    } 
    cout << "Stack item from top to bottom: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << ", ";
    }
    cout << endl;
}

void peek() //to read the top item in the stack without remove any thing
{
    if (top >= 0) {
        cout << "The top value is " << stack[top] << endl;
    }
}

int main()
{
    push("TP01"); 
    displayitemsInStack();
    cout << endl;

    push("TP02"); 
    displayitemsInStack();
    cout << endl;

    push("TP03"); 
    displayitemsInStack();
    cout << endl;

    pop(); 
    displayitemsInStack();
    cout << endl;

    peek(); 
    displayitemsInStack();
    cout << endl;
    
    pop(); 
    displayitemsInStack();
    cout << endl;

    push("TP04"); 
    displayitemsInStack();
    cout << endl;

    push("TP05"); 
    displayitemsInStack();
    cout << endl;

    push("TP03"); 
    displayitemsInStack();
    cout << endl;

    pop(); 
    displayitemsInStack();
    cout << endl;

    push("TP02");
    displayitemsInStack();
    cout << endl;

    return 0;
}