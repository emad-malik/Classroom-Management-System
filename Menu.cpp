#include<iostream>
#include "Student.h"
#include "Teacher.h"
#include "SystemUser.h"
#include "Classroom.h"
#include "Assignment.h"
#include "Notifications.h"
#include "typeEffect.h"

using namespace std;
class Menu
{
public:
void displayMenu()
{
    int userChoice= 0, teacherChoice= 0, studentChoice= 0;
    while(1)
    {
        Student student;
        Teacher teacher;
        VirtualClassroom classroom;
        Assignment assignment;
        Notifications announcement;
        cout<<"\u001B[34mWelcome to Classroom Management System\n";
        while(1)
        {
            cout<<"\nLogin Menu";
            cout<<"\n1. Teacher Login"<<"\n2. Student Login"<<"\n3. Exit\n:";
            cin>>userChoice;
            if(userChoice == 3)
            {
                typeEffect("We wish to see you soon :)", 100);
                break;
            }
            if((userChoice>=1) && (userChoice<=3))
            {
                break;
            }
            else
            {
                cout<<"Please select from the given options."<<endl;
            }
        }
        cout<<"\u001b[2J"; //clears screen
        if(userChoice == 1)
        {
            teacher.SystemLogin(); 
            if (teacher.isAuthorised)
            {
                cout<<"\u001B[34m1. Create Classroom\n2. View Classroom Details\n3. Delete Classroom\n4. Back to Main Menu\n";
                cin>>teacherChoice;
                if(teacherChoice == 1)
                {
                    classroom.createClass();
                    cout<<"\u001B[34m1. Upload Assignment\n2. Add Student\n3. Remove Student\n4. Announcement\n5. Back to Main Menu\n";
                    cin>>teacherChoice;
                    if(teacherChoice == 1)
                    {
                        assignment.UploadAssignment();
                    }
                    else if(teacherChoice == 2)
                    {
                        classroom.addStudents();
                    }
                    else if(teacherChoice == 3)
                    {
                        classroom.removeStudents();
                    }
                    else if(teacherChoice == 4)
                    {
                        announcement.addAnnouncement();
                    }
                    else if(userChoice == 5)
                    {
                        displayMenu();
                    }
                }
                else if(teacherChoice == 2)
                {
                    classroom.displayDetails();
                }
                else if(teacherChoice == 3)
                {
                    classroom.deleteClass();
                }
                else if(teacherChoice == 4)
                {
                    displayMenu();
                }
            }
        }
        else if(userChoice == 2)
        {
            student.SystemLogin();
            if(student.student_authorized) 
            {
                cout<<"\u001B[34m1. Join Class\n2. Unenrol\n3. Back to Main Menu\n";
                cin>>studentChoice;
                if(studentChoice == 1)
                {
                    student.JoinClass();
                    cout<<"\u001B[34m1. Attempt Assignment\n2. View Grades\n3. View Notifications\n4. Back to Main Menu\n";
                    cin>>studentChoice;
                    if(studentChoice == 1)
                    {
                        assignment.AccessAssignment(); 
                        assignment.CalculateScore();
                    }
                    else if(studentChoice == 2)
                    {
                        assignment.DisplayResult();
                    }
                    else if(studentChoice == 3)
                    {
                        announcement.viewAnnouncement();
                    }
                    else if(studentChoice == 4)
                    {
                        displayMenu();
                    }
                }
                else if(studentChoice == 2)
                {
                        student.LeaveClass();
                }
                else if(studentChoice == 3)
                {
                        displayMenu();
                }
            }
        }
        else if(userChoice == 3)
        {
            typeEffect("We wish to see you soon :)", 100);
              
            break;
        }
        else
        {
            cout<<"Please select from the given options."<<endl;
            break;
        }
    }
}
};