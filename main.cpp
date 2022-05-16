// FCAI – Programming 1 – 2022 - Assignment 4
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
void to_register()
{
    bool ret = false;
    cout<<"please enter your id :";
    cin>>user.ID;
    regex int_format ("[0-9]+") ;
    if (regex_match(user.ID, int_format) )
        ret = true ;
    while (!ret)
    {
        cout <<"invalid id please enter again: ";
        cin>>user.ID;
        if (regex_match(user.ID, int_format) )
            ret = true ;
    }
    cout<<"please enter your mobile :";
    cin>>user.mobile;
    regex mobileformat ("(011|012|010|015)+[0-9]{8}") ;
    ret = regex_match(user.mobile, mobileformat) ;
    while(!ret)
    {

        cout <<"invalid mobile please enter again: ";
        cin>>user.mobile;
        ret = regex_match(user.mobile, mobileformat) ;
    }
    cout<<"please enter your user name :";
    cin>>user.username;
    regex usernameformat ("([a-zA-Z])+[\\_]?([a-zA-Z])+") ;
    ret = regex_match(user.username, usernameformat) ;
    while(!ret)
    {

        cout <<"invalid username please enter again: ";
        cin>>user.username;
        ret = regex_match(user.username, usernameformat) ;
    }
    cout<<"please enter your email :";
    cin>>user.email;
    regex emailformat ("^[a-zA-Z0-9+_.-]+@[a-zA-Z.-]+$") ;

    ret = regex_match(user.email, emailformat) ;
    while(!ret)
    {

        cout <<"invalid email please enter again: ";
        cin>>user.email;
        ret = regex_match(user.email, emailformat) ;

    }
    cout<<"";
    user.password=password();

    Encrypt(user.password);

    fillfile();
    fillmapinfusers();

    cout<<"the registration completed successfully"<<endl;
}

bool Check_ID(string ID)
{

    if (mapinfusers.count(ID) == 1)
    {

        return true ;

    }

    else
    {

        return false ;

    }
}


//-------------------------------------------------------------------------------------------------------------------------------
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
void to_login()
{
    string ID;
    int n=2;
    string password;
id:

    cout<<"please enter your id :";
    cin>>ID;

    if(!Check_ID(ID))
    {
        cout << "The ID is not Exist..." ;

        goto id;
    }

    string name = mapinfusers[ID].username;

    string getpassword;
    getpassword= Decrypt(mapinfusers[ID].password);

label:

    cout << "please enter your password :";

    char character;
    int Check = 0;
    string try1;

    while ((character = getch()) != '\r')
    {


        if (character < 0 || Check % 2 != 0)
        {

            Check++;

        }
        else if (character == 8)
        {

            if (!try1.empty())
            {

                try1.pop_back();

                cout << character << " " << character;

            }
        }
        else
        {

            try1 += character;

            cout << "*";

        }
    }

    if (getpassword==try1)
    {
        cout <<"\nSuccessful login, welcome "<< name << endl ;

    }
    else
    {
        cout<<"\nFailed login.. Try again.\n";
        try1="";
        while(n-- )
        {
            cout<<"you have "<<n+1<<" chance to login before ban!!\n";
            goto label ;
        }
        cout<<"\nyou are denied of access to the system \n";
    }

    Encrypt(mapinfusers[ID].password);

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
