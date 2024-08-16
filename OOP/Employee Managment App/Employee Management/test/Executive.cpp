#include "Executive.h"
#include<iostream>
Executive::Executive(){addBounus(bounus);}
void Executive::addBounus(double BB) {bounus = BB;}
double Executive::pay(){return bounus + salary;}
void Executive::readInput(){
    cout << " Enter Executive Member details:: " << endl;
    S_Employee::readInput(); cout << " Enter Bounus: "; cin >> bounus;
}
void Executive::print(){
    Employee::print();cout << ".: Your Pay is: " << pay() << endl;
}
