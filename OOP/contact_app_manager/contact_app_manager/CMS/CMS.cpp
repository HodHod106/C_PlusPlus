#include <iostream>
#include "contacts.h"
#include<Windows.h>
using namespace std;
void remain() {
	int opt;
	cout << "\n\n.::Enter the Choice:\n[1] Main Menu\t\t[0] Exit\n";
	cin >> opt;
	if (opt == 0) {
		system("cls");
		cout << "\n\n\n\t\t\tThank you for using CMS." << endl << endl;
		exit(0);
	}
}
int main()
{
	system("cls");
	system("Color 0B");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t ------------------------------------------"
		<< "\n\n\t\t\t\t * WELCOME TO CONTACT MANAGER APP *"
		<< "\n\n\t\t\t\t =============================================";
	cout << "\n\t\t\t\t\t ";
	system("pause");
	int c = -1;
	contacts contact(100);
	while (c != 0) {
		system("cls"); system("Color 0B");
		cout << "\n CONTACT MANAGEMENT SYSTEM";
		cout << "\n\n MAIN MENU";
		cout << "\n=====================\n";
		cout << " 1. Print All Contacts\n" << " 2. Add New User\n" << " 3. Search \n"
			<< " 4. Edit Existing User\n" << " 5. Delete User\n" << " 0. Quit\n";
		cout << "\n=====================\n";
		cout << "Enter your choice: ";
		cin >> c;
		if (c == 1) {
			system("cls"); contact.print(); remain();
		}
		else if (c == 2) {
			system("cls"); contact.addNewUser(); remain();
		}
		else if (c == 3) {
			system("cls");
			string key; cout << " Enter Name or Phone To Find: ";
			cin >> key; contact.findAll(key); remain();
		}
		else if (c == 4) {
			system("cls"); int editid; cout << " Enter Id To Edit: "; cin >> editid;
			contact.editUser(editid); remain();
		}
		else if (c == 5) {
			system("cls");
			int delid; cout << " Enter Id To Delete: ";
			cin >> delid; contact.editUser(delid); remain();
		}
		else {
			cout << "\t\t\tEnter A valid Choice ..:";
			Sleep(2000);
		}
	}
	system("cls");
	cout << "\n\n\n\t\t\tThank you for using CMS." << endl << endl;
	return 0;
}
