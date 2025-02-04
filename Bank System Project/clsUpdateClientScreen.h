#pragma once

#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen
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
    static void UpdateClientScreen()
    {
        _DrawScreenHeader("\t  Update Client Screen");

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

        cout << "\nAre You Sure you Want to update this client? [Y/N] : ";
        char Answer;
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            _ReadClientInfo(Client);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";
              
                _PrintClientCard(Client);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }
            
        }
    }
};