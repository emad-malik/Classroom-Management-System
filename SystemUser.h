#include <iostream>
#include <fstream>
using namespace std;
#ifndef SYSTEMUSER_H
#define SYSTEMUSER_H
// user class design
class SystemUser
{
protected: 
string userRollNum;
bool isRegistered;
string user_email;
fstream credentials_file;
public:
string userName;
string userCourse;
string user_password;
SystemUser(); // default constructor
SystemUser(string, string); // parameter constructor
void createLoginDatabase(); // function which creates id/pass file
string GenerateRandomPassword(); // random password generator
void SystemLogin(); // login for user
};
#endif