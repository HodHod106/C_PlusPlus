#include<string>
#include <cstdlib>
#include <ctime>
#include"Customers.h"
#include"Stock.h"
#include"OrderItem.h"
#include"Payment.h"
#include"Cash.h"
#include"Check.h"
#include"Credit.h"
#include<fstream>
using namespace std;
#pragma once
enum class STATUS { NEW = 1, PINDIND, PAID, CANCELLED };
class Order
{
	STATUS orderStatus;
	unsigned int orderNumber;
	double total;
	unsigned int countItems;
	Customer* customer;
	OrderItem *orderItemList;
	double paidVal;
	Payment* paymntPntr;
	int orderId;
public:
	Order();
	void createOrder(Customers* c, Stock* s);
	double getTotalAmount() { return total; }
	void updateOrderStatus(int sts);
	string getStatus();
	void setTotalPrice(double p);
	int getNumber() const;
	void setNumber(int num);
	void pay();
	void setOrderId(int d) { orderId = d; }
	friend ostream& operator<<(ostream& out, Order& order);
};

