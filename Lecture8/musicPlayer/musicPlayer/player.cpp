#include<iostream>
#include<string>
using namespace std;

int size = 0;

struct musicPlayer
{
	string artist, song, genre;
	int released_year, position;
	double length;

	musicPlayer* nextAddress;
	musicPlayer* previousAddress;
} *head, * tail, * current, * newNode;

musicPlayer* createNewNode(string artist, string song, int released_year, string genre, double length) {
	musicPlayer* newNode = new musicPlayer;
	newNode->artist = artist;
	newNode->song = song;
	newNode->released_year = released_year;
	newNode->genre = genre;
	newNode->length = length;

	newNode->previousAddress = NULL;
	newNode->nextAddress = NULL;

	return newNode;
}

void insertNewSong(musicPlayer* newNode) {
	if (head == NULL)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->previousAddress = tail;
		tail->nextAddress = newNode;
		tail = newNode;
	}
}
void displayWholeSongFromFront() {
	musicPlayer* current = head;

	cout << "Artist - Song - Released - Genre - Length" << endl;

	while (current != NULL) {
		cout << current->artist << " - " << current->song << " - " << current->released_year << " - " << current->genre << " - " << current->length << endl;
		current = current->nextAddress;
	}

	cout << "End of List!" << endl << endl;
}


void displayWholeSongFromEnd() {
	musicPlayer* current = tail;

	cout << "Artist - Song - Released - Genre - Length" << endl;

	while (current != NULL) {
		cout << current->artist << " - " << current->song << " - " << current->released_year << " - " << current->genre << " - " << current->length << endl;
		current = current->previousAddress;
	}

	cout << "End of List!" << endl << endl;
}

void displaySingleSongFromStart() {
	musicPlayer* current = head;

	cout << "Artist - Song - Released - Genre - Length" << endl;

		cout << current->artist << " - " << current->song << " - " << current->released_year << " - " << current->genre << " - " << current->length << endl;
		current = current->nextAddress;

	cout << "End of List!" << endl << endl;
}

void displaySingleSongFromEnd();

void insertNewSongAtFront(string artist, string song, int released_year, string genre, double length) {
	newNode = new musicPlayer;
	newNode->artist = artist;
	newNode->song = song;
	newNode->released_year = released_year;
	newNode->genre = genre;
	newNode->length = length;
	newNode->nextAddress = NULL;

	if (head == NULL) {
		head = tail = newNode;
	}
	else {
		newNode->nextAddress = head;
		head = newNode;
	}
}

void insertNewSongAtEnd(string artist, string song, int released_year, string genre, double length) {
	newNode = new musicPlayer;
	newNode->artist = artist;
	newNode->song = song;
	newNode->released_year = released_year;
	newNode->genre = genre;
	newNode->length = length;
	newNode->nextAddress = NULL;

	if (tail == NULL) {
		head = tail = newNode;
	}
	else {
		//newNode->nextAddress = tail->previousAddress;
		newNode->previousAddress = tail;
		tail->nextAddress = newNode;

	}
}

int main()
{
	string artist; string song; int released_year; string genre; double length; int position;
	head = tail = NULL;
	string defaultSongs[4][5] =
	{
	{"Celine Dion", "Just Walk Away", "1993", "Pop", "4.58"},
	{"Taylor Swift", "You Belong With Me", "2008", "Pop", "3.48"},
	{"The Cranberries", "Promises", "1999", "Rock", "4.30"},
	{"Hello","Hello","2000","Rock","5.4"}
	};
	for (int i = 0; i < 4; i++)
	{
		musicPlayer* newNode = createNewNode(defaultSongs[i][0], defaultSongs[i][1], stoi(defaultSongs[i][2]),
			defaultSongs[i][3], stod(defaultSongs[i][4]));
		insertNewSong(newNode);
	}

	displayWholeSongFromFront();
	displayWholeSongFromEnd();
	insertNewSongAtFront("1", "1", 1, "1", 1);
	insertNewSongAtEnd("2", "2", 2, "2", 2);

	displayWholeSongFromFront();

	int decision = 1;
	int loop = 0;
	while (decision != 0) {
		loop++;

		for (int l = loop; l < loop + 1; l++) {
			displaySingleSongFromStart();
			cout << endl;
			cout << "Would you like to see the next song in the list? Type 1 for Yes, 0 for No: " << endl;
			cin >> decision;
			cin.ignore();
			cout << endl;
		}
	}
	//displaySingleSongFromStart();

	//int decision = 1;
	//while (decision != 0)
	//{
	//	cout << "Menu: " << endl;
	//	system("cls");
	//}

	return 0;
}