#include "Budget.h"
#include<iostream>
using namespace std;


void Budget::setBud(double value)
{
	this->value = value;
}

void Budget::setBudId(int bbb)
{
	budid = bbb;
}

int Budget::getBudId() const 
{
	return budid;
}

void Budget::increaseBud(double incr)
{
	value += incr;
}



double Budget::getBud() const 
{
	return value;
}

void Budget::readBud()
{
	cout << ">> Enter Budjet: ";
	cin >> value;
	char aaa = 'y';
	cout << ">> Would You Like To Increase Project Budjet: (y/n)";
	cin >> aaa;
	if (aaa == 'y' || aaa == 'Y') {
		int inc;
		cout << ">> Enter Increment: ";
		cin >> inc;
		this->increaseBud(inc);
	}
}

void Budget::printBud() const
{
	cout << "**> The Budget Value is: " << this->getBud() << endl;
}
