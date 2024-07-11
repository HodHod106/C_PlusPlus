#pragma once
#include <iostream>
#include <string>
#include "phone.h"
#include "email.h"
#include "address.h"
using namespace std;
class user {
	string m_fname, m_lname; int m_gender, m_age, m_id;
	phone* m_phones; email* m_emails; address* m_address;
	int m_phone_size; int m_address_size; int m_email_size;
	int m_phone_count; int m_address_count; int m_email_count;
public:
	user(); virtual ~user();
	void setUserId(int); void setFname(string); void setlname(string);
	void setAge(int); void setGender(int); int getUserId() const;
	void print() const; void readInput(); bool findAny(string) const;
};


