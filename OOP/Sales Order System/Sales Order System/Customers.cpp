#include "Customers.h"
Customers::Customers(){
	count = -1;
	customerList = new Customer * [1000];
	unsigned int id; string phone, name, location, type;
	fstream infile("CustomerList.txt", ios::in);
	if (infile.is_open()) {
		while (infile >> id and getline(infile, phone, '|') and getline(infile, name, '|')
			and getline(infile, location, '|') and getline(infile, type)) {
			if (phone.at(0) == ' ') phone.erase(0, 1);
			if (type == "Person") {
				Person* obj = new Person;
				obj->setPersonDetails(id, phone, name, location);
				customerList[++count] = new Person;
				customerList[count] = obj;
			}
			else {
				Companey* obj = new Companey;
				obj->setCompaneyDetails(id, phone, name, location);              
				customerList[++count] = new Companey;
				customerList[count] = obj;
			}
		}
	}
	infile.close();
}
Customers::~Customers()
{
	ofstream on("CustomerList.txt");
	for (size_t i = 0; i <= count; i++)
	{
		on << customerList[i]->print() << endl;
		delete customerList[i];
	}
	on.close();
	delete[]customerList;
}

void Customers::addNewCustomer(int cc) {

	if (cc == 1) {
		customerList[++count] = new Person;
	}
	else if (cc == 2) {
		customerList[++count] = new Companey;
	}
	customerList[count]->setId(count + 1);
	customerList[count]->read();
	for (size_t i = 0; i < count; i++)
	{
		if (customerList[i]->getName() == customerList[count]->getName()) {
			cout << "\aThis Customer IS Alredy Exit...!\a\n";
			Sleep(3000);
			--count;
			return;
		}
	}
	cout << "Customer Added Succesfully...:)";
	Sleep(2500);
	return;
}
void Customers::delCustomer(int delid)
{
	if (delid<0 or delid>count + 1) { cout << "Customer Not Found...:("; Sleep(2500); return; }
	for (size_t i = delid; i <= count; i++)
	{
		customerList[i]->setId(i);
		customerList[i - 1] = customerList[i];
	}
	count = count - 1;
	cout << "Customer Deleted Succesfully...:)";
	Sleep(2500);
	return;
}
void Customers::editCustomer(int id)
{
	if (id <= count + 1 and id > 0) {
		customerList[id - 1]->read();
		cout << "Customer Updated Succesfully...:)\n";
		Sleep(2500);
		return;
	}
	else {
		cout << "Customer Not Found To Update...:)\n";
		Sleep(2500);
		return;
	}
}
void Customers::showAllCuttomers()
{
	system("cls");
	int _found = 0;
	cout << "\n Id\t     Phone\tName\t Address/Location\t Type\n";
	cout << "---------------------------------------------------------------------\n";
	for (size_t i = 0; i <= count; i++)
	{
		_found = 1;
		cout << customerList[i]->getInfo() << endl;
		cout << "---------------------------------------------------------------------\n";
	}
	if (!_found) cout << "\nNo Customer Found To Show..:!\n";
}