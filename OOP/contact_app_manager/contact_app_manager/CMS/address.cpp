#include "address.h"
#include<iostream>
address::address() {}
address::address(string add, string type, string desc) {
	setAddress(add);
	setType(type); setDesc(desc);
};
address::~address() {}
void address::setAddress(string address) { m_address = address; }
void address::setType(string type) { m_type = type; }
void address::setDesc(string desc) { m_description = desc; }
void address::print() const {
	cout << "Address: " << m_address << "\t | " << m_type <<
		"\t | " << m_description << endl;
}
