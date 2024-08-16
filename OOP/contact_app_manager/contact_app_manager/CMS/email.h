#pragma once
#include <string>
using namespace std;
class email {
	string m_email;
	string m_type;
	string m_description;
public:
	email();
	email(string, string, string);
	virtual ~email();
	void setEmail(string);
	void setType(string);
	void setDesc(string);
	bool is_Matched(string);
	void print() const;
};


