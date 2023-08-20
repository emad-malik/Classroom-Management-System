#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include "Authentication.h"
#include "SystemUser.h"
#include "getpass.h"
#include "typeEffect.h"

//////implementing Authentication class functions///////

Authentication::Authentication()
{
    char userChoice;
    cout<<"Do you want to create a new user? (Y/N):  ";
    cin>>userChoice;
    if(userChoice == 'y' || userChoice == 'Y')
    {
        NewUser();
    }
    cout<<"\nEnter your userName: ";
    cin>>userName;
    cout<<"\nEnter your user Password: ";
    user_password= getPassword();
    AuthenticateUser();
}
void Authentication::NewUser()
{
    string new_UserName= "", new_userPassword= "";
    while(1)
    {
        cout<<"\nEnter New Username: ";
        cin>>new_UserName;
        cout<<"\nEnter Password: ";
        new_userPassword= getPassword();
        if(AuthenticateUser())
        {
            cout<<"User already exists, Try again ";
        }
        else
        {
            break;
        }
    }
    while (AuthenticateUser())
    {
        cout<<"User already exists, Try again!";
    }
    // open credentials_file in append mode
    ofstream credentials_file_out("login_database.dat", ios::app);
   
    // write new username and password to end of credentials_file
    credentials_file_out<<new_UserName<<';'<<new_userPassword;
    typeEffect("\nNew user created! Enter your credentials again.",100);
}
bool Authentication::AuthenticateUser() 
{
    string userName, user_password;
    credentials_file.open("login_database.dat", ios::in);
    credentials_file.clear(); // clears any error flags
    credentials_file.seekg(0, ios:: beg); //sets readability to start of program
    while(!credentials_file.eof()) 
    { 
        //eof is used to check if end of credentials_file has been reached yet
        getline(credentials_file, userName, ';'); // use ; as delimiter
        getline(credentials_file, user_password,'\n'); // use line end as delimiter
        // remember; delimiter readed from input but not added to output
        if(!credentials_file.is_open())
        {
            cout<<"File not opened."<<endl;
            return false;
        }
        if((this->userName == userName) && (this->user_password == user_password))
        {
            credentials_file.close();
            cout<<"\n\u001b[32mAUTHORIZED \u001b[0m."<<endl;
            isAuthorized=true;
            return true;
        }
    }
    credentials_file.clear();
    credentials_file.close();
    return false;
}