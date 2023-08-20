#include<iostream>
#include<fstream>
#include "SystemUser.h"
#include "Classroom.h"
using namespace std;
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
// class assignment design
class Assignment:public VirtualClassroom
{
protected:
    int m, t, s;
    string MCQS[15];
    string TF[15];
    string subjective[20];
    string AnswersMCQ[15], AnswersTF[15], subjective_answers[50];
    string* choices;
    string correct_option;
    int totalQuestions;
    string userAnswer;
    VirtualClassroom classroom;
public:
    Assignment(); // default contructor 
    fstream ReadQuestionsFile(); 
    void addQuestions(); // add questions to assignment
    int getTotalQuestions(); // getter
    void setTotalQuestions(); // setter
    void viewQuestions(); // view the assignment
    void OpenFile(fstream&);
    void UploadAssignment();
    void AccessAssignment();
    void CalculateScore();
    void DisplayResult();
};
#endif