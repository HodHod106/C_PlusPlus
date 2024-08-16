#pragma once
#include"Employee.h"
class H_Employee:public Employee{
	double rate, hoursWorked;
public:
	H_Employee();
	void setRateWork(double, double);
	double pay();
	void readInput();
	void print();
};