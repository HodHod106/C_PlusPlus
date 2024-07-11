#include "Transction.h"
Transction::Transction()
{
	transctionId = 0;
}
void Transction::printTrans()
{
	cout << "Transction Id: " << transctionId;
	cout << "\tOrder Number: " << order.getNumber();
	cout << "\tOrder Total Price: " << order.getTotalAmount();
	cout << "\tOrder Status: " << order.getStatus() << endl;
}
string Transction::saveOnFile(){
	return to_string(transctionId) + " " + to_string(order.getNumber()) + " " + to_string(order.getTotalAmount()) + " " + order.getStatus();
}
void Transction::addTransction(Customers* c, Stock* s){
	system("cls");
	order.createOrder(c, s);
	order.updateOrderStatus(2);
}
void Transction::setTransDetails(int id, double p,int num, string s)
{
	transctionId = id;
	order.setTotalPrice(p);
	order.setNumber(num);
	if (s == "PINDING") order.updateOrderStatus(2);
	else if(s=="NEW") order.updateOrderStatus(1);
	else if(s=="PAID") order.updateOrderStatus(3);
	else  order.updateOrderStatus(4);
}
void Transction::setStatus(int s){
	if (s == 1)order.updateOrderStatus(1);
	if (s == -1)order.updateOrderStatus(4);
	if (s == 2)order.updateOrderStatus(2);
	else order.updateOrderStatus(4);
}

void Transction::payOrder()
{
	order.pay();
}

