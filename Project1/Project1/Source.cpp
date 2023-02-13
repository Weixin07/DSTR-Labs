#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct ticket
{
	int transactionID;
	int ticketID;
	string source;
	string target;
	int ticketAmount;
	string transactionDateNTime;
	string departureTime;
	int customerID;
	string customerName;
	string identityCard;
	string passportDetailTs;
	string passengerEmailAddress;

	ticket* nextAddressT;
	ticket* previousAddressT;

}*headT, * currentT, * tailT, * newNodeT;

struct purchase
{
	int transactionID;
	int ticketID;
	int ticketAmount;
	string transactionDateNTime;

	purchase* nextAddressP;
	purchase* previousAddressP;

}*headP, * currentP, * tailP, * newNodeP;

struct Subway {

	int subwayID;
	string currentStationName;
	string prevStationName;
	string nextStationName;
	string prevStationDistance;
	string prevStationFare;
	string prevTravelTime;
	string nextStationDistance;
	string nextStationFare;
	string nextTravelTime;
	string nearbyAttraction;

	Subway* nextAddress;
	Subway* prevAddress;

} *head, * tail, * newnode, * current;

// CONVERT TO UPPER CASE
string converttoUpperCase(string data)
{
	std::for_each(data.begin(), data.end(), [](char& c)
		{
			c = ::toupper(c);

		});

	return data;
}

//#Didnt take
//Display customer detailTs 
void displayCustomerListFromFront()
{
	system("cls");
	currentT = headT;

	while (currentT != NULL)
	{
		cout << "Passenger ID: CS" << currentT->customerID << endl;
		cout << "Name of Passenger: " << currentT->customerName << endl;
		cout << "Identity Card No. of Passenger: " << currentT->identityCard << endl;
		cout << "Passport No. of Passenger: " << currentT->passportDetailTs << endl;
		cout << "Email Address of Passenger: " << currentT->passengerEmailAddress << endl;
		cout << endl;
		cout << "Transaction ID: TS" << currentT->transactionID << endl;
		cout << "Ticket ID: TK" << currentT->ticketID << endl;
		cout << "Source Station: " << currentT->source << endl;
		cout << "Target Station: " << currentT->target << endl;
		cout << "Amount of Tickets: " << currentT->ticketAmount << endl;
		cout << "Date of Transaction: " << currentT->transactionDateNTime << endl;
		cout << "Time of Departure from Source Station: " << currentT->departureTime << endl;
		cout << "===============================================" << endl;

		cout << endl;

		currentT = currentT->nextAddressT;
	}
	cout << "All passenger are displayed." << endl << endl;
	system("pause");
}

//View Purchase Transaction
void ViewPurchaseList()
{
	system("cls");
	currentP = headP;

	while (currentP != NULL)
	{
		cout << "Transaction ID: TS" << currentP->transactionID << endl;
		cout << "Ticket ID: TK" << currentP->ticketID << endl;
		cout << "Amount of Tickets: " << currentP->ticketAmount << endl;
		cout << "Date of Transaction: " << currentP->transactionDateNTime << endl;
		cout << "===============================================" << endl;
		cout << endl;

		currentP = currentP->nextAddressP;
	}
	cout << "End of List!" << endl << endl;
	system("pause");
}

void insertPurchasefromEnd(purchase* newNodeP)
{
	//situation 1: list empty
	if (headP == NULL)
	{
		headP = tailP = newNodeP; //changes for doubly
	}
	//situation 2: list not empty
	else
	{
		newNodeP->previousAddressP = tailP;
		tailP->nextAddressP = newNodeP;
		tailP = newNodeP;
	}
}

