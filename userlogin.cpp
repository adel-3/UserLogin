#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>
#include "userloginheader.h"
using namespace std;

fstream fileinformation,storingfile;
string filename="user information.txt";
struct infuser
{
    string ID,username,email,mobile,password;

};

map<string,infuser> mapinfusers;

infuser user;

//-------------------------------------------------------------------------------------------------------------------------------------
string Encrypt(string& Decrypt_Pass)
{

    int ind ;

    vector <char> alpha_cipher ;

    string alpha ;

    alpha_cipher.push_back('c') ;

    alpha_cipher.push_back('a') ;

    alpha_cipher.push_back('i') ;

    alpha_cipher.push_back('r') ;

    alpha_cipher.push_back('o') ;

    for (int i = 97; i <= 122; i++)

        alpha.push_back(char(i)) ;

    for (int i = 65; i <= 90 ; i++)

        alpha.push_back(char(i)) ;

    for (int i = 97; i <= 122; i++)
    {

        if (!count(alpha_cipher.begin(), alpha_cipher.end(), char(i)))

            alpha_cipher.push_back(char(i));

    }

    alpha_cipher.push_back('C') ;

    alpha_cipher.push_back('A') ;

    alpha_cipher.push_back('I') ;

    alpha_cipher.push_back('R') ;

    alpha_cipher.push_back('O') ;

    for (int i = 65; i <= 90; i++)
    {

        if (!count(alpha_cipher.begin(), alpha_cipher.end(), char(i)))

            alpha_cipher.push_back(char(i));

    }

    for (char & Pas : Decrypt_Pass)
    {
        if (Pas == ' ' )

            Pas = char (int(Pas) + 1) ;

        else if (ispunct(Pas) || isdigit(Pas))
        {

            Pas = char (int(Pas) - 1);

        }

        else
        {

            ind = (int) alpha.find(Pas) ;

            Pas = (char) alpha_cipher.at(ind) ;

        }
    }

    return Decrypt_Pass ;
}


//----------------------

string Decrypt(string& Decrypt_Pass)
{

    int ind ;

    vector <char> alpha_cipher ;

    string alpha;

    alpha_cipher.push_back('c') ;

    alpha_cipher.push_back('a') ;

    alpha_cipher.push_back('i') ;

    alpha_cipher.push_back('r') ;

    alpha_cipher.push_back('o') ;

    for (int i = 97; i <= 122; i++)

        alpha.push_back(char(i)) ;

    for (int i = 65; i <= 90 ; i++)

        alpha.push_back(char(i)) ;

    for (int i = 97; i <= 122; i++)
    {

        if (!count(alpha_cipher.begin(), alpha_cipher.end(), char(i)))

            alpha_cipher.push_back(char(i));

    }

    alpha_cipher.push_back('C') ;

    alpha_cipher.push_back('A') ;

    alpha_cipher.push_back('I') ;

    alpha_cipher.push_back('R') ;

    alpha_cipher.push_back('O') ;

    for (int i = 65; i <= 90; i++)
    {

        if (!count(alpha_cipher.begin(), alpha_cipher.end(), char(i)))

            alpha_cipher.push_back(char(i));

    }

    for (char& Pas : Decrypt_Pass)
    {

        if (Pas == '!' )

            Pas = char (int(Pas) - 1) ;

        else if (ispunct(Pas) || isdigit(Pas))
        {

            Pas = char (int(Pas) + 1);

        }

        else
        {

            auto it = find(alpha_cipher.begin(), alpha_cipher.end(), Pas);

            if (it != alpha_cipher.end())

                ind = int(it - alpha_cipher.begin()) ;

            Pas = alpha.at(ind);

        }
    }

    return Decrypt_Pass ;
}


//----------------------


//----------------------
string password()
{
    string try1, try2 ;
    bool check = false ;

    cout << "the password should be strong \nso u should enter at least one character capital\n";
    cout << "and the password should contain nums and special character \nand should contain at least one space\n";
    regex chk("((?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[!?_.,/><*&^%$#@ ]*)[a-zA-Z0-9!?_.,/><*&^%$#@ ]*){8,15}");

repeat:
    do
    {
        try1 = "";
        try2 = "";

        cout << "enter your password here :";
        int Check = 0;
        char character;

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

        if (regex_match(try1, chk))
        {
            cout << "\nenter your password again here :";
            int Check = 0;
            char character;

            while ((character = getch()) != '\r')
            {

                if (character < 0 || Check % 2 != 0)
                {

                    Check++;

                }
                else if (character == 8)
                {

                    if (!try2.empty())
                    {

                        try2.pop_back();

                        cout << character << " " << character;

                    }
                }
                else
                {

                    try2 += character;

                    cout << "*";

                }
            }
        }
        else
        {
            cout << "\nyour password is not strong\n";
            goto repeat;

        }

        if (try1 == try2)
        {
            check = true;
        }
        else
        {
            cout << "\nyour password is not strong or matching \n";
            goto repeat;
        }

    }
    while (!regex_match(try1, chk));
    if (check)
    {
        cout << "\nyour password is strong and matching\nsuccess :) ";


    }
    return try1;
}
//-------------------------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------

