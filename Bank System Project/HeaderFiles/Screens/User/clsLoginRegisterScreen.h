#pragma once
/*
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
*/

#include "../../../HeaderFiles/Global.h"

class clsLoginRegisterScreen : protected clsScreen
{
private:
    static void PrintLoginRegisterRecordLine(clsUser::stLogInfos LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.Date;
        cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
        cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
        cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
    }

public:
    static void ShowLoginRegisterScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsUser::stLogInfos> vLogInfos = clsUser::LoadLogInfosFromFile();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t (" + to_string(vLogInfos.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogInfos.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLogInfos Record : vLogInfos)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};