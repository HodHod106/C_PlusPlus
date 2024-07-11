#include "StaffMember.h"
#include<iostream>
using namespace std;
StaffMember::StaffMember():fName("No Name"),age(0),gender("No Gender Added"){
	setName(fName, lName);setEmpId(empid);setAge(age);setGender(gender);}
StaffMember::~StaffMember(){}
void StaffMember::setName(string fname, string lname) {fName = fname;lName = lname;}
void StaffMember::setEmpId(int id) {empid = id;}
int StaffMember::getId() { return empid; }
void StaffMember::setAge(int age) { this->age = age;}
void StaffMember::setGender(bool gend) { gender = gend;}

bool StaffMember::search(string key){
    if (fName.compare(key) == 0 || lName.compare(key) == 0 || phone.compare(key) || email.compare(key))
		return true;
	return false;
}

void StaffMember::readInput()
{
	cout << " \n First Name: ";cin.ignore(); cin >> fName;
	cout << " Last Name: "; cin >> lName;
	cout << " Age: ";cin >> age;
	cout << " Enter '0' For Male And '1' For Female: ";cin >> gender;
    cout << " Enter Your Phone Number: "; cin >> phone;
    cout << " Enter Your Email: "; cin >> email;

}

void StaffMember::print()
{
    cout << "\nId: " << empid << "\tName: " << fName << " " << lName;
    if (age > 0) {
        cout << "\t\tAge: " << age;
    }
    if (gender == 0)  cout << " \tGender: Male";
    else cout << " \tGender: Female";
	cout << "\n\tPhone: " << phone;
	cout << "\t\tEmail: " << email;
	cout << "\n\tDepartment: " << depart->getName() << endl;
}
void StaffMember::setDepart(department *depart) { 
	this->depart = depart;
}

