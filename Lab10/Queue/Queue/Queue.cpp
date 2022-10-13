#include <iostream>
using namespace std;
string queue[100]; int n = 100, frontindex = -1, rearindex = -1;

bool isEmpty() {
    if (frontindex == -1 || frontindex > rearindex) {
        return true;
    }
    return false;
}

void enqueue(string data) { //add to the end of array - rear move when enqueue
    //whether queue is full tank or not
    if (rearindex == n - 1) { //100 columns, index until 99 (100-1)
        cout << "Queue already full." << endl;
        return;
    }
    rearindex++;

    if (frontindex == -1) {
        frontindex = 0;
    }

    queue[rearindex] = data;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty now!" << endl;
        return;
    }

    cout << "Deleted item: " << queue[frontindex] << endl;
    queue[frontindex] = "\0";
    frontindex++;
}

void Display() {
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue items now is: ";

    for (int i = frontindex; i <= rearindex; i++) {
        cout << queue[i] << ", ";
    }
    cout << endl;
}

int main()
{
    enqueue("Ahmad"); enqueue("Ali");
    enqueue("James"); dequeue(); dequeue();
    enqueue("Mary"); dequeue(); enqueue("Gloria");
    enqueue("Peter");

    Display();
    return 0;
}