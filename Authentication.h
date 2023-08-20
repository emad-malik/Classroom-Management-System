#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "SystemUser.h"
//class design for authentication(relation with user class)
class Authentication :public SystemUser
{
public:
string userCourse;
bool isAuthorized= false;
Authentication(); // default constructor
bool AuthenticateUser(); // function to authenticate
void NewUser(); // new user creation
};
#endif