#include <iostream>
using namespace std;

int sizeOfLinkedList = 0;

struct songs
{
	int no;
	string artist;
	string songName;
	int yearReleased;
	string genre;
	double songLength;

	songs* nextAddress;
}*head, * tail;

struct songs1
{
	int no1;
	string artist1;
	string songName1;
	int yearReleased1;
	string genre1;
	double songLength1;

	songs1* nextAddress1;
}*head1, * tail1;

songs* createNewNode(int no, string artist, string songName, int yearReleased, string genre, double songLength) {
	songs* newNode = new songs;
	newNode->no = no;
	newNode->artist = artist;
	newNode->songName = songName;
	newNode->yearReleased = yearReleased;
	newNode->genre = genre;
	newNode->songLength = songLength;
	newNode->nextAddress = NULL;

	return newNode;
}

songs1* createNewNode1(int no1, string artist1, string songName1, int yearReleased1, string genre1, double songLength1) {
	songs1* newNode = new songs1;
	newNode->no1 = no1;
	newNode->artist1 = artist1;
	newNode->songName1 = songName1;
	newNode->yearReleased1 = yearReleased1;
	newNode->genre1 = genre1;
	newNode->songLength1 = songLength1;
	newNode->nextAddress1 = NULL;

	return newNode;
}

void viewList() {
	songs* current = head;

	while (current != NULL) {
		cout << "No - Artist - Song - Released - Genre - Length" << endl;
		cout << current->no << " - " << current->artist << " - " << current->songName << " - " << current->yearReleased << " - " << current->genre << " - " << current->songLength << endl;
		current = current->nextAddress;
	}

	cout << "End of List!" << endl << endl;
}

void viewSortedList() {
	songs1* current = head1;

	while (current != NULL) {
		cout << "No - Artist - Song - Released - Genre - Length" << endl;
		cout << current->no1 << " - " << current->artist1 << " - " << current->songName1 << " - " << current->yearReleased1 << " - " << current->genre1 << " - " << current->songLength1 << endl;
		current = current->nextAddress1;
	}

	cout << "End of List!" << endl << endl;
}

void insertIntoSpecificLocation(int no, string artist, string songName, int yearReleased, string genre, double songLength, int chosenPosition = 1) {
	songs* newNode = createNewNode(no, artist, songName, yearReleased, genre, songLength);

	if (head == NULL) {
		head = tail = newNode; 
	}
	else if (chosenPosition <= 1) {
		newNode->nextAddress = head;
		head = newNode;
	}
	else if (chosenPosition > sizeOfLinkedList) {
		tail->nextAddress = newNode;
		tail = newNode;
	}
	else {
		songs* current = head->nextAddress;
		songs* previous = head;

		int currentPointerIndex = 2;

		while (chosenPosition != currentPointerIndex) {
			previous = current;
			current = current->nextAddress;
			currentPointerIndex++;
		}
		previous->nextAddress = newNode;
		newNode->nextAddress = current;
	}
	::sizeOfLinkedList++;
}

void insertIntoSortedList(int no1, string artist1, string songName1, int yearReleased1, string genre1, double songLength1) {
	songs1* newNode = createNewNode1(no1, artist1, songName1, yearReleased1, genre1, songLength1);

	if (head1 == NULL) {
		head1 = newNode;
	}
	else if (newNode->yearReleased1 <= head1->yearReleased1) {
		newNode->nextAddress1 = head1;
		head1 = newNode;
	}
	else {
		songs1* current = head1->nextAddress1;
		songs1* previous = head1;

		while (current != NULL) {
			if (newNode->yearReleased1 <= current->yearReleased1) {
				break;
			}
			previous = current;
			current = current->nextAddress1;
		}
		previous->nextAddress1 = newNode;
		newNode->nextAddress1 = current;
	}
}

void deleteFromEnd()
{
	songs* current = head;

	if (head == NULL) {
		cout << "The list is still empty!" << endl;
		return;
	}

	current = head;
	songs* previous = NULL;

	while (current->nextAddress != NULL)
	{
		previous = current;
		current = current->nextAddress;
	}

	if (previous != NULL) {
		previous->nextAddress = NULL;
		tail = previous;;
	}
	else {
		head = tail = NULL;
	}
	cout << "The deleted value is " << current->no << endl;
	delete current;
}

int main() {
	head = tail = NULL;

	insertIntoSpecificLocation(3, "The Cranberries", "Promises", 1999, "Rock", 4.30);
	insertIntoSpecificLocation(2, "Taylor Swift", "You Belong with Me", 2008, "Pop", 3.48);
	insertIntoSpecificLocation(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58);
	insertIntoSpecificLocation(4, "Maria Carey", "All I Want For Christmas Is You", 1994, "Seasonal", 3.55, 1);
	insertIntoSpecificLocation(5, "Selena Fomez, Kygo", "It Ain't Me", 2017, "Dance-Pop", 3.41, ::sizeOfLinkedList+1);
	insertIntoSpecificLocation(6, "Bruno Mars", "Just The Ay You Are", 2010, "Pop", 3.42, 3);
	insertIntoSpecificLocation(7, "Selena Gomez, BlackPink", "Ice Cream", 2020, "Pop", 2.56, 5);
	insertIntoSpecificLocation(8, "Britney Spears", "Toxic", 2003, "Dance", 3.19, 7);

	viewList();
	cout << "The size of linked list is " << ::sizeOfLinkedList << "." << endl << endl;

	insertIntoSortedList(3, "The Cranberries", "Promises", 1999, "Rock", 4.30);
	insertIntoSortedList(2, "Taylor Swift", "You Belong with Me", 2008, "Pop", 3.48);
	insertIntoSortedList(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58);
	insertIntoSortedList(4, "Maria Carey", "All I Want For Christmas Is You", 1994, "Seasonal", 3.55);
	insertIntoSortedList(5, "Selena Fomez, Kygo", "It Ain't Me", 2017, "Dance-Pop", 3.41);
	insertIntoSortedList(6, "Bruno Mars", "Just The Ay You Are", 2010, "Pop", 3.42);
	insertIntoSortedList(7, "Selena Gomez, BlackPink", "Ice Cream", 2020, "Pop", 2.56);
	insertIntoSortedList(8, "Britney Spears", "Toxic", 2003, "Dance", 3.19);

	viewSortedList();

	while (head != NULL) {
		deleteFromEnd();
	}

	viewList();

	return 0;
}

