#pragma once
#include "../../../HeaderFiles/Global.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static clsCurrency GetCurrency(string Message)
    {
        cout << Message << endl;
        string CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "Currency not found! Choose another one : ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);        
        return Currency;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }

    static void _PrintCalculationsResult(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
    {
        cout << "\nConvert From: \n";
        _PrintCurrency(CurrencyFrom);
        
        float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
        cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " USD" << endl;

        if (CurrencyTo.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConvert From USD To " << CurrencyTo.CurrencyCode() << " : \n";
        _PrintCurrency(CurrencyTo);

        float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

        cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrency2 << " " << CurrencyTo.CurrencyCode() << endl; 
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        _DrawScreenHeader("\tCurrency Calculator Screen");

        clsCurrency CurrencyFrom = GetCurrency("\nPlease Enter Currency1 Code : ");
        clsCurrency CurrencyTo = GetCurrency("\nPlease Enter Currency2 Code : ");

        cout << "\nEnter Amount to Exchange: ";
        float Amount = 0;
        cin >> Amount;

        _PrintCalculationsResult(CurrencyFrom, CurrencyTo, Amount);
    }
};