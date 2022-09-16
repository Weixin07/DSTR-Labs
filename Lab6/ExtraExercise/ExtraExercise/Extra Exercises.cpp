#include <iostream>
#include <string>
using namespace std;

int sizeOfLinkedList = 0;
int sizeOfSortedLinkedList = 0;

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

struct sortedSongs
{
	int noOfSorted;
	string artistOfSorted;
	string songNameOfSorted;
	int yearReleasedOfSorted;
	string genreOfSorted;
	double songLengthOfSorted;

	sortedSongs* nextAddressOfSorted;
}*headOfSorted, * tailOfSorted;

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

sortedSongs* createSortedNewNode() {
	songs* current = head;
	sortedSongs* newNodeOfSorted = new sortedSongs;

	while (current != NULL) {
		newNodeOfSorted->noOfSorted = current->no;
		newNodeOfSorted->artistOfSorted = current->artist;
		newNodeOfSorted->songNameOfSorted = current->songName;
		newNodeOfSorted->yearReleasedOfSorted = current->yearReleased;
		newNodeOfSorted->genreOfSorted = current->genre;
		newNodeOfSorted->songLengthOfSorted = current->songLength;
		newNodeOfSorted->nextAddressOfSorted = NULL;
	}

	return newNodeOfSorted;
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

void gettingDataFromSongs() {
	songs* current = head;

	while (current != NULL) {
		cout << current->no << " - " << current->artist << " - " << current->songName << " - " << current->yearReleased << " - " << current->genre << " - " << current->songLength << endl;
		current = current->nextAddress;
	}

	cout << "End of List!" << endl << endl;
}

void viewSortedList() {
	sortedSongs* current = headOfSorted;

	while (current != NULL) {
		cout << "No - Artist - Song - Released - Genre - Length" << endl;
		cout << current->no << " - " << current->artist << " - " << current->songName << " - " << current->yearReleased << " - " << current->genre << " - " << current->songLength << endl;
		current = current->nextAddress;
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

void insertIntoSortedList()
{
	head = tail = NULL;
	int noOfSorted = 0;
	string artistOfSorted;
	string songNameOfSorted;
	int yearReleasedOfSorted = 0;
	string genreOfSorted;
	double songLengthOfSorted = 0.0;

	sortedSongs* newNodeOfSorted = createSortedNewNode();

	if (headOfSorted == NULL)
	{
		headOfSorted = newNodeOfSorted;
	}
	else if (newNodeOfSorted->yearReleasedOfSorted <= headOfSorted->yearReleasedOfSorted)
	{
		newNodeOfSorted->nextAddressOfSorted = headOfSorted;
		headOfSorted = newNodeOfSorted;
	}
	else
	{
		sortedSongs* currentOfSorted = headOfSorted->nextAddressOfSorted;
		sortedSongs* prevOfSorted = headOfSorted;

		while (currentOfSorted != NULL)
		{
			if (newNodeOfSorted->yearReleasedOfSorted <= currentOfSorted->yearReleasedOfSorted)
			{
				break; 
			}
			prevOfSorted = currentOfSorted;
			currentOfSorted = currentOfSorted->nextAddressOfSorted;
		}
		prevOfSorted->nextAddressOfSorted = newNodeOfSorted;
		newNodeOfSorted->nextAddressOfSorted = currentOfSorted;
	}

	::sizeOfSortedLinkedList++;

	sortedSongs* currentOfSorted = headOfSorted;

	while (currentOfSorted != NULL) {
		cout << "No - Artist - Song - Released - Genre - Length" << endl;
		cout << currentOfSorted->noOfSorted << " - " << currentOfSorted->artistOfSorted << " - " << currentOfSorted->songNameOfSorted << " - " << currentOfSorted->yearReleasedOfSorted << " - " << currentOfSorted->genreOfSorted << " - " << currentOfSorted->songLengthOfSorted << endl;
		currentOfSorted = currentOfSorted->nextAddressOfSorted;
	}

	cout << "End of List!" << endl << endl;
}

void deleteFromFrontOfList() {
	if (head == NULL) {
		cout << "Underflow happened here! Do not delete anything from this this!" << endl;
		return;
	}
	songs* current = head;
	head = head->nextAddress;

	if (head == NULL) {
		tail = NULL;
	}

	cout << "Deleted Song No: " << current->no << endl;
	delete current;

	::sizeOfLinkedList--;
}

int main() {
	head = tail = NULL;
	int position = 1;
	int no = 3;
	string artist;
	string songName;
	int yearReleased;
	string genre;
	double songLength;

	insertIntoSpecificLocation(3, "The Cranberries", "Promises", 1999, "Rock", 4.30);
	insertIntoSpecificLocation(2, "Taylor Swift", "You Belong with Me", 2008, "Pop", 3.48);
	insertIntoSpecificLocation(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58);
	insertIntoSpecificLocation(4, "Maria Carey", "All I Want For Christmas Is You", 1994, "Seasonal", 3.55, 1);
	insertIntoSpecificLocation(5, "Selena Fomez, Kygo", "It Ain't Me", 2017, "Dance-Pop", 3.41, ::sizeOfLinkedList+1);
	insertIntoSpecificLocation(6, "Bruno Mars", "Just The Ay You Are", 2010, "Pop", 3.42, 3);
	insertIntoSpecificLocation(7, "Selena Gomez, BlackPink", "Ice Cream", 2020, "Pop", 2.56, 5);
	insertIntoSpecificLocation(8, "Britney Spears", "Toxic", 2003, "Dance", 3.19, 7);

	/*
	int decision = 1;
	while (decision != 0)
	{
		no++;
		cout << "Enter the artist name: ";
		getline(cin, artist);
		cout << "Enter the song name: ";
		getline(cin, songName);
		cout << "Enter the Year Released: ";
		cin >> yearReleased;
		cout << "Enter the genre: ";
		cin >> genre;
		cout << "Enter the song length: ";
		cin >> songLength;
		cout << "Which location would you like to place the Song No of " << no << "? Range between 1 - " << ::sizeOfLinkedList + 1 << " : ";
		cin >> position;
		insertIntoSpecificLocation(no, artist, songName, yearReleased, genre, songLength, position);
		cout << endl;
		cout << "Would you like to add a song? Type: 1 for Yes, 0 for No. \n";
		cin >> decision;
		cin.ignore();
		cout << endl;
	}
	*/

	viewList();

	insertIntoSortedList();

	cout << "The size of linked list is " << ::sizeOfLinkedList << "." << endl << endl;

	//while (head != NULL) {
	//	deleteFromFrontOfList();
	//}

	//viewList();

	//cout << "The size of linked list is " << ::sizeOfLinkedList << "." << endl << endl;

	return 0;
}

