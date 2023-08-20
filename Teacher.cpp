#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <termios.h>
#include <unistd.h> 
#include <limits>
#include "Teacher.h" 
#include "getpass.h"

using namespace std;
////////implementing Teacher class functions///////
Teacher::Teacher()
{  
    employment_status= ' ';
    years_ofExperience= 0;    
}
Teacher::Teacher(char employment_status, int years_ofExperience)
{
    this->employment_status= employment_status;
    this->years_ofExperience= years_ofExperience;
    TeacherAuthentication();
}
Teacher::Teacher(const Teacher& teacher_obj)
{
    employment_status= teacher_obj.employment_status;
    years_ofExperience= teacher_obj.years_ofExperience;
}
char Teacher::getEmploymentStatus() const
{
    return employment_status;
}
void Teacher::setEmploymentStatus(char employment_status)
{
    this->employment_status= employment_status;
}
int Teacher::getExperience() const
{
    return years_ofExperience;
}
void Teacher::setExperience(int years_ofExperience)
{
    this->years_ofExperience= years_ofExperience;
}

bool Teacher::TeacherAuthentication()
{
    cout<<"\nEnter your userName:";
    cin>>userName;
    // Clear the input buffer
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');   
    cout<<"\nEnter your user_password:"; 
    user_password=getPassword();
  
    string Tempuser, Temppassword;
    credentials_file.open("teacher_database.dat", ios::in);
    credentials_file.clear(); // clears any error flags
    credentials_file.seekg(0, ios:: beg); //sets readability to start of program
    string fileLine, TempUser, TempPass;
    while (getline(credentials_file, fileLine))
    {
        stringstream fileStream(fileLine);
        getline(fileStream, TempUser, ';');  // Extract id before '@'
        getline(fileStream, TempPass, ';');  // Extract password
        if((this->userName == TempUser) && (this->user_password == TempPass))
        {
            cout<<"\n\u001b[32mAUTHORIZED \u001b[0m"<<endl;
            isAuthorised= true;
            return isAuthorised;
        }
    }
    cout<<"\n\u001b[31mUnauthorized:Access Denied.\u001b[0m"<<endl;
    credentials_file.clear();
    credentials_file.close();
    isAuthorised= false;
    return isAuthorised;
}
void Teacher::SystemLogin() 
{   
    isAuthorised= TeacherAuthentication();
}