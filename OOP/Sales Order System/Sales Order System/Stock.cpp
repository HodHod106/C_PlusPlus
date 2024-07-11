#include "Stock.h"
Stock::Stock(){
	count = -1; 
	p = new prodData[100];
	unsigned int id; string name, serial_num, type; double price, q;
	fstream infile("StockProducts.txt", ios::in);
	if (infile.is_open()) {
		while (infile >> id and getline(infile, name, '|') and getline(infile, serial_num, '|')
			and getline(infile, type, '|') and infile >> price and infile >> q) {
			if (name.at(0) == ' ') name.erase(0, 1);
			p[++count].stockProdList.setProductDetails(id, name, serial_num, type, price);
			p[count].quantity = q;		
		}
	}
	infile.close();
}

void Stock::addProductToStock(int serID,double quan) {
	unsigned int id; string name, serial_num, type; double price;
	bool flag = false;
	fstream readProducts("Products.txt", ios::in);
	while (readProducts >> id and getline(readProducts, name, '|')
		and getline(readProducts, serial_num, '|') and getline(readProducts, type, '|') and readProducts >> price) {
		if (id == serID)
		{
			if (name.at(0) == ' ') name.erase(0, 1);
			p[++count].stockProdList.setProductDetails(count + 1, name, serial_num, type, price);
			p[count].quantity = quan;
			for (size_t i = 0; i < count; i++)
			{
				if (p[i].stockProdList.getserial() == p[count].stockProdList.getserial()) {
					cout << "\aThis Product IS Alredy Exit, You Can Update On It If You Want\a\n";
					Sleep(3000);
					--count;
					return;
				}
			}
			flag = true;
			break;
		}
		
	}
	readProducts.close();
	if (!flag) { cout << "\nProduct Not Found....:(\n"; Sleep(2500); }
	else { cout << "\nProduct Added Sucessfully...:)\n"; Sleep(2500); }
	return;
}

void Stock::ubdateProductInStock(int id, int quantity)
{
	if (id <= count+1 and id>0) {
		cin >> p[id - 1].stockProdList;
		p[id - 1].quantity = quantity;
		cout << "Product Updated Succesfully...:)\n";
		Sleep(2500);
		return;
	}
	else {
		cout << "Product Not Found To Update...:)\n";
		Sleep(2500);
		return;
	}
}
void Stock::deleteProductFromStock(int delid)
{
	if (delid<0 or delid>count+1) { cout << "Product Id Not Found...:("; Sleep(2500); return; }
	for (size_t i = delid; i <= count; i++)
	{
		p[i].stockProdList.setId(i);
		p[i - 1].stockProdList = p[i].stockProdList;
		p[i - 1].quantity = p[i].quantity;
	}
	count = count - 1;
	cout << "Product Deleted Succesfully...:)";
	Sleep(2500);
	return;
}

void Stock::print()
{
	system("cls");
	if (count < 0) { cout << "No Product Found To Show: "; Sleep(2500); return; }
	cout << "\n Id\t  Name\t\tSerial\t\t Type\t\tprice\t\tQuantity\n";
	cout << "---------------------------------------------------------------------------------\n";
	for (size_t i = 0; i <= count; i++)
	{
		cout <<" "<< p[i].stockProdList.getId() << "\t" << p[i].stockProdList.getName() << "\t       "
			<< p[i].stockProdList.getserial() << "\t\t " << p[i].stockProdList.getType() << "\t\t "
			<< p[i].stockProdList.getprice() << "\t\t  " << p[i].quantity << endl;
		cout << "---------------------------------------------------------------------------------\n";
	}

}
Stock::~Stock()
{
	fstream writeToStock("StockProducts.txt",ios::out);
	for (size_t i = 0; i <= count; i++)
	{
		writeToStock << p[i].stockProdList << '\t' << p[i].quantity << endl;
	}
	writeToStock.close();
	delete[]p;
}

