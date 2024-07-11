#include "Cash.h"
Cash::Cash()
{
	cashValue = 0;
}

void Cash::pay()
{
	cout << "Take The Amount Of Reciept: "; cin >> cashValue;
}

