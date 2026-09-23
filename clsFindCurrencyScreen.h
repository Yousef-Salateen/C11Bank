#pragma once

#include "UI Layer/clsScreen.h"
#include "clsCurrencyExchange.h"
#include "External Libs/clsInputValidate.h"

class clsFindCurrencyScreen :
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

public:
    static void FindCurrency()
    {
        short Choice = clsInputValidate::ReadInRange<short>("Find by [1] Code OR [2] Country? ", 1, 2);

        switch (Choice)
        {
        case 1:
        {
            std::string Code = clsInputValidate::Read<std::string>("Enter currency code: ");
            clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(Code);
            if (Currency.IsEmpty())
            {
                std::cout << "Currency Not Found!";
                return;
            }
            _PrintCurrency(Currency);
            break;
        }
        case 2:
        {
            std::string Country = clsInputValidate::Read<std::string>("Enter currency country: ");
            clsCurrencyExchange Currency = clsCurrencyExchange::FindByCountry(Country);
            if (Currency.IsEmpty())
            {
                std::cout << "Currency Not Found!";
                return;
            }
            _PrintCurrency(Currency);
            break;
        }
        }
    }
};

