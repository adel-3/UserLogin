#ifndef USERLOGINHEADER_H_INCLUDED
#define USERLOGINHEADER_H_INCLUDED

#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>

using namespace std;

void to_change_password();
void to_login();
void to_register();
void fillfile();
void fillmapinfusers();
string password();
string Decrypt(string& Decrypt_Pass);
string Encrypt(string& Decrypt_Pass);

#endif // USERLOGINHEADER_H_INCLUDED
