#include"Product.h"
#include"Stock.h"
#pragma once
class OrderItem{
	double quantit;
	double sale_price;
	prodData *product; 
	int id;
	string prodName;
	int productQuantity;
public:
	OrderItem();
	void updateStockProductQuantity();
	void orderItemInfo(prodData*, int idd);
	void setId(int iddd) { id = iddd; };
	int getId() { return id; }
	double getQuantity() { return quantit; }
	double getSalePrice() { return sale_price; }
	string printOrderItemInfo();
	double operator-=(const OrderItem&obj);
};