// Sort Purchase based on passenger name in ascending order
void inserToEndOfSortedList(ticket* newNodeT)
{
	// Arrange the list based on the customer name in ascending order
	//situation 1: list is empty
	if (headT == NULL)
	{
		headT = tailT = newNodeT;
	}
	//situation 2: list is not empty, but always the content less than the headT content
	else if (converttoUpperCase(newNodeT->customerName) <= converttoUpperCase(headT->customerName))
	{
		// Insert to the front
		newNodeT->nextAddressT = headT;
		headT->previousAddressT = newNodeT;
		headT = newNodeT;
	}
	//situation 3: list is not empty, but always the content more than the tailT content
	else if (converttoUpperCase(newNodeT->customerName) >= converttoUpperCase(tailT->customerName))
	{
		// Insert To The End
		newNodeT->previousAddressT = tailT;
		tailT->nextAddressT = newNodeT;
		tailT = newNodeT;
	}
	//situation 4: list is not empty, but always the content is more than the headT content and less than the tailT content(in the middle list)
	else
	{
		currentT = headT->nextAddressT;

		while (converttoUpperCase(currentT->customerName) <= converttoUpperCase(newNodeT->customerName))
		{
			currentT = currentT->nextAddressT;
		}

		newNodeT->previousAddressT = currentT->previousAddressT;
		newNodeT->nextAddressT = currentT;
		currentT->previousAddressT->nextAddressT = newNodeT;
		currentT->previousAddressT = newNodeT;
	}
}

//Search specific customer ticket info
bool searchSpecificCustomerID(int customerID) {
	currentT = headT;

	while (currentT != NULL) {
		if (currentT->customerID == customerID) {
			return true;
		}
		currentT = currentT->nextAddressT;
	}
	return false;
}

// Edit specific customer ticket info
void UpdateFromSpecificCustomer(int customerID)
{
	// Situation 1 : ensure list is not empty 
	if (headT == NULL)
	{
		cout << "Enable to search due to the list is empty!" << endl;

		return;
	}
	// Situation 2 : If list not empty, then start search and update
	currentT = headT; // to start from first node

	while (currentT != NULL)
	{
		if (customerID == currentT->customerID)
		{
			cout << "passenger ID : CS" << customerID << " was found. Kindly update the new details here : -  " << endl;

			cout << "Update Source Station : " << endl;
			getline(cin, currentT->source);

			cout << "Update Source Station : " << endl;
			getline(cin, currentT->source);

			cout << "Update Target Station : " << endl;
			getline(cin, currentT->target);

			cout << "Update Departure Time from Source Station : " << endl;
			getline(cin, currentT->departureTime);

			displayCustomerListFromFront();

			return;
		}
		currentT = currentT->nextAddressT;
	}
	cout << "The passenger ID you entered cannot be found. Please re-enter the correct ID!" << endl;
}

// Delete specific customer ticket info 
void DeleteFromSpecificCustomer(int customerID)
{
	// Situation 1 : List Empty 
	if (headT == NULL)
	{
		return;
	}
	// Situation 2 : List not Empty, but located in the first customer ID
	else if (headT->customerID == customerID)
	{
		currentT = headT;
		headT = headT->nextAddressT;

		if (headT == NULL)
		{
			tailT = NULL;
		}
		else
		{
			headT->previousAddressT = NULL;
		}
		cout << "Passenger ID : CS" << currentT->customerID << " - ticket info has been deleted!" << endl << endl;
		delete currentT;

		displayCustomerListFromFront();
	}
	// Situation 3 : List not empty, but located in the last Customer ID
	else if (tailT->customerID == customerID)
	{
		currentT = tailT;
		tailT = tailT->previousAddressT;

		if (tailT == NULL)
		{
			headT = NULL;
		}
		else
		{
			tailT->nextAddressT = NULL;
		}
		cout << "Passenger ID : CS" << currentT->customerID << " - ticket info has been deleted!" << endl << endl;
		delete currentT;

		displayCustomerListFromFront();
	}
	// Situation 4 : List not empty, but located in the middle of Book ID
	else
	{
		currentT = headT->nextAddressT;

		while (currentT != NULL && currentT->customerID != customerID)
		{
			currentT = currentT->nextAddressT;
		}

		if (currentT != NULL)
		{
			// delete the item
			currentT->previousAddressT->nextAddressT = currentT->nextAddressT;
			currentT->nextAddressT->previousAddressT = currentT->previousAddressT;

			cout << "Passenger ID : CS" << currentT->customerID << " - ticket info has been deleted!" << endl << endl;
			delete currentT;

			displayCustomerListFromFront();
		}
		else
		{
			cout << "The passenger ID you entered cannot be found. Please re-enter the correct ID!" << endl << endl;
		}
	}
}

