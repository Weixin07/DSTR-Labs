#include <iostream>
using namespace std;

class flowers {
	string flowerID = "Flower01";

	string getFlowerID() {
		return flowerID;
	}

public:
	string flowerName = "Sunflower";
	string location = "Selangor";
	string date = "22-08-2022";

	flowers() {}

	flowers(string flowerID, string flowerName, string location, string date) {
		this->flowerID = flowerID;
		this->flowerName = flowerName;
		this->location = location;
		this->date = date;
	}

	void setFlowerID(string flowerID) {
		this->flowerID = flowerID;
	}

	void displayFlowerDetails();

};

void flowers::displayFlowerDetails() {
	cout << "Flower Details: " << flowerName << " - " << getFlowerID() << " - " << location << " - " << date << endl;
}

int main() {
	flowers f;
	f.displayFlowerDetails();

	f.setFlowerID("Flower02");
	f.flowerName = "Rose";
	f.location = "Kuala Lumpur";
	f.date = "14-05-2022";
	f.displayFlowerDetails();

	flowers f2("Flower03", "Lotus", "Perak", "12-03-2022");
	f2.displayFlowerDetails();

	return 0;
}