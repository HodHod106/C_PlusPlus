#include "H_Employee.h"
#include<iostream>
H_Employee::H_Employee(){setRateWork(rate, hoursWorked);}
void H_Employee::setRateWork(double rate, double work){
	this->rate = rate;hoursWorked = work;}
double H_Employee::pay(){return rate*hoursWorked;}
void H_Employee::readInput(){
	cout << " Enter Hourly Employee Member details:: " << endl;
	Employee::readInput();cout << " Enter Rate: "; cin >> rate;
	cout << " Enter Hours Worked: "; cin >> hoursWorked;
}
void H_Employee::print(){
	Employee::print();
	cout << ".: Your Payment is: " << pay() << endl;
}
