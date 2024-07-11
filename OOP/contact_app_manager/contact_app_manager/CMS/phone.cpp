#include "phone.h"
#include<iostream>
using namespace std;
phone::phone() {}
phone::phone(string phone, string type, string desc)
{
	setPhone(phone); setType(type); setDesc(desc);
}
phone::~phone() {};
void phone::setPhone(string phone) { m_phone = phone; }
void phone::setType(string type) { m_type = type; }
void phone::setDesc(string desc) { m_description = desc; }
bool phone::is_Matched(string key) const
{
	return (m_phone.compare(key) == 0);
}
void phone::print() const {
	cout << "phone: " << m_phone << "\t | " << m_type <<
		"\t | " << m_description << endl;
}
