#include<string>
#include<iostream>
using namespace std;
#pragma once
class Product{
	unsigned int m_id;
	string m_name, m_serial_num, m_type;
	double m_price;
public:
	Product();
	void setId(unsigned int id) { m_id = id; }
	unsigned int getId() const { return m_id; }
	string getName() const { return m_name; }
	string getserial() const { return m_serial_num; }
	string getType() const { return m_type; }
	double getprice() const { return m_price; }
	void setProductDetails(unsigned int id, string name, string ser, string type, double pr);
	friend ostream& operator<<(ostream& out, Product& pr);
	friend istream& operator>>(istream& in, Product& pr);
};

