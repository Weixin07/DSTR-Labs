#include <iostream>
#include <string>
using namespace std;

struct Patient {
	int no;
	string patientName;
	string doctorName;
	string patientID;
	string sickness;
	string queueInTime;

	Patient* nextAddress;
}*head, * current;

void insertToFront(Patient* newNode) {
	if (head == NULL) {
		head = newNode;
	}
	else {
		newNode->nextAddress = head;
		head = newNode;
	}
}

void insertToEnd(Patient* newNode) {
	if (head == NULL) {
		head = newNode;
	}
	else {
		current = head;

		while (current->nextAddress != NULL) {
			current = current->nextAddress;
		}

		current->nextAddress = newNode;
	}
}

void displayPatientInfo() {
	current = head;
	cout << "No" << "-----" << "Patient" << "-----" << "Doctor" << "-----" << "Patient ID" << "-----" << "Sickness" << "-----" << "Queue in Time" << endl;

	while (current != NULL) {
		cout << current->no << "-----" << current->patientName << "-----" << current->doctorName << "-----" << current->patientID << "-----" << current->sickness << "-----" << current->queueInTime << endl;
		cout << endl;

		current = current->nextAddress;
	}
}

Patient* createNewNode(int No, string PatientName, string DoctorName, string PatientID, string Sickness, string QueueInTime) {
	Patient* newNode = new Patient;
	newNode->no = No;
	newNode->patientName = PatientName;
	newNode->doctorName = DoctorName;
	newNode->patientID = PatientID;
	newNode->sickness = Sickness;
	newNode->queueInTime = QueueInTime;
	newNode->nextAddress = NULL;

	return newNode;
}

void insertFirstThreeData() {
	Patient* newNode1 = new Patient;
	newNode1->no = 1;
	newNode1->patientName = "Ahmad Ali";
	newNode1->doctorName = "Dr.Lee Kim Kim";
	newNode1->patientID = "P123";
	newNode1->sickness = "Fever";
	newNode1->queueInTime = "9:00";
	newNode1->nextAddress = NULL;

	Patient* newNode2 = new Patient;
	newNode2->no = 2;
	newNode2->patientName = "Jessica Lim";
	newNode2->doctorName = "Dr.Rosmitah Nasli";
	newNode2->patientID = "P008";
	newNode2->sickness = "Fever, Cough";
	newNode2->queueInTime = "12:00";
	newNode2->nextAddress = NULL;

	Patient* newNode3 = new Patient;
	newNode3->no = 3;
	newNode3->patientName = "Kun Lim Cheng";
	newNode3->doctorName = "Dr.Rosmitah Nasli";
	newNode3->patientID = "P177";
	newNode3->sickness = "Stomachache";
	newNode3->queueInTime = "14:30";
	newNode3->nextAddress = NULL;

	insertToEnd(newNode1);
	insertToEnd(newNode2);
	insertToEnd(newNode3);
}

int main() {
	head = NULL;
	insertFirstThreeData();

	int No;
	string PatientID, PatientName, DoctorName, Sickness, QueueInTime;
	int decision = 1;

	while (decision == 1) {
		cout << "Enter No: ";
		cin >> No;

		cout << "Enter Patient ID: ";
		cin >> PatientID;

		cin.ignore();
		cout << "Enter Patient Name: ";
		getline(cin, PatientName); 

		cout << "Enter Doctor Name: ";
		getline(cin, DoctorName);

		cout << "Enter Sickness: ";
		getline(cin, Sickness);

		cout << "Enter Queue in Time: ";
		cin >> QueueInTime;

		Patient* newNode = createNewNode(No, PatientID, PatientName, DoctorName, Sickness, QueueInTime); 

		//insertToEnd(newNode);
		insertToFront(newNode);

		cout << "Do you still want to create another employee profile in the system? 1: Yes, 2: No: ";
		cin >> decision;

		cout << endl;
	}

	cout << endl;
	displayPatientInfo();

	return 0;
}