// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: userlogin.cpp
// Last Modification Date: 16/5/2022
// Author1 and ID and Group: abdelrahman adel   20211059  group A
// Author2 and ID and Group: salma ramadan mohamed omar   20211047   group A
// Author3 and ID and Group: alaa azizi abdelhamid   20210071  group A
// Teaching Assistant: nesma/yousra
// Purpose: login page


#include "userlogin.cpp"
using namespace std;
//------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
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
            to_register();
        }
        else if(option==2)
        {
            to_login();
        }
        else if(option==3)
        {
            to_change_password();
        }
        else if(option==4)
        {
            state=false;
        }
        else cout<<"the option you entered is't correct ";
    }
}
