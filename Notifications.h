#include<iostream>
#ifndef NOTIFICATIONS_H
#define NOTIFICATIONS_H
using namespace std;
class Notifications
{
protected:
    string notificationText;
public:
    void addAnnouncement();
    void viewAnnouncement();
};
#endif