Subway* createNewNode(int subwayID, string currentStationName, string prevStationName, string nextStationName, string prevStationDistance, string prevStationFare, string prevTravelTime, string nextStationDistance, string nextStationFare, string nextTravelTime, string nearbyAttraction)
{
	Subway* newnode = new Subway;
	newnode->subwayID = subwayID;
	newnode->currentStationName = currentStationName;
	newnode->prevStationName = prevStationName;
	newnode->nextStationName = nextStationName;
	newnode->prevStationDistance = prevStationDistance;
	newnode->prevStationFare = prevStationFare;
	newnode->prevTravelTime = prevTravelTime;
	newnode->nextStationDistance = nextStationDistance;
	newnode->nextStationFare = nextStationFare;
	newnode->nextTravelTime = nextStationFare;
	newnode->nearbyAttraction = nearbyAttraction;
	newnode->prevAddress = NULL;
	newnode->nextAddress = NULL;

	return newnode;
}

// Display station list
void displayStationListFromFront()
{
	system("cls");
	current = head;

	while (current != NULL)
	{
		cout << "Subway ID: " << current->subwayID << endl;
		cout << "Curreant Station Name: " << current->currentStationName << endl;
		cout << "Previous Station Name: " << current->prevStationName << endl;
		cout << "Next Station Name: " << current->nextStationName << endl;
		cout << "Previous Station Distance: " << current->prevStationDistance << endl;
		cout << "Previous Station Fare: " << current->prevStationFare << endl;
		cout << "Previous Station Travel Time: " << current->prevTravelTime << endl;
		cout << "Next Station Distance: " << current->nextStationDistance << endl;
		cout << "Next Station Fare: " << current->nextStationFare << endl;
		cout << "Next Station Travel Time: " << current->nextTravelTime << endl;
		cout << "Nearby Attraction: " << current->nearbyAttraction << endl;
		cout << "===============================================" << endl;

		cout << endl;

		current = current->nextAddress;
	}
	cout << "End of station list." << endl << endl;
	system("pause");
}

// Insert new station
void InsertNewStationIntoSortedList(Subway* newNode)
//arrange the list based on the song title in ascending
{
	//situation 1: list is empty
	if (head == NULL)
	{
		head = tail = newNode;
	}

	//situation 2: list is not empty, but always the content less than the head content
	else if (converttoUpperCase(newNode->currentStationName) <= head->currentStationName)
	{
		// insert to the front
		newNode->nextAddress = head;
		head->prevAddress = newNode;
		head = newNode;
	}

	//situation 3: list is not empty, but always the content more than the tail content
	else if (converttoUpperCase(newNode->currentStationName) >= tail->currentStationName)
	{
		// insert to the end
		newNode->prevAddress = tail;
		tail->nextAddress = newNode;
		tail = newNode;
	}

	//situation 4: list is not empty, but always the content is more than the head content and less than the tail content(in the middle list)
	else
	{
		current = head->nextAddress;
		while (converttoUpperCase(current->currentStationName) <= newNode->currentStationName)
		{
			current = current->nextAddress;
		}

		newNode->prevAddress = current->prevAddress;

		newNode->nextAddress = current;

		current->prevAddress->nextAddress = newNode;

		current->prevAddress = newNode;
	}
}

//Search specific customer ticket info
bool SearchSpecificStation(int subwayID) {
	current = head;

	while (current != NULL) {
		if (current->subwayID == subwayID) {
			return true;
		}
		current = current->nextAddress;
	}
	return false;
}

// Edit specific details
void UpdateFromSpecificLocation(int subwayID)
{
	// Situation 1 : ensure list is not empty 
	if (head == NULL)
	{
		cout << "List empty, unable to search!" << endl;

		return;
	}
	// Situation 2 : If list not empty, then start search and update
	current = head; // start from first node

	while (current != NULL)
	{
		if (subwayID == current->subwayID)
		{
			cout << "Subway ID : " << subwayID << " was found. Kindly update the new details here : -  " << endl;

			cout << "Update Current Station Name : " << endl;
			getline(cin, current->currentStationName);

			cout << "Update Previous Station Fare : " << endl;
			getline(cin, current->prevStationFare);

			cout << "Update Previous Travel Time : " << endl;
			getline(cin, current->prevTravelTime);

			cout << "Update Next Station Fare : " << endl;
			getline(cin, current->nextStationFare);

			cout << "Update Next Travel Time : " << endl;
			getline(cin, current->nextTravelTime);

			displayStationListFromFront();

			return;
		}
		current = current->nextAddress;
	}
	cout << "Station cannot be found! Please try again." << endl;

}


