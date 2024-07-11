#include<string>
#include"Customer.h"
using namespace std;
#pragma once
class Companey :public Customer{
	string location;
	string compName;
public:
	Companey();
	void read();
	void setCompaneyDetails(int id, string pho, string name, string loc);
	string print();
	string getName() { return compName; }
	string getInfo();
};

