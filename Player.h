#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include "User.h"
#include<algorithm>
using namespace std;

class Player: public User
{

public:
    vector<double>Stats;
    Player():User("Waleed","Elhamey","Player","AboKamal","123"){
    }
    Player(string first,string last,string rol,string user,string pass){
        User(first,last,rol,user,pass);
    }

    //setters and getters
    void setUserName(string usernm){username=usernm;}
    void setPassword(string pw){password=pw;}
    void setFirstName(string firstnm){firstname=firstnm; }
    void setLastName(string ln){lastname=ln;}
    void setRole(string rl){role=rl;}
    string getUserName(){return username;}
    string getPassword(){return password;}
    string getFirstName(){return firstname;}
    string getLastName(){return lastname;}
    string getRole(){return role;}

    void displayALLScores(){
        if(Stats.size()==0){
            cout<<"Sorry! you didn't take any quiezes yet"<<endl;
            return;
        }
        for(int i=0;i<Stats.size();i++)
            cout<<"Quiz"<<(i+1)<<Stats[i]<<endl;
    }
    void displayLastTwoScores(){
        if(Stats.size()==0){
            cout<<"Sorry! you didn't take any quizes yet"<<endl;
            return;
        }
        for(int i=(Stats.size()-1);i>(Stats.size()-3);i--)
            cout<<"Quiz"<<(i)<<Stats[i]<<endl;
    }
    void updateName(){
        string fn,ln;
        cout<<"Enter First Name: ";
        cin>>fn;
        cout<<"Enter Last Name: ";
        cin>>ln;
        setFirstName(fn);
        setLastName(ln);
    }
    void displayScoreStats(){
        int max=*max_element(Stats.begin(),Stats.end());
        int min=*min_element(Stats.begin(),Stats.end());
        if(Stats.size()==0){
            cout<<"Sorry! you didn't take any quiezes yet"<<endl;
            return;
        }
        cout<<"- Number of Quizzes taken: "<<Stats.size();
        cout<<"- Highest quiz score: "<<max<<endl;
        cout<<"- Lowest quiz score: "<<min;
        double Sum=0;
        for(int i=0;i<Stats.size();++i){
            Sum+=Stats[i];
        }
        cout<<"- Average quiz score:"<<Sum/Stats[Stats.size()-1];
    }
    /*Player operator =(Player &temp){
        temp.firstname=firstname;
        temp.lastname=lastname;
        temp.role=role;
        temp.password=password;
        temp.username=username;
        return Player(temp);
    }*/
    void copyData(Player m){
        firstname=m.firstname;
        lastname=m.lastname;
        role=m.role;
        password=m.password;
        username=m.username;
        }
    //Player main menu
    int playerMenu(Player player){
        int choice;
        cout<<"Welcome user "<<player.getFirstName()<<"(PLAYER), please choose from the following options: \n";
        cout<<"\t [1] Switch accounts \n";
        cout<<"\t [2] Update your name \n";
        cout<<"\t [3] Start a new quiz  \n";
        cout<<"\t [4] Display your scores statistics  \n";
        cout<<"\t [5] Display all your scores  \n";
        cout<<"\t [6] Display details of your last 2 quizzes  \n";
        cout<<"\t [7] Exit the program  \n";
        cout<<"My choice: _ ";
        checkchoice:
        cin>>choice;
        if(choice>7 || choice<1) {
            cout<<"Invalid Choice 1~8 \n";
            goto checkchoice;
        }
        return choice;
    }
};

#endif // PLAYER_H
