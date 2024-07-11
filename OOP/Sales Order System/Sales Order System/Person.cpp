#include "Person.h"
#include<iostream>
Person::Person()
{
	address = "No Address Added";
	fullName = "No Name Added";
}
void Person::read() {
	Customer::read();
	cout << "Name: ";
	cin.ignore(); getline(cin, fullName);
	cout << "Address: "; getline(cin, address);
}
void Person::setPersonDetails(int id, string pho, string name, string loc)
{
	Customer::c_id = id; Customer::c_phone = pho;
	fullName = name; address = loc;
}
string Person::print() {
	return Customer::print()+'|' + fullName + '|' + address + "|Person";
}
string Person::getInfo() 
{
	return Customer::getInfo() + fullName + "\t     " + address+"\t\tPerson";
}
