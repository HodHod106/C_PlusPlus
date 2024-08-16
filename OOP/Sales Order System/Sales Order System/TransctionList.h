#include"Transction.h"
#include"Customers.h"
#include"Stock.h"
#pragma once
class TransctionList
{
	Transction* transList;
	int countTrans;
public:
	TransctionList();
	void addTransctionToList(Customers*, Stock*);
	void printAll();
	void payTrans();
	~TransctionList();
};


