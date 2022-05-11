// FCAI � Programming 1 � 2022 - Assignment 4
// Program Name: xxxxxx.cpp
// Last Modification Date: xx/xx/xxxx
// Author1 and ID and Group: xxxxx xxxxx
// Author2 and ID and Group: xxxxx xxxxx
// Author3 and ID and Group: xxxxx xxxxx
// Teaching Assistant: xxxxx xxxxx
// Purpose:..........
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
//------------------------------------------------------------------------------------------------------------------------------------
fstream fileinformation,storingfile;
string filename="user informations.txt";
struct infuser
{
    string ID,email,password,username,mobile;
};
map<string,infuser>mapinfusers;
//-------------------------------------------------------------------------------------------------------------------------------------
void fillmapinfusers()
{
    fileinformation.open(filename,ios::in | ios::trunc);
    string line1,line2,line3,line4,line5;
    while(fileinformation.peek()!=EOF)
    {
        getline(fileinformation,line1);
        getline(fileinformation,line2);
        getline(fileinformation,line3);
        getline(fileinformation,line4);
        getline(fileinformation,line5);
        mapinfusers[line1] = {line1,line2,line3,line4,line5};
    }
    fileinformation.close();
}
//------------------------------------------------------------------------------------------------------------------------------------
void fillfile(infuser user)
{
    fileinformation.open(filename,ios::app);
    fileinformation<<user.ID<<endl;
    fileinformation<<user.email<<endl;
    fileinformation<<user.password<<endl;
    fileinformation<<user.username<<endl;
    fileinformation<<user.mobile<<endl;
    fileinformation.close();
}
//-------------------------------------------------------------------------------------------------------------------------------------
void to_register(infuser &user)
{

    cout<<"please enter your name :";
    cin>>user.username;
    cout<<"please enter your email :";
    cin>>user.email;
    cout<<"please enter your password :";
    cin>>user.password;
    cout<<"please enter your id :";
    cin>>user.ID;
    cout<<"please enter your mobile :";
    cin>>user.mobile;
    fillfile(user);
    fillmapinfusers();
    cout<<"the registration completed successfully"<<endl;
}
//--------------------------------------------------------------------------------------------------------------------------------------
void to_login(infuser &user)
{

}
//---------------------------------------------------------------------------------------------------------------------------------------
void to_change_password(infuser &user)
{

}
//----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    infuser user;
    fillmapinfusers();
    int option;
    bool state=true;
    while(state)
    {
        cout <<"what do you want to do from this menu\n"
             "(1) Register\n"
             "(2) Login\n"
             "(3) Change Password\n"
             "(4) Exit\n"
             ">>>> ";
        cin>>option;
        if(option==1)
        {
            to_register(user);
        }
        else if(option==2)
        {
            to_login(user);
        }
        else if(option==3)
        {
            to_change_password(user);
        }
        else if(option==4)
        {
            state=false;
        }
        else cout<<"the option you entered is't correct ";
    }
}