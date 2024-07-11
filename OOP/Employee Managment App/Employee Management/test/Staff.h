#pragma once
#include"StaffMember.h"
#include"department.h"
class Staff{
	int size; int count_total;
	StaffMember** staff_listt;
public:
	Staff(int);
	~Staff();
	void AddNewMember(department*,int);
	void SearchMember();
	void deleteMember();
	void printAllMebers();
	void calcPayRoll();
};

