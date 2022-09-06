//Learning Outcome 1: learn how to insert node to front of list and how to insert to end of list based on user choice
//Learning Outcome 2: To get user input and put data to the single new node

#include <iostream>
#include <string>
using namespace std;

//ex1: build a structure for collecting the employee info:
//empID (employee123), empName, empSalary, empJobTitle
struct Employee {
	string empID;
	string empName;
	double empSalary;
	string empJobTitle;
	//Employee* previousAddress;
	Employee* nextAddress;
}*head, * current;// *next;

//insert into end of list
void insertToEnd(Employee* newNode) {
	if (head == NULL) {
		head = newNode;
	}
	else {
		current = head;
		
		while (current->nextAddress != NULL) { //finding the last node
			current = current->nextAddress;
		}

		current->nextAddress = newNode;
	}
}

//display function
void displayEmployeeInfo() {
	current = head;

	while (current != NULL) {
		cout << "Employee ID: " << current->empID << endl;
		cout << "Employee Name: " << current->empName << endl;
		cout << "Employee Salary: " << current->empSalary << endl;
		cout << "Employee Job Title: " << current->empJobTitle << endl;
		cout << endl;

		current = current->nextAddress;
	}

	cout << "This is the final list of our company employee." << endl << endl;
}

Employee* createNewNode(string EmpID, string Name, string JobTitle, double Salary) {
	Employee* newNode = new Employee; //empty struct
	newNode->empID = EmpID;
	newNode->empName = Name;
	newNode->empJobTitle = JobTitle;
	newNode->empSalary = Salary;
	newNode->nextAddress = NULL;

	return newNode;

}

//learning outcome 3: insert to front
void insertToFront(Employee* newNode) {
	if (head == NULL) {
		head = newNode;
	}
	else {
		newNode->nextAddress = head;
		head = newNode;
	}
}

int main() {
	//ALWAYS REMEMBER THIS FIRST STEP
	head = NULL;

	string EmpID, JobTitle, Name;
	double Salary;
	int decision = 1; //Repetition for user to put new employee info

	while (decision == 1) {
		cout << "Enter employee ID: ";
		cin >> EmpID;

		cin.ignore();
		cout << "Enter employee name: ";
		getline(cin, Name); //cin is for single words, getline is for multiple words (for eg, ahmad ali)

		cout << "Enter employee job title: ";
		getline(cin, JobTitle);

		cout << "Enter employee salary: ";
		cin >> Salary;

		//creating new node
		Employee* newNode = createNewNode(EmpID, Name, JobTitle, Salary); //returning address of new object in heap location
	
		//insertToEnd(newNode);
		insertToFront(newNode);

		cout << "Do you still want to create another employee profile in the system? 1: Yes, 2: No: ";
		cin >> decision;

		cout << endl;
	}

	cout << endl;
	displayEmployeeInfo();

	return 0;
}