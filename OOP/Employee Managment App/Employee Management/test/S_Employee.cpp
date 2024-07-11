#include "S_Employee.h"
#include<iostream>
#include<string>
using namespace std;
S_Employee::S_Employee() {setSalary(salary);}
void S_Employee::setSalary(double s){ salary = s;}
void S_Employee::readInput() { Employee::readInput(); 
cout << " Enter Your Slary: ";cin >> salary;}
void S_Employee::print(){Employee::print();
	cout << ".: Your Pay Roll Is: " << this->pay() << endl;}
double S_Employee::pay(){return salary;}