void fillmapinfusers()
{
    fileinformation.close() ;

    fileinformation.open(filename);

    string Id, User_Name, Email, Mobile, Password ;

    while (fileinformation.peek() != EOF)
    {

        getline(fileinformation, Id) ;

        getline(fileinformation, User_Name) ;

        getline(fileinformation, Email) ;

        getline(fileinformation, Mobile) ;

        getline(fileinformation, Password) ;

        mapinfusers[Id] = {Id, User_Name, Email, Mobile, Password} ;

    }

    fileinformation.close();
}
//------------------------------------------------------------------------------------------------------------------------------------
void fillfile()
{
    fileinformation.close();
    fileinformation.open(filename,ios::app);

    fileinformation << user.ID << endl;
    fileinformation<<user.username<<endl;
    fileinformation<<user.email<<endl;
    fileinformation<<user.mobile<<endl;
    fileinformation<<user.password << endl ;

    fileinformation.close();
}
void replace_password(string& pass,string pass2)
{
    string line,data;
    fileinformation.close();
    fileinformation.open("user information.txt");
    while(fileinformation.peek()!=EOF)
    {
        getline(fileinformation,line);
        if (pass==line)
        {
            data += pass2;
            cout<<"\nthe password has been changed :)\n";
        }
        else
        {
            data += line;
        }
        data+="\n";
    }

    fileinformation.close();
    fileinformation.open("user information.txt", ios::out);
    fileinformation<<data;
    fileinformation.close();
}
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
void to_change_password()
{
    string ID;
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


label:
    string getpassword ;

    getpassword = mapinfusers[ID].password;
    getpassword = Decrypt(getpassword) ;

    cout << "please enter your password :";

    char character;
    int Check = 0;
    string old_password, new_password,new_repeated_passeord;

    while ((character = getch()) != '\r')
    {


        if (character < 0 || Check % 2 != 0)
        {

            Check++;

        }
        else if (character == 8)
        {

            if (!old_password.empty())
            {

                old_password.pop_back();

                cout << character << " " << character;

            }
        }
        else
        {

            old_password += character;

            cout << "*";

        }
    }

    if (old_password!=getpassword)
    {
        old_password = "" ;
        getpassword = "" ;
        cout <<"\nthe password is not correct....\n";
        goto label;
    }
label2:
    cout <<"\nenter the new password :";

    while ((character = getch()) != '\r')
    {


        if (character < 0 || Check % 2 != 0)
        {

            Check++;

        }
        else if (character == 8)
        {

            if (!new_password.empty())
            {

                new_password.pop_back();

                cout << character << " " << character;

            }
        }
        else
        {

            new_password += character;

            cout << "*";

        }
    }
    regex chk("((?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[!?_.,/><*&^%$#@ ]*)[a-zA-Z0-9!?_.,/><*&^%$#@ ]*){8,15}");
    if (!(regex_match(new_password, chk)))
    {
        new_password = "" ;

        cout << "\nyour password is not strong \n :)\n ";
        goto label2;
    }



    cout <<"\nenter the new password again :";

    while ((character = getch()) != '\r')
    {


        if (character < 0 || Check % 2 != 0)
        {

            Check++;

        }
        else if (character == 8)
        {

            if (!new_repeated_passeord.empty())
            {

                new_repeated_passeord.pop_back();

                cout << character << " " << character;

            }
        }
        else
        {

            new_repeated_passeord += character;

            cout << "*";

        }
    }
    if (!(new_repeated_passeord==new_password))
    {
        cout << "\nyour password is not matching\n :)\n ";
        new_password="";
        new_repeated_passeord="";

        goto label2;
    }

    new_password = Encrypt(new_password);
    old_password= Encrypt(old_password);
    replace_password(old_password,new_password);
    //-----------------------
    user.password = new_password;
    fillmapinfusers();
}
