#ifndef ASS2_COMPLETE_H
#define ASS2_COMPLETE_H
#include "Question.h"
#include <bits/stdc++.h>
using namespace std;

class Complete : public Question
{
private:
    static int Com_num;
    int  Q_ID;
public:
    Complete()
    {
        Com_num++;
        Q_ID = Q_num;
    }
    int getQuestionNumber()
    {
        return Com_num;
    }
    void setID(int ID)
    {
        Q_ID = ID;
    }
    int getID()
    {
        return Q_ID;
    }
    friend ostream &operator << (ostream &out,  Complete& source);
};
int Complete::Com_num = 0;
ostream &operator << (ostream &out,  Complete& source)
{
    out<<"["<<++source.printedIDX<<"]"<<"(ID: "<<source.Q_ID<<") "<<source.question_text<<"\tAnswer: "<<source.correct_answer<<"\n";
    return out;
}

#endif
