#include "TransctionList.h"

TransctionList::TransctionList(){
	transList = new Transction[10];
	countTrans = -1;
	int id,num;  double price; string status;
	ifstream infile("transction.txt");
	if (infile.is_open()) {
		while (infile >> id and infile >> num and infile >> price  and infile >> status)
		{
			transList[++countTrans].setTransDetails(id, price,num, status);
		}
	}
	infile.close();
}
void TransctionList::printAll()
{
	if (countTrans == -1) {
		cout << "## No Transction Found!!\n"; Sleep(2000);
		return;
	}
	for (size_t i = 0; i <= countTrans; i++)
	{
		transList[i].printTrans();
		cout << endl;
	}
}

void TransctionList::addTransctionToList(Customers*CC, Stock*SS)
{
	transList[++countTrans].addTransction(CC, SS);
	transList[countTrans].setTransId(countTrans + 1);
}

TransctionList::~TransctionList()
{
	fstream writeToStock("transction.txt", ios::out);
	for (size_t i = 0; i <= countTrans; i++)
	{
		writeToStock << transList[i].saveOnFile() << endl;
	}
	writeToStock.close();
	delete[]transList;
}

void TransctionList::payTrans()
{
	printAll();
    cout << "$$$======================$$$======================$$$======================$$$======================$$$\n";
	int ccc;
	while (true)
	{
		cout << "\nEnter Transction Id: "; cin >> ccc;
		if (ccc >= 1 && ccc <= countTrans+1)
			break;
		else
			cout << "\aPlease Enter a valid Choice :";
	}
	(transList + ccc - 1)->payOrder();
}

