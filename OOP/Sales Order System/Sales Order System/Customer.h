#include<string>
#include<iostream>
using namespace std;
#pragma once
class Customer{
protected:
	int c_id;
	string c_phone;
public:
	Customer();
	virtual string print();
	virtual void read();
	void setId(int id);
	virtual string getInfo();
	virtual string getName() = 0;
};

