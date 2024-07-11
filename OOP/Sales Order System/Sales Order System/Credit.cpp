#include "Credit.h"
void Credit::pay() {
	char ch = 'y';
	cout << "Is This Credit Card Exoired Or Not: (y/n)?  "; cin >> ch;
	if (ch == 'n' or ch == 'N') {
		cout << "Enter card number : ";
		cin.ignore();
		getline(cin, creditNumber);
		cout << "Enter card type : ";
		getline(cin, cardType);
		cout << "Give Me Your Credit: "; cin >> creditVal;
	}
	else {
		cout << "\nSorry!! Your Creited Card IS Expired...You can Choose Another Way To Pay :...\a\n";
		Sleep(2500);
		return;
	}
	
}
void Credit::ExtraInfo()
{
	cout << "\nThe card number : " << creditNumber << " || " << " card type : " << cardType << endl;
}
