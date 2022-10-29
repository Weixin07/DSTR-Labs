#include <iostream>
#include <string>

using namespace std;

int size = 0;

struct musicPlayer
{
	string artist;
	string song;
	int released_year;
	string genre;
	double length;

	musicPlayer* nextAddress;
	musicPlayer* prevAddress;

} * head, * tail, *newnode, * current;

musicPlayer* createNewNode(string artist, string song, int released_year, string genre, double length)
{
	musicPlayer* newnode = new musicPlayer;
	newnode->artist = artist;
	newnode->song = song;
	newnode->released_year = released_year;
	newnode->genre = genre;
	newnode->length = length;
	newnode->prevAddress = NULL;
	newnode->nextAddress = NULL;

	return newnode;
}
void insertNewSong(musicPlayer* newnode) //insert to the end for the new song list
{
	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		tail->nextAddress = newnode;
		newnode->prevAddress = tail;
		tail = newnode;
	}
}
void displayWholeSongFromFront()
{
	system("cls");
	current = head;

	while (current != NULL)
	{
		cout << current->artist << ". " << current->song << " - " << current->released_year << " , " << current->genre << " , " << current->length;
		cout << endl;
		current = current->nextAddress;
	}
	cout << "List ended here! " << endl;
	system("pause");
}
void displayWholeSongFromEnd()
{
	system("cls");
	current = tail;

	while (current != NULL)
	{
		cout << current->artist << ". " << current->song << " - " << current->released_year << " , " << current->genre << " , " << current->length;
		cout << endl;
		current = current->prevAddress;
	}
	cout << "List ended here! " << endl;
	system("pause");
}
void displaySingleSongFromFront()
{
	current = head; int decision = 0;
	while (current != NULL)
	{
		system("cls");
		cout << "Artist: " << current->artist << endl;
		cout << "Song Title: " << current->song << endl;
		cout << "Song Released Year: " << current->released_year << endl;
		cout << "Song Genre: " << current->genre << endl;
		cout << "Song Length: " << current->length << endl;
		cout << endl;

		cout << "==================================" << endl;
		cout << "1. Next song" << endl;
		cout << "2. Previous Song" << endl;
		cout << "3. Back to Menu" << endl;
		cout << "==================================" << endl;
		cout << "Enter an option : ";
		cin >> decision;
		cout << endl;

		switch (decision)
		{
		case 1: current = current->nextAddress; break; //go to the next song
		case 2: current = current->prevAddress; break; // go to the previous song
		case 3: return;
		default: cout << "invalid input!" << endl; system("pause");
		}
	}
}
void displaySingleSongFromEnd()
{
	current = tail; int decision = 0;
	while (current != NULL)
	{
		system("cls");
		cout << "Artist: " << current->artist << endl;
		cout << "Song Title: " << current->song << endl;
		cout << "Song Released Year: " << current->released_year << endl;
		cout << "Song Genre: " << current->genre << endl;
		cout << "Song Length: " << current->length << endl;
		cout << endl;

		cout << "==================================" << endl;
		cout << "1. Next song" << endl;
		cout << "2. Previous Song" << endl;
		cout << "3. Back to Menu" << endl;
		cout << "==================================" << endl;
		cout << "Enter an option : ";
		cin >> decision;
		cout << endl;

		switch (decision)
		{
		case 1: current = current->prevAddress; break; //go to the next song
		case 2: current = current->nextAddress; break; // go to the previous song
		case 3: return;
		default: cout << "invalid input!" << endl; system("pause");
		}
	}
}
void insertNewSongAtFront(string artist, string song, int released_year, string genre, double length)
{
	musicPlayer* newnode = new musicPlayer;
	newnode->artist = artist;
	newnode->song = song;
	newnode->released_year = released_year;
	newnode->genre = genre;
	newnode->length = length;
	newnode->prevAddress = NULL;
	newnode->nextAddress = NULL;

	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		head->prevAddress = newnode;
		newnode->nextAddress = head;
		head = newnode;
	}
}
void insertNewSongAtEnd(string artist, string song, int released_year, string genre, double length)
{
	musicPlayer* newnode = new musicPlayer;
	newnode->artist = artist;
	newnode->song = song;
	newnode->released_year = released_year;
	newnode->genre = genre;
	newnode->length = length;
	newnode->prevAddress = NULL;
	newnode->nextAddress = NULL;

	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		tail->nextAddress = newnode;
		newnode->prevAddress = tail;
		tail = newnode;
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
	{"Hello", "Hello", "1999", "Rock", "4.11"}
	};
	for (int i = 0; i < 4; i++)
	{
		//insertNewSong(defaultSongs[i][0], defaultSongs[i][1], stoi(defaultSongs[i][2]),
			//defaultSongs[i][3], stod(defaultSongs[i][4]));
		musicPlayer* newnode = createNewNode(defaultSongs[i][0], defaultSongs[i][1], stoi(defaultSongs[i][2]),
			defaultSongs[i][3], stod(defaultSongs[i][4]));
		insertNewSong(newnode);
	}
	int decision = 1;
	while (decision != 0)
	{
		cout << "===============================================" << endl;
		cout << "Menu: " << endl;
		cout << "===============================================" << endl;
		cout << "1. Insert Song to Front List" << endl;
		cout << "2. Insert Song to End List" << endl;
		cout << "3. Display Whole Song List From Front" << endl;
		cout << "4. Display Whole Song List From End" << endl;
		cout << "5. Display Single Song List From Front" << endl;
		cout << "6. Display Single Song List From End" << endl;
		cout << "0. Exit Program" << endl;
		cout << "================================================" << endl;
		cout << endl << "Enter Menu Option: " << endl;
		cin >> decision;
		cin.ignore();
		
		switch (decision)
		{
			case 1: 				
				cout << "Enter a new song artist name: " << endl;
				getline(cin, artist);
				cout << "Enter a new song title: " << endl;
				getline(cin, song);
				cout << "Enter song year: " << endl;
				cin >> released_year;
				cin.ignore();
				cout << "Enter the genre of new song: " << endl;
				getline(cin, genre);
				cout << "Enter new song length: " << endl;
				cin >> length;
				insertNewSongAtFront(artist, song, released_year, genre, length);
				break;

			case 2:
				cout << "Enter a new song artist name: " << endl;
				getline(cin, artist);
				cout << "Enter a new song title: " << endl;
				getline(cin, song);
				cout << "Enter song year: " << endl;
				cin >> released_year;
				cin.ignore();
				cout << "Enter the genre of new song: " << endl;
				getline(cin, genre);
				cout << "Enter new song length: " << endl;
				cin >> length;
				insertNewSongAtEnd(artist, song, released_year, genre, length);
				break;

			case 3: displayWholeSongFromFront(); break;
			case 4: displayWholeSongFromEnd(); break;
			case 5: displaySingleSongFromFront(); break;
			case 6: displaySingleSongFromEnd(); break;
		}
		system("cls");
	}
	return 0;
}