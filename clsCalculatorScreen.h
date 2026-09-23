#pragma once

#include "UI Layer/clsScreen.h"
#include "clsCurrencyExchange.h"
#include "External Libs/clsInputValidate.h"

class clsCalculatorScreen :
    protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrencyExchange Currency)
    {
        std::cout << "\nCurrency Card:\n";
        std::cout << "_____________________________\n";
        std::cout << "\nCountry    : " << Currency.Country();
        std::cout << "\nCode       : " << Currency.CurrencyCode();
        std::cout << "\nName       : " << Currency.CurrencyName();
        std::cout << "\nRate(1$) = : " << Currency.Rate();

        std::cout << "\n_____________________________\n";

    }

    static clsCurrencyExchange _ReadCurrency(const std::string Msg)
    {
        std::string Code = clsInputValidate::Read<std::string>(Msg);
        clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(Code);
        while (Currency.IsEmpty())
        {
            Code = clsInputValidate::Read<std::string>(Msg);
            clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(Code);
        }

        return Currency;
    }

public:
    static void Calculate()
    {
        do
        {
            _ClearScreen();
            clsCurrencyExchange Currency1 = _ReadCurrency("Enter currency1: ");
            clsCurrencyExchange Currency2 = _ReadCurrency("Enter currency2: ");

            double Amount = clsInputValidate::ReadPositive<double>("Enter amount: ");

            std::cout << "Calculate from: \n";
            _PrintCurrency(Currency1);
            _PrintCurrency(Currency2);
            std::cout << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.ConvertToOtherCurrency(Amount, Currency2) 
                << " " << Currency2.CurrencyCode() << "\n";

        } while (clsInputValidate::ReadBool("Another operation? "));
    }
};

