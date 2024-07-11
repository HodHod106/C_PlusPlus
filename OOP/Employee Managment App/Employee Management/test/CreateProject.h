#pragma once
#include"Project.h"
#include"Budget.h"
#include"Employee.h"
class CreateProject
{
	Budget *budCount;
	int size;
	int count;
	Project* project;
	Employee* manager;
public:
	CreateProject(int);
	~CreateProject();
	void addNewProject();
	void showAllProject();
	void incrProjBud(long double idddd);
};

