#pragma once

#include "../../../HeaderFiles/Global.h"

class clsCurrencyMainScreen : protected clsScreen
{
private:
        enum enCurrencyMenuOption {
            eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
            eCurrencyCalculator = 4, eExit = 5
        };

       static short _ReadCurrencyMenueOption()
        {
            cout <<setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
            short Choice = clsInputValidate::ReadShortNumberBetween(1,5,"\t\t\t\t     Enter Number between 1 to 5? ");
            return Choice;
        }

    static void _GoBackToCurrencyMenu()
    {
        cout << "\n\nPress any key to go back to Currency Menue...";
        system("pause>0");
        ShowCurrencyExchangeMenu();
    }

    static void _ShowListCurrenciesScreen()
    {
        //cout << "Currencies List Screen Will be here..";
        clsListCurrenciesScreen::ShowListCurrenciesScreen();

    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "Find Currency Screen Will be here..";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "Update Rate Screen Will be here..";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "Currency Calculator Screen Will be here..";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyMenuOption(enCurrencyMenuOption CurrencyMenuOption)
    {
        switch (CurrencyMenuOption)
        {
        case enCurrencyMenuOption::eListCurrencies:
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyMenu();
            break;

        case enCurrencyMenuOption::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyMenu();
            break;

        case enCurrencyMenuOption::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyMenu();
            break;

        case enCurrencyMenuOption::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyMenu();
            break;

        case enCurrencyMenuOption::eExit:
            //do nothing here the main screen will handle it :-) ;
           break;
        }
    }

public:
    static void ShowCurrencyExchangeMenu()
    {
        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
            cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
            cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
            cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
            cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerformCurrencyMenuOption((enCurrencyMenuOption)_ReadCurrencyMenueOption());
    }
};