#include<bits/stdc++.h>
#include <vector>
#include <iomanip>

#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "Complete.h"
#include "MCQ.h"
#include "TF.h"

using namespace std;
vector<Admin>Alladmins;
vector<Player>Allplayers;
vector<Complete> complete;
vector<MCQ> mcq;
vector<TF> tf;
vector<int> scores;
Question questions;
int score = 0;


//View all admins and players in the AllAdmins & AddPlayers vectors
void viewUsers(){
    cout<<"FirstName\t\t"<<"LastName\t\t"<<"UserName\t\t"<<"Role\t\t\n";
    for(int i=0;i<Alladmins.size();i++) {
        cout<<Alladmins[i].getFirstName()<<"\t \t"<<Alladmins[i].getLastName()<<"\t \t"<<Alladmins[i].getUserName()<<"\t \t"<<Alladmins[i].getRole()<<"\t \t \n";
    }
    for(int i=0;i<Allplayers.size();i++) {
        cout<<Allplayers[i].getFirstName()<<"\t \t"<<Allplayers[i].getLastName()<<"\t \t"<<Allplayers[i].getUserName()<<"\t \t"<<Allplayers[i].getRole()<<"\t \t \n";
    }
}
//To add new admin in the AllAdmins vector
void addNewAdmin(){
    cout<<"Please enter the Admin's information"<<endl;
    string tempp;
    Admin temp;
    cout<<"Enter First Name: ";
    cin>>tempp;
    temp.setFirstName(tempp);
    cout<<"Enter Last Name: ";
    cin>>tempp;
    temp.setLastName(tempp);
    temp.setRole("Admin");
    usernmadmin:
    cout<<"Enter UserName: ";
    cin>>tempp;
    for(int i=0;i<Alladmins.size();i++)
        if(Alladmins[i]==tempp){
            cout<<"Already Used Username \n";
            goto usernmadmin;
        }
    temp.setUserName(tempp);
    cout<<"Enter Password: ";
    cin>>tempp;
    temp.setPassword(tempp);
    Alladmins.push_back(temp);
}
//To add new admin in the AllPlayers vector
void addNewPlayer(){
    cout<<"Please enter the Player's information"<<endl;
    string tempp;
    Player temp;
    cout<<"Enter First Name: ";
    cin>>tempp;
    temp.setFirstName(tempp);
    cout<<"Enter Last Name: ";
    cin>>tempp;
    temp.setLastName(tempp);
    temp.setRole("Player");
    userplayer:
    cout<<"Enter UserName: ";
    cin>>tempp;
    for(int i=0;i<Allplayers.size();i++)
        if(Allplayers[i]==tempp){
            cout<<"Already Used Username \n";
            goto userplayer;
        }
    temp.setUserName(tempp);
    cout<<"Enter Password: ";
    cin>>tempp;
    temp.setPassword(tempp);
    Allplayers.push_back(temp);
}
//To check if the username and password does exist or not in the AllAdmins vector
int checkAdmin(string user,string pw){
    for(int i=0;i<Alladmins.size();i++) {
        if (Alladmins[i].getUserName() == user && Alladmins[i].getPassword() == pw){
            return i;
        }
    }
    return -1;
}
//To check if the username and password does exist or not in the AllPlayers vector
int checkPlayer(string user,string pw){

    for(int i=0;i<Allplayers.size();i++) {
        if (Allplayers[i].getUserName() == user && Allplayers[i].getPassword() == pw){
            return i;
        }
    }
    return -1;
}

string Str_ignore_case(string cmp)
{
    for (int i = 0; i < cmp.length(); i++)
    {
        cmp[i] = toupper(cmp[i]);
    }
    return cmp;
}

void randomMcq(int questionNum)
{
    cout<<"Multiple Choice Questions: "<<endl;
    string printedQ;
    string printedA;
    string yourAnswer;
    for (int i=0; i<questionNum;)
    {
        RandomQ:
        int counterQ = rand()% complete.size();
        size_t foundQ = printedQ.find(to_string(counterQ));

        if (foundQ != string::npos)
        {
            goto RandomQ;
        }
        cout<<complete.at(counterQ).getQuestionText()<<endl;
        printedQ += to_string(counterQ);


        for (int j=0; j<4;)
        {
            RandomA:
            int counterA = rand()% 4;
            size_t foundA = printedA.find(to_string(counterQ));
            if (foundA != string::npos)
            {
                goto RandomA;
            }
            cout<<"["<<char(j+65)<<"] "<<mcq.at(counterQ).getAnswer(counterA);
            j++;
        }
        cin>>yourAnswer;
        yourAnswer=Str_ignore_case(yourAnswer);
        if (yourAnswer == Str_ignore_case(complete.at(counterQ).getCorrectAnswer()))
        {
            score++;
        }
        i++;
    }
}

