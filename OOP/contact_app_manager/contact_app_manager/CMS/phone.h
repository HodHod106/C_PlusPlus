#pragma once
#include <string>
using namespace std;
class phone {
	string m_phone; string m_type; string m_description;
public:
	phone(); phone(string phone, string type, string desc); virtual ~phone();
	void setPhone(string); void setType(string); void setDesc(string);
	bool is_Matched(string) const; void print() const;
};

