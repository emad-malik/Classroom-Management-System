#include <iostream>
#include <fstream>
using namespace std;
#ifndef TEACHER_H
#define TEACHER_H
#include "SystemUser.h"
//class design for teacher(relation with user class)
class Teacher:public SystemUser
{
private: 
char employment_status;
int years_ofExperience;
public:
bool isAuthorised;
fstream credentials_file= fstream("teacher_database.dat", ios::in | ios::out);
Teacher(); // default constructor
Teacher(char, int); // parameter constructor
Teacher(const Teacher&); // copy constructor
/* getters/setters for members */ 
char getEmploymentStatus() const;
void setEmploymentStatus(char);
int getExperience() const;
void setExperience(int);
bool TeacherAuthentication();
virtual void SystemLogin();
};
#endif