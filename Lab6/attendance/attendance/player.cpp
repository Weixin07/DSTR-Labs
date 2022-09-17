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

	cout << "No - Artist - Song - Released - Genre - Length" << endl;

	while (current != NULL) {
		cout << current->no << " - " << current->artist << " - " << current->songName << " - " << current->yearReleased << " - " << current->genre << " - " << current->songLength << endl;
		current = current->nextAddress;
	}

	cout << "End of List!" << endl << endl;
}

void viewSortedList() {
	songs1* current = head1;

	cout << "No - Artist - Song - Released - Genre - Length" << endl;

	while (current != NULL) {
		cout << current->no1 << " - " << current->artist1 << " - " << current->songName1 << " - " << current->yearReleased1 << " - " << current->genre1 << " - " << current->songLength1 << endl;
		current = current->nextAddress1;
	}

	cout << "End of List!" << endl << endl;
}

void insertToFront(int no, string artist, string songName, int yearReleased, string genre, double songLength) {
	songs* newNode = createNewNode(no, artist, songName, yearReleased, genre, songLength);
	songs* current = head;

	if (head == NULL) {
		head = newNode;
	}
	else {
		newNode->nextAddress = head;
		head = newNode;
	}
	::sizeOfLinkedList++;
}

void insertToEnd(int no, string artist, string songName, int yearReleased, string genre, double songLength) {
	songs* newNode = createNewNode(no, artist, songName, yearReleased, genre, songLength);
	songs* current = head;

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
	::sizeOfLinkedList++;
}

void insertToFront1(int no1, string artist1, string songName1, int yearReleased1, string genre1, double songLength1) {
	songs1* newNode1 = createNewNode1(no1, artist1, songName1, yearReleased1, genre1, songLength1);
	songs1* current1 = head1;

	if (head1 == NULL) {
		head1 = newNode1;
	}
	else {
		newNode1->nextAddress1 = head1;
		head1 = newNode1;
	}
}

void insertToEnd1(int no1, string artist1, string songName1, int yearReleased1, string genre1, double songLength1) {
	songs1* newNode1 = createNewNode1(no1, artist1, songName1, yearReleased1, genre1, songLength1);
	songs1* current1 = head1;

	if (head1 == NULL) {
		head1 = newNode1;
	}
	else {
		current1 = head1;

		while (current1->nextAddress1 != NULL) {
			current1 = current1->nextAddress1;
		}

		current1->nextAddress1 = newNode1;
	}
}

void deleteFromFront() {
	if (head == NULL) {
		cout << "Underflow happened here! Do not delete anything from this this!" << endl;
		return;
	}
	songs* current = head;
	head = head->nextAddress;

	if (head == NULL) {
		tail = NULL;
	}

	cout << "Deleted Song ID: " << current->no << endl;
	delete current;

	::sizeOfLinkedList--;
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
	cout << "Deleted Song ID: " << current->no << endl;
	delete current;
}

void deleteWithArtist(string artist)
{
	songs* current = head;

	if (head == NULL)
	{
		cout << "Sorry list is empty." << endl;
		return;
	}
	else
	{
		current = head->nextAddress; 
		songs* previous = head; 

		while (current != NULL)
		{
			if (artist == current->artist)
			{
				previous->nextAddress = current->nextAddress;
				cout << "Deleted Song ID : " << current->no << endl;
				delete current;
				break;
			}
			previous = current;
			current = current->nextAddress;
		}
	}
	::sizeOfLinkedList--;
}

void deleteWithSongNo(int no)
{
	songs* current = head;

	if (head == NULL)
	{
		cout << "Sorry list is empty." << endl;
		return;
	}
	else
	{
		current = head->nextAddress;
		songs* previous = head;

		while (current != NULL)
		{
			if (no == current->no)
			{
				previous->nextAddress = current->nextAddress;
				cout << "Deleted Song ID : " << current->no << endl;
				delete current;
				break;
			}
			previous = current;
			current = current->nextAddress;
		}
	}
	::sizeOfLinkedList--;
}

void searchGenre(string genre)
{
	songs* current = head;

	if (head == NULL)
	{
		cout << "Sorry, the list is empty." << endl;
		return;
	}

	cout << "No - Artist - Song - Released - Genre - Length" << endl;

	while (current != NULL)
	{
		if (current->genre == genre)
		{
	while (current != NULL) {
		cout << current->no << " - " << current->artist << " - " << current->songName << " - " << current->yearReleased << " - " << current->genre << " - " << current->songLength << endl;
		current = current->nextAddress;
	}
	return;
		}
		current = current->nextAddress;
	}
	cout << "Genre does not exist, please retype." << endl;
}

int main() {
	head = tail = NULL;

	insertToFront(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58);
	insertToEnd(2, "Taylor Swift", "You Belong with Me", 2008, "Pop", 3.48);
	insertToEnd(3, "The Cranberries", "Promises", 1999, "Rock", 4.30);
	viewList();

	insertToEnd1(2, "Taylor Swift", "You Belong with Me", 2008, "Pop", 3.48);
	insertToEnd1(3, "The Cranberries", "Promises", 1999, "Rock", 4.30);
	insertToFront1(1, "Celine Dion", "Just Walk Away", 1993, "Pop", 4.58);
	viewSortedList();

	insertToFront(4, "Maria Carey", "All I Want For Christmas Is You", 1994, "Seasonal", 3.55);
	insertToEnd(5, "Selena Fomez, Kygo", "It Ain't Me", 2017, "Dance-pop", 3.41);
	viewList();

	deleteFromFront();
	viewList();

	deleteFromEnd();
	viewList();

	deleteWithArtist("Taylor Swift");
	viewList();

	deleteWithSongNo(3);
	viewList();

	searchGenre("Pop");

	return 0;
}

