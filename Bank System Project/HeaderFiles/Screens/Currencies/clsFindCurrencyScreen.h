#pragma once
#include "../../../HeaderFiles/Global.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static short _GetUserFindChoice()
    {
        cout << "Find By: [1] Code or [2] Country? ";
        short choice = clsInputValidate::ReadShortNumberBetween(1,2);

        return choice;
    }

    static string _GetCode()
    {
        cout << "Enter Currency Code : ";
        string Code = clsInputValidate::ReadString();

        return Code;
    }

    static string _GetCountry()
    {
        cout << "Enter Country : ";
        string Country = clsInputValidate::ReadString();

        return Country;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "Currency not found!" << endl;
        }
    }

public:
    static void ShowFindCurrencyScreen()
    {

        _DrawScreenHeader("\tFind Currency Screen");

        int UserFindChoice = _GetUserFindChoice();
        
        if (UserFindChoice == 1)
        {
            string Code = _GetCode();
            clsCurrency Currency = clsCurrency::FindByCode(Code);
            _ShowResults(Currency);
        }
        else if (UserFindChoice == 2)
        {
            string Country = _GetCountry();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }


        
    }



};