#pragma once
#include<string>
using namespace std;
class department
{
	int depId;
	string depName;
public:
	department();
	void setDepIdName(int, string);
	string getName() const;
	void print() const;
};

