#ifndef ASS2_MCQ_H
#define ASS2_MCQ_H
#include "Question.h"
#include <bits/stdc++.h>
using namespace std;

class MCQ : public Question
{
private:
    vector<string> Answers{4};
    int counter = 0;
    static int MCQ_num;
    int  Q_ID;
public:
    MCQ(){MCQ_num++;Q_ID = Q_num;}
    void setAnswers(string answer,int idx) {
        Answers.at(idx) = answer;
        counter++;
    }
    int getQuestionNumber()
    {
        return MCQ_num;
    }
    string getAnswer(int idx)
    {
        return Answers.at(idx);
    }
    void setID(int ID)
    {
        Q_ID = ID;
    }
    int getID()
    {
        return Q_ID;
    }
    friend ostream &operator << (ostream &out, MCQ& source);
};
int MCQ:: MCQ_num = 0;
ostream &operator << (ostream &out, MCQ& source)
{
    out<<"["<<++source.printedIDX<<"]"<<"(ID: "<<source.Q_ID<<") "<<source.question_text<<"\n";
    for (int i=0; i<4;i++)
    {
        out<<char(i+65)<<source.Answers[i]<<"\t";
    }
    out<<endl;
    return out;
}
#endif //ASSIGNMENT_2_MCQ_H
