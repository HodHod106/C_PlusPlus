#pragma once
#include"Employee.h"
class Commission:public Employee{
	double target;
public:
	Commission();
	void setTarget(double);
	void readInput();
	void print();double pay();
};

