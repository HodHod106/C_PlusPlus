#include<string>
#include"Order.h"
using namespace std;
#pragma once
class Transction{
	Order order;
	int transctionId;
public:
	Transction();
	void setTransId(int id) { transctionId = id; }
	int getTransId() {return transctionId; }
	void printTrans();
	string saveOnFile();
	void addTransction(Customers* c, Stock* s);
	void setTransDetails(int id, double p,int num, string s);
	void setStatus(int s);
	void payOrder();
	
};