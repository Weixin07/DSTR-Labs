#include <iostream>
#include <string>
#include <algorithm>

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

string converttoUpperCase(string data)
{
	std::for_each(data.begin(), data.end(), [](char& c) {
		c = ::toupper(c);
		});

	return data;
}

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
void insertNewSonginSortedList(musicPlayer* newnode) //arrange the list based on the song title in ascending order
{
	//situation 1: list is empty
	if (head == NULL)
	{
		head = tail = newnode;
	}
	//situation 2: list is not empty, but always the content less than the head content
	else if (converttoUpperCase(newnode->song) <= converttoUpperCase(head->song))
	{
		//insert to the front?
		newnode->nextAddress = head;
		head->prevAddress = newnode;
		head = newnode;
	}
	//situation 3: list is not empty, but always the content more than the tail content
	else if (converttoUpperCase(newnode->song) >= converttoUpperCase(tail->song))
	{
		//insert to the end?
		newnode->prevAddress = tail;
		tail->nextAddress = newnode;
		tail = newnode;
	}
	//situation 4: list is not empty, but always the content is more than the head content and less than the tail content(in the middle list)
	else
	{
		current = head->nextAddress;

		while (converttoUpperCase(current->song) <= converttoUpperCase(newnode->song))
		{
			current = current->nextAddress;
		}

		//9 <---15
		newnode->prevAddress = current->prevAddress;
		//15---> 17
		newnode->nextAddress = current;
		//9 --->15 ?
		current->prevAddress->nextAddress = newnode;
		//15 <--- 17
		current->prevAddress = newnode;
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
		musicPlayer* newnode = createNewNode(defaultSongs[i][0], defaultSongs[i][1], stoi(defaultSongs[i][2]),
			defaultSongs[i][3], stod(defaultSongs[i][4]));
		insertNewSonginSortedList(newnode);
	}
	int decision = 1;
	while (decision != 0)
	{
		cout << "===============================================" << endl;
		cout << "Menu: " << endl;
		cout << "===============================================" << endl;
		cout << "1. Insert Song to Sorted List" << endl;
		cout << "2. Display Whole Song List From Front" << endl;
		cout << "3. Display Whole Song List From End" << endl;
		cout << "0. Exit Program" << endl;
		cout << "================================================" << endl;
		cout << endl << "Enter Menu Option: " << endl;
		cin >> decision;
		cin.ignore();

		musicPlayer* newnode = NULL;
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
				newnode = createNewNode(artist, song, released_year, genre, length);
				insertNewSonginSortedList(newnode);
				break;
			case 2: displayWholeSongFromFront(); break;
			case 3: displayWholeSongFromEnd(); break;
		}
		
		system("cls");
	}
	return 0;
}