#include "Project.h"
#include<iostream>
using namespace std;
void Project::setProId(int id){proId = id;}
int Project::getProId(){ return proId;}
void Project::setProName(string name){namePro = name;}
void Project::setProLoc(string loc){locPro = loc;}
void Project::addProject()
{
	cout << ">> Enter Project Name: ";
	cin.ignore(); getline(cin, namePro);
	cout << ">> Enter Project Location: ";
	cin.ignore(); getline(cin, locPro);
	cout << ">> Enter The Current Cost Which Company has: ";
	cin >> costCurr;
}

void Project::showProject()
{
	cout << "*> Project Id: " << proId << endl;
	cout << "*> Project Name: " << namePro << endl;
	cout << "*> Project Location: " << locPro << endl;
	cout << "*> The Capital Of Companey: " << costCurr << endl;
}
