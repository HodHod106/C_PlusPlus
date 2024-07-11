#include<string>
#include<Windows.h>
using namespace std;  
#pragma once
class Payment
{
public:
	Payment();
	virtual void pay() = 0;
	virtual double get() = 0;
	virtual void ExtraInfo() = 0;
};