#include<iostream>
#include<String>
#include"Payment.h"
using namespace std;

#pragma once
class Credit:public Payment
{
public:
    void pay();
    double get() { return creditVal; }
    void ExtraInfo();
private:
    double creditVal;
    string creditNumber;
    string cardType;
};