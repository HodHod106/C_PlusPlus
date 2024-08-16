#include "Product.h"
Product::Product():m_id(0),m_price(0.0),m_name("No_Product_Name_Added"),
m_serial_num("No_Product_SerialNumber_Added"),m_type("No_Product_Type_Added"){}

void Product::setProductDetails(unsigned int id, string name, string ser, string type, double pr){
	m_id = id; m_name = name; m_serial_num = ser; m_type = type; m_price = pr;
}

ostream& operator<<(ostream& out, Product& pr)
{
	out << pr.m_id << " " << pr.m_name << "|" << pr.m_serial_num << "|" << pr.m_type << "|" << pr.m_price;
	return out;
}

istream& operator>>(istream& in, Product& pr){
	in.ignore();
	cout << "Name:  ";
	getline(in, pr.m_name);
	cout << "SeraiL Number:  ";
	getline(in, pr.m_serial_num);
	cout << "Type:  ";
	getline(in, pr.m_type);
	cout << "price:  ";
	in >> pr.m_price;
	return in;
}
