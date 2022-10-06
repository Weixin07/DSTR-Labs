//Ex1: Use double linked-list and class to make a stack and store the values in this question.
#include <iostream>
using namespace std;

class stack
{
    //Step 1: What node data field we need in this stack
    struct stacknode
    {
        string studentID; //data field
        stacknode* next;
        stacknode* previous;
    } *top, *bottom; //top = head, bottom = tail

public:
    //Step 2: We need to ensure top and bottom should start from NULL
    stack() { //constructor to define default value
        top = bottom = NULL; // whenever create a new stack object it will start from empty
    }

    //Step 3: We meed to set the push function - insert to the front
    void push(string studentID){
        //3.1 Create a new node
        stacknode* newnode = new stacknode;
        newnode->studentID = studentID;
        newnode->next = NULL;
        newnode->previous = NULL;

        //3.2 insert to the front
        if (top == NULL) {
            top = bottom = newnode;
        }
        else {
            newnode->next = top;
            top->previous = newnode;
            top = newnode;
        }
    }

    void pop() {

    }

    void displayitemsInStack() {

    }

    void peek()
    {

    }
};


int main()
{
    //create object stack and modify the below code:

    /*push("TP01");
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
    cout << endl;*/
    return 0;
}