void randomComplete(int questionNum)
{
    cout<<"Complete Questions: "<<endl;
    string printedQ;
    string yourAnswer;
    for (int i=0; i<questionNum;)
    {
        RandomQ:
        int counter = rand()% complete.size();
        size_t foundQ = printedQ.find(to_string(counter));

        if (foundQ != string::npos)
        {
            goto RandomQ;
        }
        cout<<complete.at(counter).getQuestionText()<<endl;
        printedQ += to_string(counter);
        cin>>yourAnswer;
        yourAnswer=Str_ignore_case(yourAnswer);
        if (yourAnswer == Str_ignore_case(complete.at(counter).getCorrectAnswer()))
        {
            score+=2;
        }
        i++;
    }
}

void randomTf(int questionNum)
{
    cout<<"True or False Questions: "<<endl;
    string printedQ;
    string yourAnswer;
    for (int i=0; i<questionNum;)
    {
        RandomQ:
        int counter = rand()% mcq.size();
        size_t foundQ = printedQ.find(to_string(counter));

        if (foundQ != string::npos)
        {
            goto RandomQ;
        }
        cout<<mcq.at(counter).getQuestionText()<<endl;
        printedQ += to_string(counter);
        cin>>yourAnswer;
        yourAnswer=Str_ignore_case(yourAnswer);
        if (yourAnswer == Str_ignore_case(mcq.at(counter).getCorrectAnswer()))
        {
            score++;
        }
        i++;
    }
}

void Quiz()
{
    cout<<"--------------------QUIZ STARTED--------------------"<<endl;
    if (complete.size() < 4 || mcq.size() < 1 || tf.size() < 1)
    {
        cout<<"***There isn't sufficient number of Questions yet***\n";
    }
    else
    {
        int degree = 10;
        int completeNum = (rand()% 3) + 1;
        degree = degree - completeNum*2;
        int mcqNum = (rand()% (degree-2)) + 1;
        degree = degree - mcqNum*1;
        int tfNum = (rand()% (degree-2)) + 1;

        randomComplete(completeNum);
        randomMcq(mcqNum);
        randomTf(tfNum);
        scores.push_back(score);
        cout<<"Your Score is "<<score<<"/10\n";
        score = 0;
    }
}

void deleteQuestion(int ID)
{
    int idxFound=0;
    for (int i=0; i<mcq.size(); i++)
    {
        if (ID==mcq.at(i).getID())
        {
            idxFound++;
            mcq.erase(mcq.begin()+(ID-1));
            break;
        }
    }
    if (idxFound!=1)
    {
        for (int i=0; i<complete.size(); i++)
        {
            if (ID==complete.at(i).getID())
            {
                idxFound++;
                complete.erase(complete.begin()+(ID-1));
                break;
            }
        }
    }
    if (idxFound!=1)
    {
        for (int i=0; i<tf.size(); i++)
        {
            if (ID==tf.at(i).getID())
            {
                idxFound++;
                tf.erase(tf.begin()+(ID-1));
                break;
            }
        }
    }
    if (idxFound!=1)
    {
        cout<<"***ID Not found***"<<endl;
        return;
    }
    return;
}

