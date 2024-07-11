#include "Employee.h"
#include<iostream>
using namespace std;
//Employee::Employee(){
//	setsocialSecurutyNumber(socialSecurutyNumber);
//}
void Employee::setsocialSecurutyNumber(string soc) {socialSecurutyNumber = soc;}
void Employee::readInput(){ StaffMember::readInput();
	cout << " Enter Your Social Security Number: ";cin >> socialSecurutyNumber;}


void Employee::print()
{
	StaffMember::print();
	cout << ".: Social Security Number is: " << socialSecurutyNumber << endl;
}
double Employee::pay(){
	return 0.0;
}
