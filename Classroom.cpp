#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Classroom.h"
#include "typeEffect.h"
using namespace std;
//////implementing classroom class functions///////
VirtualClassroom::VirtualClassroom()
{
    className= "";
    subjectName= "";
    classCode= "";
    classDescription= "";
}
VirtualClassroom::VirtualClassroom(string className, string subjectName, string classCode, string classDescription)
{
    this->className= className;
    this->subjectName= subjectName;
    this->classCode= classCode;
    this->classDescription= classDescription;
}
void VirtualClassroom::createClass()
{
    ofstream classroom;
 
    // get teacher input for creation of classroom
    cout<<"Enter classroom name: ";
    cin>>className;
    cin.ignore();
    cout<<"Enter your subject: "; 
    getline(cin, subjectName);
    cout<<"Enter classroom code: ";
    cin>>classCode;
    cin.ignore();
    cout<<"Enter teacher name: ";
    getline(cin, userName);
    cout<<"Enter description: ";
    getline(cin, classDescription);
    classroom.open("class_info.txt", ios::app);
    classroom<<'&'<<className<<';'<<subjectName<<';'<<classCode<<';'<<userName<<';'<<classDescription<<endl;
    classroom.close();
   
    typeEffect("Class created successfully.\n",100);
    cout<<endl;
}
void VirtualClassroom::updateClass()
{
    cout<<"Enter classroom name to update: ";
    cin>>className;
}
void VirtualClassroom::displayDetails()
{
    cout<<"Enter class name to view its details: ";
    cin>>className;
    ifstream file_in("class_info.txt");
    if(!file_in.is_open()) // file error handling
    {
        return; 
    }
    string fileLine;
    while(getline(file_in, fileLine))
    {
        if(fileLine.find(className) != string::npos)
        {
            size_t lineStart= fileLine.find(';');
            size_t lineEnd= fileLine.find(';', lineStart + 1);
            if(lineStart != string::npos && lineEnd != string::npos)
            {
                string subject_name= fileLine.substr(lineStart + 1, lineEnd - lineStart - 1);
                cout<<"Subject Name: "<<subject_name<<endl;
                lineStart= lineEnd;
                lineEnd= fileLine.find(';', lineStart + 1);
                if(lineStart != string::npos && lineEnd != string::npos) 
                {
                    string class_code= fileLine.substr(lineStart + 1, lineEnd - lineStart - 1);
                    cout<<"Classroom Code: "<<class_code << endl;
                    lineStart = lineEnd;
                    lineEnd = fileLine.find(';', lineStart + 1);
                    if(lineStart != string::npos && lineEnd != string::npos) 
                    {
                        string teacherName = fileLine.substr(lineStart + 1, lineEnd - lineStart - 1);
                        cout<<"Teacher Name: "<<teacherName<<endl;
                        lineStart = lineEnd;
                        string class_description= fileLine.substr(lineStart + 1);
                        cout<<"Description: "<<class_description<<endl;
                    }
                
                }
            }
            break; 
        }
    }
    file_in.close();
}
void VirtualClassroom::deleteClass()
{
    cout<<"Enter class name to delete: ";
    cin>>className;
    ifstream file_in("class_info.txt");
    if(!file_in.is_open()) // file error handling
    {
        return; 
    }
    string fileLine;
    vector<string> remainingData;
    while(getline(file_in, fileLine))
    {
        if(fileLine.find(className) == string::npos)
        {
            remainingData.push_back(fileLine);
        }
    }
    ofstream file_out("class_info.txt");
    if (!file_out.is_open()) 
    {
        return;
    }
    for(const string& line : remainingData) 
    {
        file_out<<line<<endl;
    }
    file_out.close();
    string message= "Class "+ className+ " has been deleted successfully.";
    typeEffect(message,100);
    cout<<endl;    
}

bool VirtualClassroom::addStudents()
{
    string studentData;
    cout<<"Enter student information(e.g. 20I-1234,Malik Emad): ";
    cin.ignore();
    getline(cin, studentData);
    // add to vector
    studentRoster.push_back(studentData);
    // save to a file
    ofstream file_out("student_registration.txt", ios::app);
    if(file_out.is_open())
    {
        file_out<<studentData<<endl;
        file_out.close();
        typeEffect("Student added successfully!\n",100);
        return true;
    }
    else
    {
        cout<<"Unable to open roster file for writing.\n";
        return false;
    }
}

bool VirtualClassroom::removeStudents()
{
    string studentData;
    cout<<"Enter student information to remove (e.g. 20I-1234,Malik Emad): ";
    cin.ignore();
    getline(cin, studentData);
    // search for the student information in the vector
    auto it= find(studentRoster.begin(), studentRoster.end(), studentData);
    if(it != studentRoster.end())
    {
        // Remove the student information from the roster vector
        studentRoster.erase(it);
        // Save to a file
        ofstream file_out("student_registration.txt");
        if(file_out.is_open())
        {
            for(const string& student : studentRoster)
            {
                file_out<<student<<endl;
            }
            file_out.close();
            typeEffect("Student removed successfully!\n",100);
            return true;
        }
        else
        {
            cout<<"Unable to open roster file for writing.\n";
            return false;
        }
    }
    else
    {
        cout<<"Student information not found in roster.\n";
        return false;
    }
}