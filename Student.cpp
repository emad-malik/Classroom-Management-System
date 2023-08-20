#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Student.h"
#include "Classroom.h"
#include "Authentication.h" 
#include "SystemUser.h"
/////////implementing Student class functions//////////
Student::Student()
{
    studentAge= 0;
    program_enrolled= " ";
    current_semester= 0;
    current_status= ' ';
    student_CNIC= 0000;
    date_ofBirth= " ";
}
Student::Student(int studentAge, string program_enrolled, int current_semester, char current_status, long int student_CNIC, string date_ofBirth)
{
    this->studentAge= studentAge;
    this->program_enrolled= program_enrolled;
    this->current_semester= current_semester;
    this->current_status= current_status;
    this->student_CNIC= student_CNIC;
    this->date_ofBirth= date_ofBirth;
}
Student::Student(const Student& student_obj)
{
    studentAge= student_obj.studentAge;
    program_enrolled= student_obj.program_enrolled;
    current_semester= student_obj.current_semester;
    current_status= student_obj.current_status;
    student_CNIC= student_obj.student_CNIC;
    date_ofBirth= student_obj.date_ofBirth;
}
int Student::getAge() const
{
    return studentAge;
}
void Student::setAge(int studentAge)
{
    this->studentAge= studentAge;
}
string Student::getProgram() const
{
    return program_enrolled;
}
void Student::setProgram(string program_enrolled)
{
    this->program_enrolled= program_enrolled;
}
int Student::getSemester() const
{
    return current_semester;
}
void Student::setSemester(int current_semester)
{
    this->current_semester= current_semester;
}
char Student::getStatus() const
{
    return current_status;
}
void Student::setStatus(char current_status)
{
    this->current_status= current_status;
}
long int Student::getCNIC() const
{
    return student_CNIC;
}
void Student::setCNIC(long int student_CNIC)
{
    this->student_CNIC= student_CNIC;
}
string Student::getDOB() const
{
    return date_ofBirth;
}
void Student::setDOB(string date_ofBirth)
{
    this->date_ofBirth= date_ofBirth;
}

void Student::SystemLogin()  
{
    // create binary files for login credentials
    Student student;
    // Authenticate user
    while (1)
    {
        Authentication S; 
        student_authorized= S.isAuthorized;
        this->userName= S.userName; 
        this->user_password= S.user_password;
        this->userCourse= S.userCourse;
        if(student_authorized) 
        {
            cout<<endl;
            break;
        }
        else
        {    
            cout<<"\n\u001b[31mUnauthorized:Access Denied.\u001b[0m"<<endl;
        }
    }
}
bool Student::validateCode()
{
    string userCode;
    cout<<"Enter class code to join a classroom. "<<"1.It should be 6 characters long\n2.It should not contain special characters\n3.It can contain digits(0-9)\n";
    cin>>userCode;
    ifstream codeFile("class_info.txt");
    if(codeFile.is_open())
    {
        string line,teacherName;
        while (getline(codeFile, line))
        {   
            istringstream iss(line);
            if(getline(iss, className, ';') &&
                getline(iss, subjectName, ';') &&
                getline(iss, classCode, ';') &&
                getline(iss, teacherName, ';') &&
                getline(iss, classDescription, ';'))
            {
                if (classCode == userCode)
                {
                    codeFile.close();
                    return true;
                }
            }
        }
        codeFile.close();
    }
    return false;
}
void Student::JoinClass() 
{
    if(validateCode())
    {
        cout<<"Welcome to "<<className<<"Classroom"<<endl;
       ofstream classListFile("classlist.txt", ios::app);
        if(classListFile.is_open())
        {
            classListFile<<subjectName<<";"<<userName<<";\n";
            classListFile.close();
            cout<<"Joined class successfully!\n";
        }
        else
        {
        cout << "Unable to open classlist.txt\n";
        }
    }
}

void Student::LeaveClass()
{
    cout<<"Enter class name to Unenrol: ";
    cin>>className;
    ifstream classListFile("classlist.txt");
    if (!classListFile.is_open())
    {
        cout<<"Failed to open file"<<endl;
        return;
    }
    vector<string> content;
    string fileLine;
    while (getline(classListFile, fileLine))
    {
        content.push_back(fileLine);
    }
    classListFile.close();
    ofstream file_out("classlist.txt");
    if (!file_out.is_open())
    {
        cout<<"Failed to open file"<<endl;
        return;
    }
    bool studentRemove= false;
    for (const string& currentLine : content)
    {
        if (currentLine.find(subjectName + ";" + userName + ";") != string::npos)
        {
            studentRemove= true;
            continue; // skip writing the line to the output file
        }
        file_out << currentLine << endl;
    }
    file_out.close();
    if(studentRemove)
    {
        cout<<"Left class successfully."<<endl;
    }
    else
    {
        cout<<"Student's information not found."<<endl;
    }
}
