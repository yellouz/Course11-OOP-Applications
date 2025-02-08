#pragma once
/*
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
*/

#include "../../HeaderFiles/Global.h"

class clsLoginScreen :protected clsScreen
{

private :
    
    static  void _Login()
    {
        bool LoginFaild = false;
        string Username, Password;
        short NumberOfTrialsLeft = 2;

        do
        {
            if (NumberOfTrialsLeft == 0)
            {
                cout << "\nYou have Are Locked After 3 Failed Trials to Login\n\n";
                exit (1);
            }
            
            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have " << NumberOfTrialsLeft << " Trials to Login\n\n";
                NumberOfTrialsLeft--;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();

        clsMainScreen::ShowMainMenue();

    }

public:


    static void ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        _Login();

    }

};