int main()
{
	// Purchase Details 
	headP = currentP = tailP = NULL;

	purchase* purchase1 = new purchase;
	purchase1->transactionID = 1;
	purchase1->ticketID = 1;
	purchase1->ticketAmount = 1;
	purchase1->transactionDateNTime = "Sun Oct 30 17:45:33 2022";

	purchase1->nextAddressP = NULL;
	purchase1->previousAddressP = NULL;

	purchase* purchase2 = new purchase;
	purchase2->transactionID = 2;
	purchase2->ticketID = 2;;
	purchase2->ticketAmount = 1;
	purchase2->transactionDateNTime = "Sun Oct 30 17:45:33 2022";
	purchase2->nextAddressP = NULL;
	purchase2->previousAddressP = NULL;

	purchase* purchase3 = new purchase;
	purchase3->transactionID = 3;
	purchase3->ticketID = 3;
	purchase3->ticketAmount = 1;
	purchase3->transactionDateNTime = "Sun Oct 30 17:45:33 2022";
	purchase3->nextAddressP = NULL;
	purchase3->previousAddressP = NULL;

	purchase* purchase4 = new purchase;
	purchase4->transactionID = 4;
	purchase4->ticketID = 4;
	purchase4->ticketAmount = 1;
	purchase4->transactionDateNTime = "Sun Oct 30 17:45:33 2022";
	purchase4->nextAddressP = NULL;
	purchase4->previousAddressP = NULL;

	insertPurchasefromEnd(purchase1);
	insertPurchasefromEnd(purchase2);
	insertPurchasefromEnd(purchase3);
	insertPurchasefromEnd(purchase4);

	// Customer Details
	headT = currentT = tailT = NULL;

	ticket* customer = new ticket;
	customer->transactionID = 1;
	customer->ticketID = 1;
	customer->source = "Titiwangsa";
	customer->target = "Klang";
	customer->ticketAmount = 1;
	customer->transactionDateNTime = "Sun Oct 30 17:45:33 2022";
	customer->departureTime = "13:00";
	customer->customerID = 1;
	customer->customerName = "Sara";
	customer->identityCard = "123456789";
	customer->passportDetailTs = "n/a";
	customer->passengerEmailAddress = "sara@gmail.com";
	customer->nextAddressT = NULL;
	customer->previousAddressT = NULL;

	ticket* customer1 = new ticket;
	customer1->transactionID = 2;
	customer1->ticketID = 2;
	customer1->source = "Chan Sou Lin";
	customer1->target = "KL";
	customer1->ticketAmount = 1;
	customer1->transactionDateNTime = "Sun Oct 30 17:45:33 2022";
	customer1->departureTime = "12:00";
	customer1->customerID = 2;
	customer1->customerName = "Suet Yan";
	customer1->identityCard = "009876511";
	customer1->passportDetailTs = "n/a";
	customer1->passengerEmailAddress = "suetyan@gmail.com";
	customer1->nextAddressT = NULL;
	customer1->previousAddressT = NULL;

	ticket* customer2 = new ticket;
	customer2->transactionID = 3;
	customer2->ticketID = 3;
	customer2->source = "KL";
	customer2->target = "Titiwangsa";
	customer2->ticketAmount = 1;
	customer2->transactionDateNTime = "Sun Oct 30 17:45:33 2022";
	customer2->departureTime = "11:00";
	customer2->customerID = 3;
	customer2->customerName = "Faithlin";
	customer2->identityCard = "n/a";
	customer2->passportDetailTs = "C18920";
	customer2->passengerEmailAddress = "faithlin@gmail.com";
	customer2->nextAddressT = NULL;
	customer2->previousAddressT = NULL;

	ticket* customer3 = new ticket;
	customer3->transactionID = 4;
	customer3->ticketID = 4;
	customer3->source = "Klang";
	customer3->target = "Chan Sou Lin";
	customer3->ticketAmount = 1;
	customer3->transactionDateNTime = "Sun Oct 30 17:45:33 2022";
	customer3->departureTime = "14:00";
	customer3->customerID = 4;
	customer3->customerName = "Alya";
	customer3->identityCard = "n/a";
	customer3->passportDetailTs = "S19711";
	customer3->passengerEmailAddress = "alya@gmail.com";
	customer3->nextAddressT = NULL;
	customer3->previousAddressT = NULL;

	inserToEndOfSortedList(customer);
	inserToEndOfSortedList(customer1);
	inserToEndOfSortedList(customer2);
	inserToEndOfSortedList(customer3);


	// Subway Details
	head = current = tail = NULL;

	Subway* station = new Subway;
	station->subwayID = 'SW1';
	station->currentStationName = "Titiwangsa";
	station->prevStationName = "N/A";
	station->nextStationName = "PWTC";
	station->prevStationDistance = "N/A";
	station->prevStationFare = "N/A";
	station->prevTravelTime = "N/A";
	station->nextStationDistance = "4 km";
	station->nextStationFare = "RM 0.40";
	station->nextTravelTime = "3 min";
	station->nearbyAttraction = "REXKL";
	station->nextAddress = NULL;
	station->prevAddress = NULL;


	Subway* station1 = new Subway;
	station1->subwayID = 'SW2';
	station1->currentStationName = "PWTC";
	station1->prevStationName = "Titiwangsa";
	station1->nextStationName = "Sultan Ismail";
	station1->prevStationDistance = "4 km";
	station1->prevStationFare = "RM 0.40";
	station1->prevTravelTime = "3 min";
	station1->nextStationDistance = "8 km";
	station1->nextStationFare = "RM 0.80";
	station1->nextTravelTime = "7 min";
	station1->nearbyAttraction = "Sunway Putra Mall";
	station1->nextAddress = NULL;
	station1->prevAddress = NULL;

	Subway* station2 = new Subway;
	station2->subwayID = 'SW3';
	station2->currentStationName = "Sultan Ismail";
	station2->prevStationName = "PWTC";
	station2->nextStationName = "Masid Jamek";
	station2->prevStationDistance = "8 km";
	station2->prevStationFare = "RM 0.80";
	station2->prevTravelTime = "7 min";
	station2->nextStationDistance = "8 km";
	station2->nextStationFare = "RM 0.80";
	station2->nextTravelTime = "7 min";
	station2->nearbyAttraction = "SOGO";
	station2->nextAddress = NULL;
	station2->prevAddress = NULL;

	Subway* station3 = new Subway;
	station3->subwayID = 'SW4';
	station3->currentStationName = "Masjid Jamek";
	station3->prevStationName = "Sultan Ismail";
	station3->nextStationName = "Plaza Rakyat";
	station3->prevStationDistance = "8 km";
	station3->prevStationFare = "RM 0.80";
	station3->prevTravelTime = "7 min";
	station3->nextStationDistance = "6 km";
	station3->nextStationFare = "RM 0.60";
	station3->nextTravelTime = "5 min";
	station3->nearbyAttraction = "Jamek Mosque";
	station3->nextAddress = NULL;
	station3->prevAddress = NULL;

	Subway* station4 = new Subway;
	station4->subwayID = 'SW5';
	station4->currentStationName = "Plaza Rakyat";
	station4->prevStationName = "Masjid Jamek";
	station4->nextStationName = "Hang Tuah";
	station4->prevStationDistance = "6 km";
	station4->prevStationFare = "RM 0.60";
	station4->prevTravelTime = "5 min";
	station4->nextStationDistance = "10 km";
	station4->nextStationFare = "RM 1.00";
	station4->nextTravelTime = "9 min";
	station4->nearbyAttraction = "MABA Basketball Stadium";
	station4->nextAddress = NULL;
	station4->prevAddress = NULL;

	Subway* station5 = new Subway;
	station5->subwayID = 'SW6';
	station5->currentStationName = "Hang Tuah";
	station5->prevStationName = "Plaza Rakyat";
	station5->nextStationName = "Pudu";
	station5->prevStationDistance = "10 km";
	station5->prevStationFare = "RM 1.00";
	station5->prevTravelTime = "9 min";
	station5->nextStationDistance = "5 km";
	station5->nextStationFare = "RM 0.50";
	station5->nextTravelTime = "4 min";
	station5->nearbyAttraction = "Kenanga Wholesale City";
	station5->nextAddress = NULL;
	station5->prevAddress = NULL;

	Subway* station6 = new Subway;
	station6->subwayID = 'SW7';
	station6->currentStationName = "Pudu";
	station6->prevStationName = "Hang Tuah";
	station6->nextStationName = "Chan Sow Lin";
	station6->prevStationDistance = "5 km";
	station6->prevStationFare = "RM 0.50";
	station6->prevTravelTime = "4 min";
	station6->nextStationDistance = "5 km";
	station6->nextStationFare = "RM 0.50";
	station6->nextTravelTime = "4 min";
	station6->nearbyAttraction = "Pasar Besar Pudu";
	station6->nextAddress = NULL;
	station6->prevAddress = NULL;

	Subway* station7 = new Subway;
	station7->subwayID = 'SW7';
	station7->currentStationName = "Chan Sow Lin";
	station7->prevStationName = "Pudu";
	station7->nextStationName = "N/A";
	station7->prevStationDistance = "5 km";
	station7->prevStationFare = "RM 0.50";
	station7->prevTravelTime = "4 min";
	station7->nextStationDistance = "N/A";
	station7->nextStationFare = "N/A";
	station7->nextTravelTime = "N/A";
	station7->nearbyAttraction = "KLCC Park";
	station7->nextAddress = NULL;
	station7->prevAddress = NULL;

	InsertNewStationIntoSortedList(station);
	InsertNewStationIntoSortedList(station1);
	InsertNewStationIntoSortedList(station2);
	InsertNewStationIntoSortedList(station3);
	InsertNewStationIntoSortedList(station4);
	InsertNewStationIntoSortedList(station5);
	InsertNewStationIntoSortedList(station6);
	InsertNewStationIntoSortedList(station7);

	int decision = 1;

	int customerID;

	int subwayID;
	string currentStationName;
	string prevStationName;
	string nextStationName;
	string prevStationDistance;
	string prevStationFare;
	string prevTravelTime;
	string nextStationDistance;
	string nextStationFare;
	string nextTravelTime;
	string nearbyAttraction;

	while (decision != 0)
	{
		cout << "===============================================" << endl;
		cout << "User : ADMIN" << endl;
		cout << "===============================================" << endl;
		cout << "1. Subway Station Information" << endl;
		cout << "2. Passenger Ticket Information" << endl;
		cout << "0. Exit Program" << endl;
		cout << "================================================" << endl;
		cout << endl << "Enter Menu Option: " << endl;
		cin >> decision;
		cin.ignore();

		switch (decision)
		{
		case 1:

			while (decision != 0)
			{
				cout << "===============================================" << endl;
				cout << "Subway Station Information Menu: " << endl;
				cout << "===============================================" << endl;
				cout << "1. Add New Subway Information" << endl;
				cout << "2. Display Subway Station List" << endl;
				cout << "3. Edit Current Subway Station Details" << endl;
				cout << "0. Exit Program" << endl;
				cout << "================================================" << endl;
				cout << endl << "Enter Menu Option: " << endl;
				cin >> decision;
				cin.ignore();

				int subwayID{};

				switch (decision)
				{
				case 1:
					subwayID++;
					cout << "Enter Station Name: " << endl;
					getline(cin, currentStationName);
					cout << "Enter Previous Station Name: " << endl;
					getline(cin, prevStationName);
					cout << "Enter Next Station Name: " << endl;
					getline(cin, nextStationName);
					cout << "Enter Previous Station Distance: " << endl;
					getline(cin, prevStationDistance);
					cout << "Enter Previous Station Fare: " << endl;
					getline(cin, prevStationFare);
					cout << "Enter Previous Station Travel Time: " << endl;
					getline(cin, prevTravelTime);
					cout << "Enter Next Station Fare: " << endl;
					getline(cin, nextStationFare);
					cout << "Enter Next Station Travel Time: " << endl;
					getline(cin, nextTravelTime);
					cout << "Enter Attraction Nearby: " << endl;
					getline(cin, nearbyAttraction);
					newnode = createNewNode(subwayID, currentStationName, prevStationName, nextStationName, prevStationDistance, prevStationFare, prevTravelTime, nextStationDistance, nextStationFare, nextTravelTime, nearbyAttraction);
					InsertNewStationIntoSortedList(newnode);
					break;

				case 2:
					displayStationListFromFront();
					break;

				case 3:
					cout << "Please enter Subway ID: " << endl;
					cin >> subwayID;
					cout << endl;

					if (SearchSpecificStation(subwayID))
					{
						cout << "Subway ID: " << current->subwayID << endl;
						cout << "Current Station: " << current->currentStationName << endl;
						cout << "Previous Station: " << current->prevStationName << endl;
						cout << "Next Station: " << current->nextStationName << endl;
						cout << "Previous Station Distance: " << current->prevStationDistance << endl;
						cout << "Previous Station Fare: " << current->prevStationFare << endl;
						cout << "Previous Station Travel Time: " << current->prevTravelTime << endl;
						cout << "Next Station Distnace: " << current->nextStationDistance << endl;
						cout << "Next Station Fare: " << current->nextStationFare << endl;
						cout << "Next Station Travel Time: " << current->nextTravelTime << endl;
						cout << "Nearby Attraction: " << current->nearbyAttraction << endl;
						cout << "===============================================" << endl;
					}
					else
					{
						cout << "Subway ID entered cannot be found. Please try again." << endl << endl;
					}

				case 4:
					while (decision != 0)
					{
						cout << "Do you want to update any station details? 1-Yes, 0-No: ";
						cin >> decision;
						cin.ignore();

						if (decision == 1)
						{
							UpdateFromSpecificLocation(subwayID);
						}
					}
					break;
				}
				system("cls");
			}

			break;

		case 2:

			while (decision != 0)
			{
				cout << "===============================================" << endl;
				cout << "Passenger Information Menu: " << endl;
				cout << "===============================================" << endl;
				cout << "1. View All Purchase Transaction" << endl;
				cout << "2. Sort All Passenger Ticket Info" << endl;
				cout << "3. Search Passenger Ticket Info" << endl;
				cout << "4. Edit Passenger Ticket Info" << endl;
				cout << "5. Delete Passenger Ticket Info" << endl;
				cout << "0. Exit Program" << endl;
				cout << "================================================" << endl;
				cout << endl << "Enter Menu Option: " << endl;
				cin >> decision;
				cin.ignore();

				switch (decision)
				{
				case 1:
					ViewPurchaseList();
					break;

				case 2:
					displayCustomerListFromFront();
					break;

				case 3:
					cout << "Please enter the passenger ID : " << endl;
					cin >> customerID;
					cin.ignore();
					cout << endl;

					if (searchSpecificCustomerID(customerID)) {
						cout << "Passenger ID: CS" << currentT->customerID << endl;
						cout << "Name of Customer: " << currentT->customerName << endl;
						cout << "Identity Card No. of Passenger: " << currentT->identityCard << endl;
						cout << "Passport No. of Passenger: " << currentT->passportDetailTs << endl;
						cout << "Email Address of Passenger: " << currentT->passengerEmailAddress << endl;
						cout << endl;
						cout << "Transaction ID: TS" << currentT->transactionID << endl;
						cout << "Ticket ID: TK" << currentT->ticketID << endl;
						cout << "Source Station: " << currentT->source << endl;
						cout << "Target Station: " << currentT->target << endl;
						cout << "Amount of Tickets: " << currentT->ticketAmount << endl;
						cout << "Date of Transaction: " << currentT->transactionDateNTime << endl;
						cout << "Time of Departure from Source Station: " << currentT->departureTime << endl;
						cout << "===============================================" << endl;
					}
					else {
						cout << "The passenger ID you entered cannot be found. Please re-enter the correct ID!" << endl << endl;
					}
					system("pause");
					break;

				case 4:
					while (decision != 0)
					{
						cout << "Do you want to update any passenger ticket info? 1- Yes, 0- No : ";
						cin >> decision;
						cin.ignore();

						if (decision == 1)
						{
							cout << "Please enter the passenger ID : ";
							cin >> customerID;
							UpdateFromSpecificCustomer(customerID);
						}
					}
					system("pause");
					break;

				case 5:

					while (decision != 0)
					{
						cout << "Do you want to delete any passenger from the list? Type 1 for Yes, 0 for No: ";
						cin >> decision;
						cout << endl;

						if (decision == 1)
						{
							cout << "Please enter the passenger ID : ";
							cin >> customerID;
							cout << endl;
							DeleteFromSpecificCustomer(customerID);
						}
					}
					system("pause");
					break;
				}

				system("cls");
			}

			break;

			system("pause");
			break;
		}

		system("cls");
	}

	return 0;
}
