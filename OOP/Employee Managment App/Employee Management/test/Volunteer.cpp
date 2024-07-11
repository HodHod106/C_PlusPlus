#include "Volunteer.h"
#include<iostream>
void Volunteer::setAmount(int a){amount = a;}
void Volunteer::readInput(){cout << " Enter Volunteer Member details:: " << endl;
	StaffMember::readInput();cout << " Enter Amount: "; cin >> amount;}
void Volunteer::print(){StaffMember::print();std::cout << ".: Your Pay Roll is: 0\n";}
double Volunteer::pay(){return amount;}
