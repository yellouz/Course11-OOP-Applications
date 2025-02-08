#pragma once
/*
#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"

using namespace std;
*/

#include "../../../HeaderFiles/Global.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
    static void _PrintClientCard(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }
    
public:
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Delete Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number not found, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client);

        cout << "\nAre You Sure you Want to delete this client? [Y/N] : ";
        char Answer;
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Delete())
            {
                cout << "Client Deleted Successfully.\n";

                _PrintClientCard(Client);
            }
            else
            {
                cout << "Error, Client was not deleted\n";
            }
            
        }
    }
};