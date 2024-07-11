#include"Payment.h"
#include<string>
#include<iostream>
using namespace std;
#pragma once
class Cash:public Payment{
	double cashValue;
public:
	Cash();
	void pay();
	double get() { return cashValue; }
	void ExtraInfo() {};
};