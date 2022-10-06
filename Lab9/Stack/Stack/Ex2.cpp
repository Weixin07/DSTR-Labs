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

    int stackID;

public:
    //Step 2: We need to ensure top and bottom should start from NULL
    stack(int ID) { //constructor to define default value
        top = bottom = NULL; // whenever create a new stack object it will start from empty
        stackID = ID;
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

    //Step 4: Delete from the front of list
    void pop() {
        //4.1 Check if the stack is empty or not
        if (top == NULL) {
            cout << "Stack is underflow! Unable to delete!" << endl;
            return;
        }

        //4.2 declare a new current pointer
        stacknode* current = top;
        top = top->next;

        //4.3 Check whether top is equal to NULL
        if (top != NULL)
            top->previous = NULL;
        else
            bottom = NULL;

        //4.4 delete the current item
        cout << "Pop: Item " << current->studentID << endl;
        delete current;
    }

    void displayitemsInStack() {
        //delete from top to bottom
        stacknode* current = top;

        cout << "Stack: " << stackID << endl;
        while (current != NULL) {
            cout << current->studentID << ", ";
            current=current->next;
        }
        cout << endl;
    }
    
    //To view the latest top value without removing it. only view it
    void peek()
    {
        stacknode* current = top;
        cout << "Top value: " << current->studentID << endl;
    }
};


int main()
{
    //create object stack and modify the below code:
    stack stack1(1);
    stack stack2(2);

    stack1.push("TP01");
    stack1.displayitemsInStack();
    cout << endl;

    stack1.push("TP02");
    stack1.displayitemsInStack();
    cout << endl;

    stack1.push("TP03");
    stack1.displayitemsInStack();
    cout << endl;

    stack1.pop();
    stack1.displayitemsInStack();
    cout << endl;

    stack1.peek();
    cout << endl;

    stack1.pop();
    stack1.displayitemsInStack();
    cout << endl;

    stack1.push("TP04");
    stack1.displayitemsInStack();
    cout << endl;

    stack1.push("TP05");
    stack1.displayitemsInStack();
    cout << endl;

    stack1.push("TP03");
    stack1.displayitemsInStack();
    cout << endl;

    stack1.pop();
    stack1.displayitemsInStack();
    cout << endl;

    stack1.push("TP02");
    stack1.displayitemsInStack();
    cout << endl;

    stack2.push("TP11");
    stack2.displayitemsInStack();
    cout << endl;

    stack2.push("TP12");
    stack2.displayitemsInStack();
    cout << endl;

    stack2.pop();
    stack2.displayitemsInStack();
    cout << endl;

    return 0;
}