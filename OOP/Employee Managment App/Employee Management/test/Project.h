#pragma once
#include"Budget.h"
#include"Employee.h"
#include"string"
class Project
{
	int proId;
	long double costCurr;
	string namePro, locPro;

public:
	void setProId(int id);
	int getProId();
	void setProName(string name);
	void setProLoc(string loc);
	virtual void addProject();
	virtual void showProject();
};

