
#include <iostream>

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsMainScreen.h"

using namespace std;

/*
void ReadClientInfo(clsBankClient &Client)
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

void AddNewClient()
{
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number in use, choose another one : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResults = NewClient.Save();

        switch (SaveResults)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nClient Added Successfully :-)\n";
            NewClient.Print();
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

void PrintClientRecordLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.GetPhone();
    cout << "| " << setw(20) << left << Client.GetEmail();
    cout << "| " << setw(10) << left << Client.GetPinCode();
    cout << "| " << setw(12) << left << Client.GetAccountBalance();

}

void ShowClientsList()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}

void DeleteClient()
{
    string AccountNumber = "";
    cout << "\nPlease Enter Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number not found, choose another one : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    cout << "\nAre You Sure you Want to delete this client? [Y/N] : ";
    char Answer;
    cin >> Answer;

    if (Answer == 'Y' || Answer == 'y')
    {
        if (Client.Delete())
        {
            cout << "Client Deleted Successfully.\n";

            Client.Print();
        }
        else
        {
            cout << "Error, Client was not deleted\n";
        }
        
    }
    

}

*/

void PrintClientRecordBalanceLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.GetAccountBalance();

}

void ShowTotalBalances()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
    cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
}

int main()
{
   
    clsMainScreen::ShowMainMenue();
}