#include "Companey.h"
#include<iostream>
Companey::Companey()
{
	location = "No Address Added";
	compName = "No Name Added";
}
string Companey::print() {
	return  Customer::print()+'|'+ compName + '|' + location + "|Companey";
}
string Companey::getInfo()
{
	return Customer::getInfo() + compName + "\t     " + location+"\t\tCompaney";
}

void Companey::read()
{
	Customer::read();
	cout << "Name: ";
	cin.ignore(); getline(cin, compName);
	cout << "Location: "; getline(cin, location);
}

void Companey::setCompaneyDetails(int id, string pho, string name, string loc)
{
	Customer::c_id = id; Customer::c_phone = pho;
	compName = name; location = loc;
}
