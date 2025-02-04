#pragma once

#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient &Client)
    {
        cout << "\nFirst Name : ";
        Client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nLast Name : ";
        Client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEmail : ";
        Client.SetEmail(clsInputValidate::ReadString());

        cout << "\nPhone : ";
        Client.SetPhone(clsInputValidate::ReadString());

        cout << "\nPassword : ";
        Client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nAccount Balance : ";
        Client.SetAccountBalance(clsInputValidate::ReadDblNumber());
    }  

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
    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number in use, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResults = NewClient.Save();

        switch (SaveResults)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nClient Added Successfully :-)\n";
            _PrintClientCard(NewClient);
            break;
        
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "Error, Account not saved because it's empty\n";
            break;

        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
            cout << "Error, Account not saved because account number already exists\n";
            break;

        default:

            break;
        }
    }
};