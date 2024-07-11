#pragma once
#include <string>
using namespace std;
class address {
	string m_address, m_type, m_description;
public:
	address();
	address(string, string, string);
	~address();
	void setAddress(string);
	void setType(string);
	void setDesc(string);
	void print() const;
};

