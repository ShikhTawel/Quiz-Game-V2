#ifndef USER_H
#define USER_H
#include<vector>
#include<string>
using namespace std;
class User
{
protected:
    string username;
    string password;
    string firstname;
    string lastname;
    string role;

public:

    User(){
        firstname="first name";
        lastname="last name";
        role="model";
        username="user";
        password="123";
    }
    User(string first,string last,string rol,string user,string pass){
        firstname=first;
        lastname=last;
        role=rol;
        username=user;
        password=pass;
    }
    virtual void setUserName(string username){}
    virtual void setPassword(string pw){}
    virtual void setFirstName(string firstname){}
    virtual void setLastName(string lastname){}
    virtual void setRole(string role){}
    virtual string getUserName(){return " ";}
    virtual string getPassword(){return " "; }
    virtual string getFirstName(){return " ";}
    virtual string getLastName(){ return " ";}
    virtual string getRole(){return " "; }
    bool operator ==(string temp){
        if(temp==username)
            return false;
        else
            return true;
    }
    void copyData(User temp){
        firstname=temp.firstname;
        lastname=temp.lastname;
        role=temp.role;
        password=temp.password;
        username=temp.username;
    }
};

#endif // USER_H
