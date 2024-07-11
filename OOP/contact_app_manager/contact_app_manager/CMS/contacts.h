#pragma once
#pragma once
#include"user.h"
#include<iostream>
using namespace std;
class contacts
{
private:
	int count, size;
	user* users;
public:
	contacts(int);
	~contacts();
	void addNewUser();
	void deleteUser(int);
	void editUser(int);
	void print() const;
	void findAll(string) const;
};


