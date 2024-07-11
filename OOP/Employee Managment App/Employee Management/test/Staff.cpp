#include "Staff.h"
#include"StaffMember.h"
#include"Commission.h"
#include"S_Employee.h"
#include"Executive.h"
#include"H_Employee.h"
#include"Volunteer.h"
#include<iostream>
using namespace std;
Staff::Staff(int count) :count_total(0) { size = count;  staff_listt = new StaffMember*[size];}
Staff::~Staff(){
	for (size_t i = 0; i < size; i++) {delete staff_listt[i];}
	delete[]staff_listt;
}
void Staff::AddNewMember(department*depList,int size) {
	int type = -1; 
	cout << "\n\n.::Enter Member Type: \n"; cout << "[1] Volunteer\n[2] Salarid Employee\n"
		"[3] Hourly Employee \n[4] Commission Employee\n[5] Executive Employee!!";
	cout << "\nEnter Your Choice: ";	cin >> type;
	bool flag = true;
	if (type == 1) { system("cls"); staff_listt[count_total] = new Volunteer;}
	else if (type == 2) {system("cls");
	cout << " Enter Salaried Employee Member details:: " << endl;
		staff_listt[count_total] = new S_Employee;}
	else if (type == 3) { system("cls"); staff_listt[count_total] = new H_Employee;}
	else if (type == 4) {system("cls");staff_listt[count_total] = new Commission;}
	else if (type == 5) {system("cls");staff_listt[count_total] = new Executive;}
	else flag = false;
	if (flag) {
		staff_listt[count_total]->setEmpId(count_total + 1);
		staff_listt[count_total]->readInput();
		cout << "\n----------------------------------------------------\n";
		for (size_t i = 0; i < size; i++) depList[i].print();
		cout << "\n----------------------------------------------------\n";
		int c;
		cout << "\n Enter Department Id: "; cin >> c;
		staff_listt[count_total]->setDepart(&depList[c - 1001]);
		++count_total;
	}
}

void Staff::SearchMember() {
	string keySer;int foundMemeber = 0;
	cout << "\n:. Enter Name Or Phone To Find: "; cin >> keySer;
	for (size_t i = 0; i < count_total; ++i) {
		if (staff_listt[i]->search(keySer)) {
			staff_listt[i]->print();
			cout << "------------------------------------------------------\n";
			++foundMemeber;
		}
	}
	if (foundMemeber == 0) cout << "\n\nNo Member Found!!\n";
	else cout << foundMemeber << " Founded\n";
}
void Staff::deleteMember(){
	string keySer;bool delet = false;
	cout << ".:: Enter Name Or Phone To delete: "; cin >> keySer;
	for (size_t i = 0; i < count_total; i++)
	{
		if (staff_listt[i]->search(keySer)) {
			if (i == count_total - 1) count_total--;
			else {
				staff_listt[i] = staff_listt[count_total - 1];
				count_total--;
			}
		}
		delet = true;break;
	}
	if (!delet) cout << "\n\nNo Member Found To Delete..:(\n";
	else cout << " Member Deleted Successfully..:)\n";
}
void Staff::printAllMebers()
{
	if (count_total == 0) { cout << " \n\nNo Employees Found!!!\n";}
	else { cout << "\n.:: List Of Employees: \n";
		cout << "===============================================================\n";
		for (int i = 0; i < count_total; ++i){
			staff_listt[i]->print();
			cout << "----------------------------------------------------------------\n";
		}
	}
}
void Staff::calcPayRoll()
{
	cout << "\n\t Employee Total PayRoll.......:\n";
	double _total = 0;
	for (size_t i = 0; i < count_total; ++i)
	{
		_total += staff_listt[i]->pay();
	}
	cout << "\t Total PayRoll = " << _total << endl;
}