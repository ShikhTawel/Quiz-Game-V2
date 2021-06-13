#ifndef ASS2_Question_H
#define ASS2_Question_H
#include <bits/stdc++.h>
using namespace std;

class Question
{
protected:
    string question_text;
    string correct_answer;

    static int Q_num;
    static int printedIDX;
public:

    Question()
    {
        Q_num++;
    }
    void setQuestionText(string _text)
    {
        question_text=_text;
    }
    string getQuestionText()
    {
        return question_text;
    }
    virtual int getQuestionNumber()
    {
        return Q_num;
    }
    void setCorrectAnswer(string _ans)
    {
        correct_answer=_ans;
    }
    string getCorrectAnswer()
    {
        return correct_answer;
    }

    /*  Question addQuestion(Question temp) {
          string inputQType, inputQText, inputCorrectAns;

          cout << "Please Enter the Question Type (TF-COMPLETE-CHOOSE)" << endl;
          Valid_Qtype:
          cin >> inputQType;
          inputQType = Str_ignore_case(inputQType);
          cout << "Please Enter the Question: ";
          temp.setQuestionText(inputQText);
          cout << "Please Enter the correct Answer";
          temp.setCorrectAnswer(inputCorrectAns);
          return  temp;
      }*/
    void deleteQuestion()
    {
        Q_num--;
    }

    /* friend Question &operator << (ostream out, const Question& source)
     {
         out<<"Number of questions: "<<source.Q_num<<"\n";
         out<<"------------------------------------------\n";

     }*/
};
int Question::Q_num=0;
int Question::printedIDX=0;
#endif //ASSIGNMENT_2_QUESTION_H
