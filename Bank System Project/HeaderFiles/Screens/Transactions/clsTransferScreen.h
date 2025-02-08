#pragma once
/*
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
*/

#include "../../../HeaderFiles/Global.h"

class clsTransferScreen : protected clsScreen
{
private:
    static string _ReadAccountNumberToTransferFrom()
    {
        string AccountNumber = "";
        cout << "\nPlease enter Account Number To Transfer From : ";
        cin >> AccountNumber;
        return AccountNumber;
    }

    static string _ReadAccountNumberToTransferTo()
    {
        string AccountNumber = "";
        cout << "\nPlease enter Account Number To Transfer To : ";
        cin >> AccountNumber;
        return AccountNumber;
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";
    }

    struct stTransferLog
    {
        string Date;
        string AccountNumberTransferedForm;
        string AccountNumberTransferedTo;
        double Amount;
        double AccountNumberTransferedForm_Balance;
        double AccountNumberTransferedTo_Balance;
        string UserName;
    };

    static void _AddDataLineToFile(string stDataLine)
    {
        fstream MyFile;
        MyFile.open("TextFiles/TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static string _PrepareTransferLogLine(clsBankClient ClientFrom, clsBankClient ClientTo, double Amount, string Seperator = "#//#")
    {
        string stLogRecord = "";
        stLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
        stLogRecord += ClientFrom.AccountNumber() + Seperator;
        stLogRecord += ClientTo.AccountNumber() + Seperator;
        stLogRecord += to_string(Amount) + Seperator;
        stLogRecord += to_string(ClientFrom.GetAccountBalance()) + Seperator;
        stLogRecord += to_string(ClientTo.GetAccountBalance()) + Seperator;
        stLogRecord += CurrentUser.GetUserName();

        return stLogRecord;
    }

    static void _SaveLogTransfer(clsBankClient ClientFrom, clsBankClient ClientTo, double Amount)
    {
        _AddDataLineToFile(_PrepareTransferLogLine(ClientFrom, ClientTo, Amount));
    }

    static stTransferLog _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
    
        vector <string> TransferLog;
        TransferLog = clsString::Split(Line, Seperator);

        stTransferLog TransferLogStruct;
        TransferLogStruct.Date = TransferLog[0];
        TransferLogStruct.AccountNumberTransferedForm = TransferLog[1];
        TransferLogStruct.AccountNumberTransferedTo = TransferLog[2];
        TransferLogStruct.Amount = stod(TransferLog[3]);
        TransferLogStruct.AccountNumberTransferedForm_Balance = stod(TransferLog[4]);
        TransferLogStruct.AccountNumberTransferedTo_Balance = stod(TransferLog[5]);
        TransferLogStruct.UserName = TransferLog[6];

        return TransferLogStruct;

    }

    static vector <stTransferLog> GetTransfersLogList()
    {
        vector <stTransferLog> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("TextFiles/TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTransferLog TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);

            }

            MyFile.close();

        }

        return vTransferLogRecord;

    }

    static void PrintTransferLogRecordLine(stTransferLog TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.Date;
        cout << "| " << setw(8) << left << TransferLogRecord.AccountNumberTransferedForm;
        cout << "| " << setw(8) << left << TransferLogRecord.AccountNumberTransferedTo;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.AccountNumberTransferedForm_Balance;
        cout << "| " << setw(10) << left << TransferLogRecord.AccountNumberTransferedTo_Balance;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;

      
    }

public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\tTransfer Screen");

        //Read Account Number To Transfer From
        string AccountNumberToTransferFrom = _ReadAccountNumberToTransferFrom();

        while (!clsBankClient::IsClientExist(AccountNumberToTransferFrom))
        {
            cout << "\nClient with [" << AccountNumberToTransferFrom << "] does not exist.\n";
            AccountNumberToTransferFrom = _ReadAccountNumberToTransferFrom();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumberToTransferFrom);
        _PrintClient(Client1);


        //Read Account Number To Transfer To
        string AccountNumberToTransferTo = _ReadAccountNumberToTransferTo();

        while (!clsBankClient::IsClientExist(AccountNumberToTransferTo))
        {
            cout << "\nClient with [" << AccountNumberToTransferTo << "] does not exist.\n";
            AccountNumberToTransferTo = _ReadAccountNumberToTransferTo();
        }

        clsBankClient Client2 = clsBankClient::Find(AccountNumberToTransferTo);
        _PrintClient(Client2);

        

        cout << "\nEnter Transfer Amount : ";
        double Amount;
        cin >> Amount;

        while (Amount > Client1.GetAccountBalance())
        {
            cout << "\nAmount Exceeds the Available Balance, Enter Another Amount : ";
            cin >> Amount;
        }

        cout << "\nAre you sure you want to perform this operation? [Y/N] : ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            if(Client1.Transfer(Amount, Client2))
            {
                cout << "\nTransfer Done Successfully.\n";
                _SaveLogTransfer(Client1, Client2, Amount);
            }
            else
            {
                cout << "\nTransfer Failed.\n";
            }

            _PrintClient(Client1);
            _PrintClient(Client2);
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
        
    }

    static void ShowTransferLogScreen()
    {
        vector <stTransferLog> vTransferLogRecord = GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (stTransferLog Record : vTransferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};