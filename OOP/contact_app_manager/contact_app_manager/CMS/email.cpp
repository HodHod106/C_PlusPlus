#include "email.h"
#include<iostream>
email::email() {}
email::email(string email, string type, string desc) {
	setEmail(email); setType(type); setDesc(desc);
}
email::~email() {}
void email::setEmail(string email) { m_email = email; }
void email::setType(string type) { m_type = type; }
void email::setDesc(string desc) { m_description = desc; }
bool email::is_Matched(string key) { return (m_email.compare(key) == 0); }
void email::print() const
{
	cout << "Email: " << m_email << "\t | " << m_type <<
		"\t | " << m_description << endl;
}