#include "OrderItem.h"
OrderItem::OrderItem()
{
	quantit = 0.0;
	sale_price = 0;
	id = 0;
	prodName = "NO PRODUCT ADDED!!";
}

void OrderItem::updateStockProductQuantity()
{
	product->quantity -= quantit;
}
void OrderItem::orderItemInfo(prodData* pp,int idd){
	product = pp + idd - 1;
	double q;
	prodName = product->stockProdList.getName();
	productQuantity = product->quantity;

	sale_price = product->stockProdList.getprice();
	sale_price = sale_price + sale_price * 0.1;
	while (true) {
		cout << "Enter Quantity: "; cin >> q;
		if (product->quantity < q) {
			cout << "The Quanity You Enterd Is Invalid!!\nPlz Try Again"; Sleep(1500);
		}
		quantit = q;
		break;
	}
}
string OrderItem::printOrderItemInfo(){
	return  "Id: " + to_string(id) + "\tProduct Name: " + prodName + "\tPrice: " + to_string(sale_price) + "\tQauntity: " + to_string(quantit);
}

double OrderItem::operator-=(const OrderItem& obj)
{

	return quantit -= obj.quantit;
}