void viewAllQuestion()
{
    if(questions.getQuestionNumber()==1){
        cout<<"There is No Questions \n";
        return;
    }
    cout << "Number of Questions available: " << questions.getQuestionNumber() <<endl<<endl;

    cout<<"Number of MCQs: "<<mcq.at(0).getQuestionNumber()<<"\n";
    cout<<"------------------------------------------\n";

    for (int i = 0; i < mcq.size(); i++)
    {
        cout << mcq.at(i);
    }
    cout<<"------------------------------------------------\n";
    cout<<"Number of TF Questions: "<<tf.at(0).getQuestionNumber()<<"\n";
    cout<<"------------------------------------------\n";
    for (int i = 0; i < tf.size(); i++)
    {
        cout << tf.at(i);
    }
    cout<<"------------------------------------------------\n";
    cout<<"Number of Complete Questions: "<<complete.at(0).getQuestionNumber()<<"\n";
    cout<<"------------------------------------------\n";
    for (int i = 0; i < complete.size(); i++)
    {
        cout << complete.at(i);
    }
    cout<<"------------------------------------------------\n";
    char option;
    cout<<"Type [d] and the question ID if you want to delete a question.\n";
    cout<<"Type [b] if you want to go back to the main menu.\n";
    ValidOption:
    cin>>option;
    if (toupper(option) == 'D')
    {
        int ID;
        cin>>ID;
        deleteQuestion(ID);
    }
    else if (toupper(option)=='B')
    {
        //MainMenu();
    }
    else
    {
        cout<<"***Enter valid option***\n";
        goto ValidOption;
    }
}

void addNewQuestion()
{
    int correctAnsCount =0;
    string inputQType, inputQText, inputCorrectAns, inputAnswer;
    string temp;

    cout << "Please Enter the Question Type (TF-COMPLETE-MCQ)" << endl;
    Valid_Qtype:
    cin >> inputQType;
    inputQType = Str_ignore_case(inputQType);
    if (inputQType == "MCQ")
    {
        MCQ tempMCQ;
        cin.ignore();
        cout << "Enter the question: " << endl;
        getline(cin, inputQText);
        tempMCQ.setQuestionText(inputQText);
        CorrectAnswerMCQ:
        cout << "Enter 4 Answers with only one correct answer marked by \'*\': " << endl;
        for (int i = 0; i < 4; i++)
        {
            getline(cin, inputAnswer);
            if (inputAnswer.at(0)=='*')
            {
                correctAnsCount++;
                tempMCQ.setCorrectAnswer(inputAnswer.substr(1,inputAnswer.length()));
            }
            tempMCQ.setAnswers(inputAnswer, i);
        }
        if (correctAnsCount!=1)
        {
            cout<<"***Enter one and only one correct answer***\n\n";
            correctAnsCount=0;
            goto CorrectAnswerMCQ;
        }
        mcq.push_back(tempMCQ);
    }
    else if (inputQType == "TF")
    {
        TF tempTF;
        cin.ignore();
        cout << "Enter the question: " << endl;
        getline(cin, inputQText);
        tempTF.setQuestionText(inputQText);
        CorrectAnswerTF:
        cout << "Enter the correct Answer: " << endl;
        cin>>inputCorrectAns;
        temp = Str_ignore_case(inputCorrectAns);
        if (temp != "TRUE" && temp != "FALSE")
        {
            cout<<"***Correct answer can be only True or False***\n";
            goto CorrectAnswerTF;
        }
        tempTF.setCorrectAnswer(inputCorrectAns);
        tf.push_back(tempTF);
    }
    else if (inputQType == "COMPLETE")
    {
        Complete tempCom;

        cin.ignore();
        CorrectAnswerComplete:
        cout << "Enter the question: " << endl;
        getline(cin, inputQText);
        int dotCount = 0;
        for (int i = 1; i < inputQText.length() - 1; i++)
        {
            if (inputQText.at(i) != '.' && inputQText.at(i + 1) == '.')
            {
                dotCount++;
            }
        }
        if (dotCount != 1)
        {
            cout << "***Enter valid Question with ..... exists only once***" << endl;
            goto CorrectAnswerComplete;
        }
        tempCom.setQuestionText(inputQText);
        cout << "Enter the correct Answer: " << endl;
        getline(cin, inputCorrectAns);
        tempCom.setCorrectAnswer(inputCorrectAns);
        complete.push_back(tempCom);
    }
    else
    {
        cout << "***Enter valid question type***" << endl;
        goto Valid_Qtype;
    }
}

