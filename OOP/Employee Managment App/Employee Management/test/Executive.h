#pragma once
#include"S_Employee.h"
class Executive:public S_Employee
{
	double bounus;
public:
	Executive();
	void addBounus(double);
	double pay();
	void readInput();
	void print();

};

