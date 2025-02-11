#pragma once
#include "../../../HeaderFiles/Global.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
    static string _GetCurrencyCode()
    {
        cout << "Enter Currency Code : ";
        string Code = clsInputValidate::ReadString();

        return Code;
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


public:
    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\tUpdate Currency Rate Screen");

        string CurrencyCode = _GetCurrencyCode();
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        if (Currency.IsEmpty())
        {
            cout << "Currency not found!" << endl;
            return;
        }

        _PrintCurrency(Currency);
        cout << "Are you sure you want to update the rate of this currency [Y/N] : ";
        char Answer;
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nUpdate Currency Rate:" << endl;
            cout << "_____________________" << endl;
            cout << "Enter New Rate: ";

            float NewRate = 0;
            cin >> NewRate;

            Currency.UpdateRate(NewRate);
            
            cout << "\nCurrency Rate Updated Successfully." << endl;
            _PrintCurrency(Currency);
        }
        
        
    }
};