void loadFromFile(string filePath)
{
    ifstream input_file;
    input_file.open(filePath);
    if (!input_file.is_open())
    {
        cout << " Failed to open\n";
        return;
    }
    else
    {

        MCQ tempMCQ;
        TF tempTF;
        Complete tempCom;

        cout << "Opened OK\n";
        string lines;
        while (!input_file.eof())
        {
            getline(input_file, lines);
            if (lines == "MCQ")
            {
                getline(input_file, lines);
                tempMCQ.setQuestionText(lines);
                getline(input_file, lines);
                tempMCQ.setCorrectAnswer(lines);
                for (int i = 0; i < 4; i++)
                {
                    tempMCQ.setAnswers(lines, i);
                    getline(input_file, lines);
                }
                mcq.push_back(tempMCQ);
            }
            else if (lines == "TF")
            {
                tempTF.setQuestionText(lines);
                getline(input_file, lines);
                tempTF.setCorrectAnswer(lines);
                tf.push_back(tempTF);
            }
            else if (lines == "COMPLETE")
            {
                tempCom.setQuestionText(lines);
                getline(input_file, lines);
                tempCom.setCorrectAnswer(lines);
                complete.push_back(tempCom);
            }
            input_file.close();
            cout <<"Questions File Was Loaded Successfully"<<endl;
        }
    }
}


int main() {
    Admin temp1;
    Player temp2;
    Alladmins.push_back(temp1);
    Allplayers.push_back(temp2);

    string usernm, pass;
    int testAdmin,testPlayer;
    cout << "******************************************************************* " <<endl;
    cout << "\t \t Welcome to the Quiz game program V2.0! " <<endl;
    cout << "******************************************************************* " <<endl;
    Return1:
    cout << "Please enter your username: _ \n";
    cin >>usernm;
    cout << "Please enter your Password: _ \n";
    cin >>pass;

    testAdmin = checkAdmin(usernm, pass);//test admin take the index of the admin in the AllAdmins vectors
    testPlayer = checkPlayer(usernm, pass);//test player take the index of the player in the AllPlayers vectors

    if (testAdmin == -1 && testPlayer == -1) {//the username and password are invalid
        cout << "Invalid User \n";
        goto Return1;
    }
////////////////////////////////////////////////////////////////////////////////////////////////
    else if(testPlayer==-1){//Enter the admin's menu
        Admin admon=Alladmins[testAdmin];
        int adminchoice;
        do {
            adminchoice =admon.adminMenu(admon);
            if (adminchoice == 1)//switch accounts
                goto Return1;
            else if (adminchoice == 2) {//update name
                Alladmins[testAdmin].updateName();
            } else if (adminchoice == 3)// to view all users
            {
                viewUsers();
            } else if (adminchoice == 4)// add new user
            {
                int choice2;
                AdminOrPlayer:
                cout << "[1] Admin"<<endl<< "[2] Player \n";
                cin >> choice2;
                if(choice2<1&&choice2>2){
                    cout<<"You enterd a wrong choice"<<endl;
                    goto AdminOrPlayer;
                }
                else if (choice2 == 1)
                    addNewAdmin();
                else if (choice2 == 2)
                    addNewPlayer();
            } else if (adminchoice == 5)//View all question --->beta3t amr we zoz
            {
                viewAllQuestion();
            } else if (adminchoice == 6)//Add new question --->beta3t amr we zoz
            {
                addNewQuestion();
            } else if (adminchoice == 7)//Load questions from file
            {
                string filenm;
                cout<<"Enter File Name With Extention";
                cin.ignore(); getline(cin,filenm);
                loadFromFile(filenm);
            } else if (adminchoice == 8)//Exit the program
            {
                cout<<"Quiz Ended"<<endl;
                return 0;
            }

        }while(true);
    }
//////////////////////////////////////////////////////////////////////////////////////////
    else if (testAdmin==-1) {//Enter the Player's menu
        Player player;
        player=Allplayers[testPlayer];
        do {
            int playerchoice = player.playerMenu(player);
            if (playerchoice == 1)//Switch accounts
                goto Return1;
            else if (playerchoice == 2)//Update name
            {
                Allplayers[testPlayer].updateName();
            } else if (playerchoice == 3)//Start new quiz
            {
                Quiz();
            } else if (playerchoice == 4)//Display score stat
                player.displayScoreStats();

            else if (playerchoice == 5)//Display all scores
                player.displayALLScores();

            else if (playerchoice == 6)//display last two scores
                player.displayLastTwoScores();
            else if (playerchoice == 7) {
                cout<<"Quiz Ended"<<endl;
                return 0;
            }
        }while(true);
    }
    return 0;

}