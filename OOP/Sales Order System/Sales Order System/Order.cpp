#include "Order.h"
Order::Order(){
	srand(time(0));
	orderNumber = (rand() % 1000000) + 1;
	orderStatus = STATUS::NEW;
	total = 0.0;
	countItems = 0;
	orderItemList = new OrderItem[1000];
	customer = nullptr;
	paidVal = 0;
	orderId = 0;
	paymntPntr = nullptr;
}
void Order::createOrder(Customers* c, Stock* s){
	int cusid, OrderItemNum;
	int prodId;
	while (true) {
		c->showAllCuttomers();
		cout << "Enter Customer Id: ";
		cin >> cusid;
		if (cusid >= 1 and cusid <= c->getCount()+1) break;
		else cout << "Plz Enter A valid ID!!\a\n"; Sleep(1500);
	}
	customer = (c->getCustomerList()[cusid - 1]);
	cout << "Enter Order Items: "; cin >> OrderItemNum;
	for (size_t i = 0; i < OrderItemNum; i++){
		s->print();
		while (true) {
			cout << "Enter Order Item " << i + 1 << " Product Id: ";
			cin >> prodId;
			if (prodId >= 1 and prodId <= s->getProdCount()+1) break;
			else cout << "Plz Enter A valid ID!!\a\n"; Sleep(1500);
		}
		orderItemList[countItems].orderItemInfo(s->getProdData(), prodId);
		total += orderItemList[countItems].getQuantity() * orderItemList[countItems].getSalePrice();
		orderItemList[countItems].setId(countItems + 1);
		++countItems;
	}
	cout << "Order Created Succesfully..:)\n"; Sleep(2500);
	fstream order("order.txt", ios::app);
	order << "Order Number: " << orderNumber << "\t\tOrder Time: " << __TIME__ << "    " << __DATE__ << endl;
	for (int i = 0; i < countItems; i++)
	{
		order << orderItemList[i].printOrderItemInfo() << endl;
	}
	order << "Customer Info: \n" << customer->getInfo();
	order << "\n=========================================================================================\n";
	order.close();
}
void Order::updateOrderStatus(int sts)
{
	switch (sts)
	{
	case 1:
		orderStatus = STATUS::NEW;
		break;
	case 2:
		orderStatus = STATUS::PINDIND;
		break;
	case 3:
		orderStatus = STATUS::PAID;
		for (int i = 0; i < countItems; ++i) orderItemList[i].updateStockProductQuantity();
		break;
	default:
		orderStatus = STATUS::CANCELLED;
		break;
	}
	
}
string Order::getStatus()
{
	if (orderStatus == STATUS::NEW) return "NEW";
	else if(orderStatus == STATUS::PAID) return "PAID";
	else if (orderStatus == STATUS::PINDIND) return "PINDING";
	else return "CANCELLED";
}
void Order::setTotalPrice(double p)
{
	total = p;
}
int Order::getNumber() const
{
	return orderNumber;
}
void Order::setNumber(int num)
{
	orderNumber = num;
}
ostream& operator<<(ostream& out, Order& order){
	out << "Order Number: " << order.orderNumber << "\tStatus: ";
	if (order.orderStatus == STATUS::NEW) out << "NEW";
	else if (order.orderStatus == STATUS::PAID) out << "PAID";
	else if (order.orderStatus == STATUS::PINDIND) out << "PINDIND";
	else out << "CANCELLED";
	out << "\tOrder Date/Time: " << __TIME__ << "  " << __TIME__ << endl;
	return out;
}
void Order::pay()
{
	if (orderStatus == STATUS::PAID ){
		cout << "\n\nThis order is already paid" << endl;
		Sleep(2500);
		return;
	}
	system("cls");

	int paytype;
	cout << "\nTotal Amount of Order value : " << total << endl;
	cout << "Please Choose payment Type \n"
		<< "\n[1] Credit \t [2] Cash \t [3] Check\n";

	while (true)
	{
		cout << "Enter Your Choice: ";cin >> paytype;
		if (paytype >= 1 && paytype <= 3)
			break;
		else
			cout << "\aPlease Enter a valid Choice :";
	}
	switch (paytype)
	{
	case 1:
		paymntPntr = new Credit;
		paymntPntr->pay();
		break;
	case 2:
		paymntPntr = new Cash;
		paymntPntr->pay();
		break;
	case 3:
		paymntPntr = new Check;
		paymntPntr->pay();
		break;
	default:
		cout << "\a Not valid Choice \n";
		return;
	}

	paidVal = paymntPntr->get();
	if (paidVal >= total){
	cout << "\n\nOrder is totally paied successefully..:)" << endl;
	updateOrderStatus(3);
	}
	else {
		cout << "\n\nOrder is being Hold because there is no enough money...:(" << endl;
		orderStatus = STATUS::PINDIND;
	}
	cout << "Total amount payed is : " << paidVal;
	paymntPntr->ExtraInfo();
	cout << "\nThank You For using our Payment Service\n\n\n";
	Sleep(2000);
	int any;
	cout << "Press Any Key To Return Back:  "; cin >> any;
}

