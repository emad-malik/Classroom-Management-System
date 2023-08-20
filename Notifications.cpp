#include<iostream>
#include<fstream>
#include "Notifications.h"
using namespace std;
void Notifications::addAnnouncement()
{
    ofstream announcement("notifs.txt");
    if(!announcement.is_open())
    {
        cout<<"Failed to open file."<<endl;
    }
    // store in a file
    cout<<"Enter new announcement:"<<endl;
    getline(cin, notificationText);
    announcement<<notificationText;
    announcement.close();
    cout<<"Notification added successfully."<<endl;
}
void Notifications::viewAnnouncement()
{
    ifstream announcement("notifs.txt");
    if(!announcement.is_open())
    {
        cout<<"Failed to open file."<<endl;
    }
    // read from file
    string fileLine;
    while(getline(announcement, fileLine))
    {
        cout<<fileLine<<endl;
    }
    announcement.close(); 
}