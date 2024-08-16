#include "department.h"
#include<iostream>
department::department():depId(0),depName("No Department Added") {}
void department::setDepIdName(int id, string name) { depId = id; depName = name;}
string department::getName() const {return depName;}
void department::print() const{
	cout << " Department Id: " << depId << "\t| Department Name: " 
		<< depName << endl;}
