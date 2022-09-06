//L01: Making static/dynamic array
#include <iostream>
using namespace std;

class flower {
private:
	int flowerID;
	string flowerName;
	string flowerLocation;
	string flowerPickDate;

public:

//multiple types of constructors
	flower() { //dafault value
		this->flowerID = 123;
		this->flowerName = "Rose";
		this->flowerLocation = "Selangor";
		this->flowerPickDate = "22-08-2022";
	}

	flower(int flowerID, string flowerName, string flowerLocation) {
		this->flowerID = flowerID;
		this->flowerName = flowerName;
		this->flowerLocation = flowerLocation;
		this->flowerPickDate = "22-08-2022";
	}

	flower(int flowerID, string flowerName, string flowerLocation, string flowerPickDate) {
		this->flowerID = flowerID;
		this->flowerName = flowerName;
		this->flowerLocation = flowerLocation;
		this->flowerPickDate = flowerPickDate;
	}

	//getter and setter methods
	void setFlowerInformation(int flowerID, string flowerName, string flowerLocation, string flowerPickDate) {
		this->flowerID = flowerID;
		this->flowerName = flowerName;
		this->flowerLocation = flowerLocation;
		this->flowerPickDate = flowerPickDate;
	}

	int getFlowerID() {
		return flowerID;
	}

	string getFlowerName() {
		return flowerName;
	}

	string getFlowerLocation() {
		return flowerLocation;
	}

	string getFlowerPickDate() {
		return flowerPickDate;
	}

	//display method
	void displayFlowerInformation();

	//destructor - to clean up the memory fully from the system (auto invoke by system when system detects an object is being deleted)
	~flower() {
		cout << "Deleted: Object with flower ID = " << flowerID << endl << endl;
	}
	//first will be the last to be removed cuz stack concept, it will take from the top first aka the last one we added in
	//only stack flowers will be deleted cuz stack removes data once the function finishes
	//heap only removes data once the programme ends
};

void flower::displayFlowerInformation() {
	cout << "Flower ID: " << flowerID << endl;
	cout << "Flower Name: " << flowerName << endl;
	cout << "Flower Location: " << flowerLocation << endl;
	cout << "Flower Pick Date: " << flowerPickDate << endl << endl;
}

int main() {
	//static item/object - stack
	flower f;
	f.displayFlowerInformation(); //stating which object its using - cuz its static

	flower f2(345, "Rose", "Penang");
	f2.displayFlowerInformation();

	flower f3(156, "Cactus", "Selangor", "05-09-2022");
	f3.displayFlowerInformation();

	//they will auto find the suitable constructor to use
	flower f4(666, "Kayson", "Pet Cocky");
	f4.displayFlowerInformation();

	//dynamic - heap
	flower* f5 = new flower;
	f5->displayFlowerInformation(); //pointing to another object - cuz its dynamic, it doesn't have its own

	flower* f6 = new flower(222, "Lotus", "Kuala Lumpur", "30-04-2021");
	f6->displayFlowerInformation();

	flower* f7 = new flower(777, "Rafflesia","Kuching");
	f7->displayFlowerInformation();

	//can delete data in heap by this
	delete f7;

	//-------------------------------------------------------------------------------------------------------------------------------------------------
	//Making arrays
	int flowerID[3] = { 123, 567, 899 };
	string flowerName[3] = {"Rose","Lotus","Cactus"};
	string flowerLocation[3] = {"Selangor","Kuala Lumpur","Penang"};
	string flowerPickDate[3] = {"12-08-2022","30-05-2022","12-06-2001"};

	//static array
	flower fArrayStatic[3];

	for (int i = 0; i < size(fArrayStatic); i++) {
		fArrayStatic[i].setFlowerInformation(flowerID[i], flowerName[i], flowerLocation[i], flowerPickDate[i]);

	}

	for (int i = 0; i < size(fArrayStatic); i++) {
		fArrayStatic[i].displayFlowerInformation();
	}
	
	//dynamic array
	flower* fArrayDynamic = new flower[3];

	for (int i = 0; i < 3; i++) {
		fArrayDynamic[i].setFlowerInformation(flowerID[i], flowerName[i], flowerLocation[i], flowerPickDate[i]);

	}

	for (int i = 0; i < 3; i++) {
		fArrayDynamic[i].displayFlowerInformation();
	}

	//To delete array
	delete[] fArrayDynamic;

	return 0;
}