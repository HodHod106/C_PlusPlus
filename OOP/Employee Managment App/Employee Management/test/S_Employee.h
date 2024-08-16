#pragma once
#include"Employee.h"
class S_Employee:public Employee{
protected:
	double salary;
public:
	S_Employee();
	void setSalary(double); virtual void readInput();
	virtual void print(); virtual double pay();
};