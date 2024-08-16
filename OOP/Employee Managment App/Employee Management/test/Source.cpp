#include<iostream>
#include "StaffMember.h"
#include"Staff.h"
#include"S_Employee.h"
#include"H_Employee.h"
#include"Executive.h"
#include"CreateProject.h"
#include<Windows.h>
#include"department.h"
using namespace std;
Staff staff(50);
department* dep = new department[100];
CreateProject proj(50);
auto depart_counter = 0;
int c = -1; int scc = -1;
int remain() {
    int opt;
    cout << "\n[1] Main Menue\t\t[2] Nested Menu\t\t[0] Exit\n"
        << "..::Enter the Choice:";
    cin >> opt;
    if (opt == 0) {
        system("cls");
        cout << "\n\n\n\t\t\tTHANK YOU FOR YOUR REGESTRATION." << endl;
        return 1;
    }
    else if (opt == 1)
        return -1;
}
void department_handle() {
    int choice = -1;
    int id = 1000;
    int count = 0;
    char ch = 'y';
    string name;
    while (choice != 0) {
        system("cls");
        cout << "\n\n Department Menue";
        cout << "\n=====================\n" << "[1] Add New Department\n" << "[2] Show All Departments\n"
            << "[0] Quit\n" << "\n=====================\n" << "Enter your choice: ";
        cin >> choice;
        if (choice == 0) break;
        else if (choice == 1) {
            do {
                system("cls");

                cout << "\n Enter Department Name: "; cin >> name;
                dep[count++].setDepIdName(++id, name);
                depart_counter++;

                cout << "\n Would You Lke To Add Another Department: (y/n)? "; cin >> ch;
            } while (ch == 'y' || ch == 'Y');
            int opt;
            cout << "\n[1] Main Menue\t\t[2] Nested Menu\t\t[0] Exit\n"
                << "..::Enter the Choice:";
            cin >> opt;
            switch (opt)
            {
            case 1 || 0:
                return;
            case 2:
                break;
            default:
                break;
            }
        }
        else if (choice == 2) {
            system("cls");
            cout << endl;
            for (size_t i = 0; i < count; i++)
            {
                dep[i].print();
                cout << "-------------------------------------------------------------------------\n";
            }
            if (depart_counter == 0) cout << "\n No Department Found...!!):\n";
            else cout << depart_counter << " Departments Founded\n";
            int opt;
            cout << "\n[1] Main Menue\t\t[2] Nested Menu\t\t[0] Exit\n"
                << "..::Enter the Choice:";
            cin >> opt;
            switch (opt)
            {
            case 1 || 0:
                return;
            case 2:
                break;
            default:
                break;
            }
        }
        else {
            cout << " Invalid Chioce!!";
            Sleep(3000);
        }
    }
}
int main() {

    system("cls");
    system("Color 0B");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t   ------------------------------------------"
        << "\n\n\t\t\t\t     * WELCOME TO EMPLOYEE MANAGMENT SYSTEM  *"
        << "\n\n\t\t\t\t  ============================================="; cout << "\n\t\t\t\t\t "; system("pause");
    while (c != 0) {
        system("cls"); system("Color 0B");
        cout << "\n EMPLOYEE MANAGEMENT SYSTEM"; cout << "\n\n MAIN MENU";
        cout << "\n=====================\n";
        cout << "[1] Department\n" << "[2] Staff\n" << "[3] Project\n" << "[0] Quit\n";
        cout << "\n=====================\n";
        cout << "Enter your choice: "; cin >> c; system("cls");
        switch (c) {
        case 1:
            department_handle();
            break;
        case 2:
            while (scc != 0) {
                system("cls"); cout << "\n\n Staff Menue";
                cout << "\n=====================\n" << "[1] Add New Meber\n" << "[2] Search Meber\n" << "[3] delete Meber\n"
                    << "[4] Show All Mebers\n" << "[5] CalcPyRoll\n"
                    << "[0] Quit\n" << "\n=====================\n" << "Enter your choice: "; cin >> scc; system("cls");
                if (scc == 1) {
                    staff.AddNewMember(dep, depart_counter);
                    int rem = remain(); if (rem == 1) exit(0);
                    else if (rem == -1)
                        break; else continue;
                }
                else if (scc == 4) {
                    staff.printAllMebers();
                    int rem = remain();
                    if (rem == 1) exit(0);
                    else if (rem == -1) break;
                    else continue;
                }
                else if (scc == 2) {
                    staff.SearchMember();
                    int rem = remain();
                    if (rem == 1) exit(0);
                    else if (rem == -1) break;
                    else continue;
                }
                else if (scc == 3) {
                    staff.deleteMember();
                    int rem = remain();
                    if (rem == 1) exit(0);
                    else if (rem == -1) break;
                    else continue;
                }
                else if (scc == 5) {
                    system("cls");
                    staff.calcPayRoll();
                    int rem = remain();
                    if (rem == 1) exit(0);
                    else if (rem == -1) break;
                }
            }
            break;
        case 3:
            while (scc != 0) {
                system("cls");
                cout << "\n Project Menue"; 
                cout << "\n=====================\n"; 
                cout << "[1] Add New Project \n" << "[2] Show All Projects \n" 
                    << "[3] Incresse Project Budget Value \n" << "[0] Quite \n";
                cout << "\n=====================\n"; 
                cout << "Enter Choice: "; cin >> scc;
                if (scc == 1) { system("cls"); 
                proj.addNewProject(); 
                int rem = remain(); if (rem == 1) exit(0); else if (rem == -1) break; else continue; }
                else if (scc == 2) { system("cls"); 
                proj.showAllProject();
                int rem = remain(); if (rem == 1) exit(0); else if (rem == -1) break; else continue; }
                else if (scc == 3) {system("cls");int _id;
                    cout << " Enter Project Id: "; cin >> _id;
                    proj.incrProjBud(_id); int rem = remain(); if (rem == 1) exit(0); else if (rem == -1) break; else continue;
                }
            }
            break;
        default:
            cout << " \n\n\n\tInvalid Chioce!!\n\tWait for seconds And Enroll Again\n";
            Sleep(3000);
            break;
        }
    }
    system("cls");
    cout << "\n\n\n\t\t\tThank you." << endl << endl;
    exit(0);
   return 0; 
}
