#include "CreateProject.h"
#include<iostream>
#include<string>
CreateProject::CreateProject(int amount) {count = 0;size = amount;
	project = new Project[size];
	manager = new Employee[size];
	budCount = new Budget[size];
}
void CreateProject::addNewProject()
{
	Project* newProject = new Project;
	Employee* newmanger = new Employee;
	Budget* newBudget = new Budget;
	newProject->setProId(count + 1);
	newmanger->setEmpId(count + 1);
	budCount->setBudId(count + 1);
	newProject->addProject();
	newBudget->readBud();
	cout << ">> Enter Manager Details:";
	newmanger->readInput();
	project[count] = *newProject;
	manager[count] = *newmanger;
	budCount[count] = *newBudget;
	++count;
}
void CreateProject::showAllProject()
{
	bool pro = false;
	for (size_t i = 0; i < count; i++)
	{
		pro = true;
		project[i].showProject();
		cout << "----------------------------------------------\n";
		budCount[i].printBud();
		cout << "----------------------------------------------";
		cout << "\n*> Manager Details Are:  \n";
		manager[i].print();
		cout << "==================================================================\n";
	}
	if (!pro) cout << "\n\t No ProJect Found!!\n";
}
void CreateProject::incrProjBud(long double idddd){
	bool _found = false;
	int increase;
	for (size_t i = 0; i < count; i++)
	{
		if (project[i].getProId() == idddd) {
			cout << " \n>> Enter Budget Increment: "; cin >> increase;
			budCount[i].increaseBud(increase);
			_found = true;break;
		}
	}
	if (!_found)cout << "\n\t Project Not Found!!\n";
}
CreateProject::~CreateProject(){delete[]project;delete[]manager;delete[]budCount;}
