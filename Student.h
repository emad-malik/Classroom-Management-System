#include <iostream>
#include <vector>
using namespace std;
#ifndef STUDENT_H
#define STUDENT_H
#include "Classroom.h"

// class design for student class(relation with user class)
class Student: public VirtualClassroom
{
private: 
int studentAge;
string program_enrolled;
int current_semester;
char current_status;
long int student_CNIC;
string date_ofBirth;
public: 
bool student_authorized;
Student(); // default constructor
Student(int, string,int, char, long int, string); // 4-parameter constructor
Student(const Student&); // copy constructor
/* getters/setters for members */
int getAge() const;
void setAge(int);
string getProgram() const;
void setProgram(string);
int getSemester() const;
void setSemester(int);
char getStatus() const;
void setStatus(char);
long int getCNIC() const;
void setCNIC(long int);
string getDOB() const;
void setDOB(string);
virtual void SystemLogin();
bool validateCode(); // class code validation
void JoinClass(); // student enrollment
void LeaveClass(); // unenrol
};
#endif