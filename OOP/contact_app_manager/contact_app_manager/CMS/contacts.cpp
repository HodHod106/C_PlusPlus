#include "contacts.h"

contacts::contacts(int contact_size)
{
    size = contact_size;
    users = new user[size];
    count = 0;
}

contacts::~contacts()
{
    delete[] users;
}

void contacts::addNewUser() {
    user* newUser = new user();
    newUser->setUserId(count + 1);
    cout << "\nEnter User Information:- \n";
    cout << "================================ \n";
    newUser->readInput();
    users[count++] = *newUser;
}

void contacts::deleteUser(int user_id) {
    if (count == 0) {
        cout << "NO USER EXIST~!\n";
        return;
    }
    bool deleted = false;

    for (int i = 0; i < count; ++i) {
        if (users[i].getUserId() == user_id) {

            if (i == count - 1) {
                count--;
            }
            else {

                users[i] = users[count - 1];
                count--;
            }
            deleted = true;
            break;
        }
    }
    if (deleted) {
        cout << "USER DELETED SUCESSFULLY!\n";
    }
    else {
        cout << "NO USER EXIST\n";
    }
}
void contacts::editUser(int user_id) {
    if (count == 0) {
        cout << "NO USER EXIST~!\n";
        return;
    }
    bool edited = false;
    for (int i = 0; i < count; ++i) {
        if (users[i].getUserId() == user_id) {

            users[i].readInput();

            edited = true;
            break;
        }
    }
    if (edited) {
        cout << "USER EDITED SUCESSFULLY!\n";
    }
    else {
        cout << "NO USER EXIST\n";
    }
}
void contacts::print()const {
    if (count == 0) {
        cout << "NO USER FOUND!\n";
        return;
    }
    for (int i = 0; i < count; ++i) {
        users[i].print();
    }
}
void contacts::findAll(string key)const {
    int foundCounter = 0;
    for (int i = 0; i < count; ++i) {
        if (users[i].findAny(key)) {
            users[i].print();
            foundCounter++;
        }
    }
    if (foundCounter == 0) {
        cout << "NO USER FOUNDED!\n";
    }
    else {
        cout << foundCounter << "FOUNDED~\n";
    }
}