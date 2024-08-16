#include "Customer.h"
Customer::Customer()
{
    c_id = 0;
    c_phone = "NO PHONE ADDED";
}
string Customer::print()
{
    return to_string(c_id) + ' ' + c_phone;
}
void Customer::read()
{
    cout << "Phone: "; cin >> c_phone;
}
void Customer::setId(int id)
{
    c_id = id;
}
string Customer::getInfo()
{
    return " "+to_string(c_id) + "\t" + c_phone + "\t";
}
