#include "Check.h"

void Check::pay()
{
	char ch = 'y';
	cout << "Is This Check Work Or Not: (y/n)?  "; cin >> ch;
	if (ch == 'n' or ch == 'N') {
		cout << "Enter Bank Name : ";
		cin.ignore();
		getline(cin, n_name);
		cout << "Enter Bank ID : ";
		getline(cin, bankID);
		cout << "Check: "; cin >> checkVal;
	}
	else {
		cout << "\nSorry!! Your Check Donot Work...You can Choose Another Way To Pay :...\a\n";
		Sleep(2500);
		return;
	}
}
void Check::ExtraInfo()
{
	cout << "\nThe Bank Name : " << n_name << " || " << " Bank Id : " << bankID << endl;
}