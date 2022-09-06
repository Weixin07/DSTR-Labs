#include <iostream>
using namespace std;

class cashRegister {
public:
	int cashOnHand = 500;
	int newAmount;

	int calculateNewCash() {
		int newTotal = cashOnHand + newAmount;
		cashOnHand = newTotal;

		return cashOnHand;
	}

	void acceptAmount() {
		cout << "Please enter the amount that the customer has paid: ";
		cin >> newAmount;
		cout << "The amount paid is " << newAmount << "." << endl;
	}

	void printBalance() {
		cout << "The current balance is " << cashOnHand << "." << endl;
	}
};



int main() {
	cashRegister cr;
	cr.acceptAmount();
	cr.calculateNewCash();
	cr.printBalance();

	return 0;
}