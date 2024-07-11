#include"Customer.h"
#include"Person.h"
#include"Companey.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
#pragma once
class Customers{
	int count;
	Customer** customerList;
public:
	Customers();
	~Customers();
	void addNewCustomer(int cc);
	void delCustomer(int id);
	void editCustomer(int id);
	Customer** getCustomerList() { return customerList; }
	void showAllCuttomers();
	int getCount() { return count; }
};

