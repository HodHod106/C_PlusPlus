#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include"Product.h"
#include"Stock.h"
#include"Customers.h"
#include"TransctionList.h"
using namespace std;
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
	Sleep(sec * 1000);
	if (clear_screen) system("cls");
}
inline void printline(string msg, bool end_line = true)
{
	cout << msg << (end_line ? "\n" : "\t");
}
inline void print_try_again() {
	printline("\n\aInvalid Choice Try Again!!!!!!!!", 1);
	wait_or_clear(3, 1);
}
Product* prodList = new Product[10000];
Stock stock;
Customers customers;
TransctionList trans;
int switch_on = -1;
int transcount = -1;
void data_Entry();
void sales_Process();
void print();
void Handle_Product();
void Handle_Customer();
void AddPoductToList();
void HnadleCustomerType();
void readOrders();
int main() {
	system("Color 0B");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   -------------------------------"
		<< "\n\n\t\t\t\t    \2\1 SALES ORDER APPLICATION \1\2";
		cout << "\n\t\t\t\t\t   \x015Loading."; Sleep(500);
	cout << "."; Sleep(400);
	cout << "."; Sleep(300);
	cout << "..:)\x015"; Sleep(200);
	cout<< "\n\n\t\t\t\t  ==================================";	cout << "\n\t\t\t\t    ";system("pause");
	while (switch_on != 0) {
		system("cls");
		cout << "\nSALES ORDER APPLICATION"; 
		cout << "\n=====================\nMAIN MENU";
		cout << "\n=====================\n";
		cout << "[1] Data Entey\n" << "[2] Sales Process\n" << "[3] Print\n" << "[0] Quit\n";
		cout << "=====================\n";
		cout << "Enter your choice: "; cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			data_Entry();
			break;
		case 2:
			sales_Process();
			break;
		case 3:
			print();
			break;
		case 0:
			cout << "\n\n\t\t\tThank You..........:) Good Bye.\n\n";
			exit(0);
		default:
			print_try_again();
			break;
		}
	}
	return 0;
}
void data_Entry(){
	int selectChoice = -1;
	while (selectChoice != 0) {
		system("cls");
		cout << "\nSALES ORDER APPLICATION";
		cout << "\n=====================\nMAIN MENU -> Data Entry";
		cout << "\n=====================\n";
		cout << "[1] Product\n" << "[2] Customer\n" << "[0] Return Back\n";
		cout << "=====================\n";
		cout << "Enter your choice: "; cin >> selectChoice;
		switch (selectChoice) {
		case 1:
			Handle_Product();
			break;
		case 2:
			Handle_Customer();
			break;
		case 0:
			return;
		default:
			print_try_again();
		}
	}	
}
void sales_Process(){
	int selectChoice = -1;
	int id;
	while (selectChoice != 0) {
		
		system("cls");
		cout << "\nSALES ORDER APPLICATION";
		cout << "\n=====================\nMAIN MENU -> Sale Process";
		cout << "\n=====================\n";
		cout << "[1] Add Transction\n" << "[2] pay Order\n" << "[0] Return Back\n";
		cout << "=====================\n";
		cout << "Enter your choice: "; cin >> selectChoice;
		switch (selectChoice)
		{
		case 1:
			system("cls");
			trans.addTransctionToList(&customers, &stock);
			break;
		case 2:
			system("cls");
			trans.payTrans();
			break;
		default:
			break;
		}
	}
}
void print(){
	int selectChoice = -1;
	char key = 'w';
	while (selectChoice != 0) {
		system("cls");
		cout << "\nSALES ORDER APPLICATION";
		cout << "\n=====================\nMAIN MENU -> Print";
		cout << "\n=====================\n";
		cout << "[1] Stock Data\n" << "[2] Customers\n" << "[3] Transctions\n" << "[0] Return Back\n";
		cout << "=====================\n";
		cout << "Enter your choice: "; cin >> selectChoice;
		switch (selectChoice) {
		case 1:
			stock.print();
			cout << "\n\nPress AnyKey To Return Back: "; cin >> key;
			break;
		case 2:
			customers.showAllCuttomers();
			cout << "\n\nPress AnyKey To Return Back: "; cin >> key;
			break;
		case 3:
			system("cls");
			cout << "List Of All Transctions: \n";
			trans.printAll();
			cout << "######################################################################################################"
				"\n\nList Of Orders Of Transctions Defined By Orders Number:\n"
				"-----------------------------------------------------------------------------------------\n\n";
			readOrders();
			cout << "\n\nPress AnyKey To Return Back: "; cin >> key;
			break;
		case 0:
			return;
		default:
			print_try_again();
		}
	}
}
void Handle_Product()
{
	int id; double quant;
	int selectChoice = -1;
	while (selectChoice != 0) {
		system("cls");
		cout << "\nSALES ORDER APPLICATION";
		cout << "\n=====================\nMAIN MENU -> Data Entry -> Handle Product";
		cout << "\n=====================\n";
		cout << "[1] Add Product To Product List\n" << "[2] Add Product To Stock\n" 
			<< "[3] Ubdate Product In Stock\n"<< "[4] Delete Product From Stock\n" << "[0] Return Back\n";
		cout << "=====================\n";
		cout << "Enter your choice: "; cin >> selectChoice;
		switch (selectChoice) {
		case 1:
			AddPoductToList();
			break;
		case 2:
			cout << "Enter Product Id To Find And Add To Stock: "; cin >> id;
			cout << "Enter Product Quantity: "; cin >> quant;
			stock.addProductToStock(id, quant);
			break;
		case 3:
			cout << "Enter Product Id To Find And Add To Stock: "; cin >> id;
			cout << "Enter Product Quantity: "; cin >> quant;
			stock.ubdateProductInStock(id, quant);
			break;
		case 4:
			cout << "Enter Product Id To Find And Delete It From Stock: "; cin >> id;
			stock.deleteProductFromStock(id);
			break;
		case 0:
			return;
		default:
			print_try_again();
		}
	}
}
void Handle_Customer(){
	int selectChoice = -1;
	int id;
	while (selectChoice != 0) {
		system("cls");
		cout << "\nSALES ORDER APPLICATION";
		cout << "\n=====================\nMAIN MENU -> Data Entry -> Handle Customer";
		cout << "\n=====================\n";
		cout << "[1] Add Customer\n" << "[2] Update Customer\n"
			<< "[3] Delete Customer\n" << "[0] Return Back\n";
		cout << "=====================\n";
		cout << "Enter your choice: "; cin >> selectChoice;
		switch (selectChoice) {
		case 1:
			HnadleCustomerType();
			break;
		case 2:
			system("cls");
			cout << "\nSALES ORDER APPLICATION";
			cout << "\n=====================\nMAIN MENU -> Data Entry -> Handle Customer -> Delete Customer";
			cout << "\n=============================================================\n";
			cout << "Enter Customer Id To Find And Edit: "; cin >> id;
			customers.editCustomer(id);
			break;
		case 3:
			system("cls");
			cout << "\nSALES ORDER APPLICATION";
			cout << "\n=====================\nMAIN MENU -> Data Entry -> Handle Customer -> Edit Customer";
			cout << "\n=============================================================\n";
			cout << "Enter Customer Id To Find And Edit: "; cin >> id;
			customers.delCustomer(id);
			break;
		case 0:
			return;
		default:
			print_try_again();
		}
	}
}
void AddPoductToList()
{
	int sizeBefore = 0; int sizeAdded = 0;
	int totalSize = 0;
	char ch = 'Y';
	do{
		system("cls");
		cout << "\nSALES ORDER APPLICATION";
		cout << "\n=====================\nMAIN MENU -> Data Entry -> Handle Product -> Add Product To Product List";
		cout << "\n=====================\n";
		unsigned int id;string name, serial_num, type;double price;
		ofstream onfile("Products.txt", ios::app);
		ifstream infile("Products.txt", ios::in);
		if (onfile.is_open()) {
			int i = -1;
			while (infile >> id and getline(infile, name, '|')
				and getline(infile, serial_num, '|') and getline(infile, type, '|') and infile >> price) {
				if (name.at(0) == ' ') name.erase(0, 1);
				prodList[++i].setProductDetails(id, name, serial_num, type, price);
				sizeBefore = id;
			}
		}
		infile.close();
		cout << "Enter Number Of Product: "; cin >> sizeAdded;
		totalSize = sizeBefore + sizeAdded;
		cout << sizeBefore << " products Founded\n";
		for (unsigned int i = sizeBefore; i < totalSize; ++i)
		{
			cout << "Enter Product Number " << i + 1 << " In Product List Details \n";
			cout << "=======================================================\n";
			prodList[i].setId(i + 1);
			cin >> prodList[i];
			onfile << prodList[i] << endl;;
		}
		onfile.close();
		cout << "\n\nWolud You Like To Add Another Product.....(Y/N)? "; cin >> ch;
	} while (ch == 'y' or ch == 'Y');
	
}
void HnadleCustomerType(){
	system("cls");
	int cc = -1;
	cout << "\nSALES ORDER APPLICATION";
	cout << "\n=====================\nMAIN MENU -> Data Entry -> Handle Customer -> Customer Type";
	cout << "\n=====================\n";
	cout << "[1] Person\n" << "[2] Companey\n" << "[0] Quit\n";
	cout << "=====================\n";
	cout << "Enter your choice: "; cin >> cc;
	system("cls");
	cout << "\nSALES ORDER APPLICATION";
	cout << "\n=====================\nMAIN MENU -> Data Entry -> Handle Customer -> Add New Customer";
	cout << "\n============================================================\n";
	cout << "Enter Customer Detials: \n";
	cout << "========================\n";
	customers.addNewCustomer(cc);
}
void readOrders()
{
	ifstream read("order.txt");
	string line;
	while (!read.eof()) {
		getline(read, line, '\n');
		cout << line << endl;
	}
	read.close();
}
