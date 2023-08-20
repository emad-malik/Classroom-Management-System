#include <vector>
#ifndef VIRTUALCLASSROOM_H
#define VIRTUALCLASSROOM_H
#include "SystemUser.h"
// classroom management
class VirtualClassroom:public SystemUser
{
protected:
string className;
string subjectName;
string classCode;
string classDescription;
vector<string> studentRoster;
public:
VirtualClassroom(); // default constructor
VirtualClassroom(string, string, string, string); // constructor
void createClass(); // class creation function
void updateClass(); // update class function
void displayDetails(); // view class details function
void deleteClass(); // class removal function
bool addStudents(); // add student function
bool removeStudents(); // remove students function
};
#endif