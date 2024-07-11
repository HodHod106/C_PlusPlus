#pragma once
#include"StaffMember.h"
class Volunteer:public StaffMember
{
	int amount = 0;
public:
	void setAmount(int);
	void readInput();
	void print();
	double pay();
};

