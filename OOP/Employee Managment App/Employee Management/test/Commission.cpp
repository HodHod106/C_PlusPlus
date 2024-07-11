#include "Commission.h"
#include<iostream>
using namespace std;
void Commission::setTarget(double tar){target = tar;}
Commission::Commission(){target = 0;}
void Commission::readInput()
{
	double tarr;
	cout << " Enter Commission Member details:: " << endl;
	Employee::readInput();
	cout << " Enter Your Target: "; cin >> tarr;
	setTarget(tarr);
}
void Commission::print()

{Employee::print();
cout << ".: Your Payment Is: " << pay() << endl;
}
double Commission::pay(){
	return 0.05 * target;
}
