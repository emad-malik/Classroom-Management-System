#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "SystemUser.h"
#include "Teacher.h"
#include "Student.h"
///////implementing SystemUser class functions///////
SystemUser::SystemUser()
{
    userName= " ";
    userCourse= " ";
    userRollNum= " ";
    isRegistered= false;
    user_email= " ";
    user_password= " ";
}
SystemUser::SystemUser(string userName, string userCourse)
{
    this->userName= userName;
    this->userCourse= userCourse;
}
string SystemUser::GenerateRandomPassword()
{
// this functions helps generate a random password of desired length. the passsword must have one Uppercase, one lowercase, one special character and one number
    int  count_upper= 0, count_lower= 0, count_special= 0, count_digits= 0, counter= 0, pass_length=8;
    string userPassword= "";
    string upperCase= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowerCase= "abcdefghijklmnopqrstuvwxyz";
    string special_char= "!@#$%&";
    string digits= "0123456789";
// generating random numbers   
    for(static int index =0; index<216; index++)
    {
        srand(index); // seed the random number generator
    }
    // generate random uppercase letter
    userPassword+= upperCase[rand() % upperCase.length()];
    count_upper++;
    // generate random lowercase letter
    userPassword+= lowerCase[rand() % lowerCase.length()];
    count_lower++;
    // generate random digit
    userPassword+= digits[rand() % digits.length()];
    count_digits++;
    // generate random special character
    userPassword+= special_char[rand() % special_char.length()];
    count_special++;
    // generate remaining characters
    for(int iter= 4; iter<pass_length; iter++) 
    {
        int choice= rand() % 4;
        if((choice == 0) && (count_upper < 2)) 
        {
            userPassword+= upperCase[rand() % upperCase.length()];
            count_upper++;
        } 
        else if((choice == 1) && (count_lower < 2)) 
        {
            userPassword+= lowerCase[rand() % lowerCase.length()];
            count_lower++;
        } 
        else if((choice == 2) && (count_digits < 2)) 
        {
            userPassword+= digits[rand() % digits.length()];
            count_digits++;
        } 
        else if((choice == 3) && (count_special < 2)) 
        {
            userPassword+= special_char[rand() % special_char.length()];
            count_special++;
        } 
        else 
        {
            userPassword+= upperCase[rand() % upperCase.length()];
            count_upper++;
        }
    }
    return userPassword;
}
extern void SystemUser::createLoginDatabase()
{
    //this function extracts username from "students.txt" and writes it into "login_database.dat" with a random password alongside it
    fstream file_in("student_registration.txt", ios:: in);//file from where we have to read usernames
    fstream file_out("login_database.dat", ios::out); //file where we want to write our credentials
    if(!file_out.is_open()) 
    {
        cout<<"Error opening file\n";
    }
    char ch;
    int i;
    string fileLine, extra;
    while(!file_in.eof())
    {
        srand(i++);
        int random_index= rand()% 11;
        file_in.get(ch);
        if (ch== ',')
        {
            (getline(file_in, fileLine, ','));  
            file_out<<fileLine<<"@nu.edu.pk"<<';'<<GenerateRandomPassword()<<endl;
            getline(file_in, extra); // skip the rest of the line
        }    
    }
    file_in.seekg(0, ios:: beg); //sets readability to start of program;    
}