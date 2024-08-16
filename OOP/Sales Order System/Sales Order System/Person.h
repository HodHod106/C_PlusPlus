#include<string>
#include"Customer.h"
using namespace std;
#pragma once
class Person :public Customer
{
	string address;
	string fullName;
public:
	Person();
	void read();
	void setPersonDetails(int id, string pho, string name, string loc);
	string print();
	string getName() { return fullName; }
	string getInfo() ;
};