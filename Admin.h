#ifndef ASS2_ADMIN_H
#define ASS2_ADMIN_H

#include<iostream>
#include "User.h"
#include<algorithm>
using namespace std;

class Admin: public User {

public:
    vector<double> Stats;

    Admin() : User("Ahmed", "ShikhTawel", "Admin", "ShikhTawel", "123") {}

    Admin(string first,string last,string rol,string user,string pass){
        User(first,last,rol,user,pass);
    }

    //setters and getters
    void setUserName(string usernm) { username = usernm; }

    void setPassword(string pw) { password = pw; }

    void setFirstName(string firstnm) { firstname = firstnm; }

    void setLastName(string ln) { lastname = ln; }

    void setRole(string rl) { role = rl; }

    string getUserName() { return username; }

    string getPassword() { return password; }

    string getFirstName() { return firstname; }

    string getLastName() { return lastname; }

    string getRole() { return role; }

    /*Admin operator =(Admin &temp){
        temp.firstname=firstname;
        temp.lastname=lastname;
        temp.role=role;
        temp.password=password;
        temp.username=username;
        return Admin(temp);
    }*/

    //Admin main menu
    int adminMenu(Admin admon) {
        int choice;
        cout << "Welcome user " << admon.getFirstName() << "(ADMIN), please choose from the following options: \n";
        cout << "\t [1] Switch accounts \n";
        cout << "\t [2] Update your name \n";
        cout << "\t [3] View all users \n";
        cout << "\t [4] Add new user \n";
        cout << "\t [5] View all questions \n";
        cout << "\t [6] Add new question \n";
        cout << "\t [7] Load questions from file \n";
        cout << "\t [8] Exit the program \n";
        cout << "My choice: _ ";
        checkchoice:
        cin >> choice;
        if (choice > 8 || choice < 1) {
            cout << "Invalid Choice 1~8 \n";
            goto checkchoice;
        }
        return choice;
    }
    void updateName() {
        string fn, ln;
        cout << "Enter First Name: ";
        cin >> fn;
        cout << "Enter Last Name: ";
        cin >> ln;
        setFirstName(fn);
        setLastName(ln);
    }
    void copyData(Admin m){
        firstname=m.firstname;
        lastname=m.lastname;
        role=m.role;
        password=m.password;
        username=m.username;
    }
};
#endif //ASS2_ADMIN_H
