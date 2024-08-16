#include"Product.h"
#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#pragma once
using namespace std;
struct prodData {
	Product stockProdList;
	double quantity;
};
class Stock{
	int count;
	prodData *p;
public:
	Stock();
	~Stock();
	void addProductToStock(int idd, double q);
	void ubdateProductInStock(int id, int quantity);
	void deleteProductFromStock(int delid);
	prodData* getProdData() { return p; }
	int getProdCount() { return count; }
	void print();
};