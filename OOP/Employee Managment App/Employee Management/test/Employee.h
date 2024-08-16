#pragma once
#include"StaffMember.h"
#include<string>
using namespace std;
class Employee :public StaffMember{
protected:
	string socialSecurutyNumber;
public:
	//Employee();
	void setsocialSecurutyNumber(string);
	virtual void readInput();
	virtual void print();
	virtual double pay();
};

