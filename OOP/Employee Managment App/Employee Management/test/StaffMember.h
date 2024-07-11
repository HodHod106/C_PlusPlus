#pragma once
#include<string>
#include"department.h"
using namespace std;
class StaffMember{
protected:
	string fName, lName; int empid,age;
	bool gender; string phone;string email;
	department *depart;
public:
	StaffMember(); ~StaffMember();
	void setName(string ,string); void setEmpId(int);
	void setAge(int); int getId(); void setGender(bool);
	bool search(string); virtual void readInput();
	virtual void print(); virtual double pay() = 0;
	void setDepart(department*);
};