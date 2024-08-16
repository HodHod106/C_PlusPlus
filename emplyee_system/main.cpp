
#include<iostream>
#include<vector>
using namespace std;

struct employee{
    string names;
    int ages;
    double salaries;
    char genders;
};
vector<employee>emp;

int menu() {
    int choice = -1;
    while (choice == -1) {
        cout << "\nEnter your choice:\n";
        cout << "1) Add new employee\n";
        cout << "2) Print all employees\n";
        cout << "3) Delete by age\n";
        cout << "4) Update Salary by name\n";
        cout << "5) Exit\n";

        cin >> choice;

        if (!(1 <= choice && choice <= 5)) {
            cout << "Invalid choice. Try again\n";
            choice = -1;	// loop keep working
        }
    }
    return choice;
}

void read_employee() {
    string name;
    int age;
    double salary;
    char gender;
    cout << "Enter name: ";
    cin>>name;
    cout << "Enter age: ";
    cin >> age;

    cout << "Enter salary: ";
    cin >> salary;

    cout << "Enter gender (m/f): ";
    cin >> gender;
    emp.push_back({name,age,salary,gender});
}

void print_employees() {
    cout << "****************************\n";
    for(auto it : emp) {
        if(it.ages==-1) continue;
        cout << it.names << ' ' << it.ages << ' ' << it.salaries << ' ' << it.genders << endl;
    }
}

void delete_by_name() {
    cout << "Enter Employee Name to delete: ";
    string name; cin >>name;
    bool isdeleted = false;
    for (int i = 0; i < emp.size(); ++i) {
        if(emp[i].names==name){
            emp[i].names="Deleted";
            emp[i].ages=-1;
            emp[i].salaries=0.0;
            emp[i].genders='c';
            isdeleted=true;
            break;
        }
    }

    if(!isdeleted) cout<<"This Name can not be found!!";
    else cout<<"Deleted Successfully";
}

void update_salary_by_name() {
    cout << "Enter the name and salary: ";
    string name;
    int salary;
    cin >> name >> salary;

    bool is_found = false;
    for (int i = 0; i < emp.size(); ++i) {
        if(emp[i].names==name){
            emp[i].salaries=salary;
            is_found = true;
            break;
        }
    }
    if (!is_found)
        cout << "No employee with this name!\n";
    else cout<<"Uodated Succesfully";
    cout<<"**************************************************\n";
}



int main() {

    while (true) {
        int choice = menu();

        if (choice == 1)
            read_employee();
        else if (choice == 2)
            print_employees();
        else if (choice == 3)
            delete_by_name();
        else if (choice == 4)
            update_salary_by_name();
        else
            break;
    }
    return 0;
}
