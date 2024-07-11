#include<iostream>
#include<String>
#include"Payment.h"
using namespace std;
#pragma once
class Check:public Payment
{
    void pay();
    double get() { return checkVal; }
    void ExtraInfo();
private:
    double checkVal;
    string n_name;
    string bankID;
};