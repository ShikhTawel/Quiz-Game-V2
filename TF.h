#ifndef ASS2_TF_H
#define ASS2_TF_H
#include "Question.h"
#include <bits/stdc++.h>
using namespace std;

class TF : public Question
{
private:
    int counter = 0;
    static int TF_num;
    int  Q_ID;
public:
    TF(){TF_num++; Q_ID = Q_num;}
    int getQuestionNumber()
    {
        return TF_num;
    }
    void setID(int ID)
    {
        Q_ID = ID;
    }
    int getID()
    {
        return Q_ID;
    }
    friend ostream &operator << (ostream &out, TF& source);
};
int TF:: TF_num = 0;
ostream &operator << (ostream &out, TF& source)
{
    out<<"["<<++source.printedIDX<<"]"<<"(ID: "<<source.Q_ID<<") "<<source.question_text<<"\tAnswer: "<<source.correct_answer<<"\n";
    return out;
}



#endif //ASSIGNMENT_2_TF_H
