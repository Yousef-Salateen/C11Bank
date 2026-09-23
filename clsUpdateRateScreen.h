#pragma once

#include "UI Layer/clsScreen.h"
#include "clsCurrencyExchange.h"
#include "External Libs/clsInputValidate.h"

class clsUpdateRateScreen :
    private clsScreen
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
    static void UpdateCurrency()
    {
        std::string Code = clsInputValidate::Read<std::string>("Enter currency code: ");
        clsCurrencyExchange Currency = clsCurrencyExchange::FindByCode(Code);
        if (Currency.IsEmpty())
        {
            std::cout << "Currency Not Found!";
            return;
        }
        _PrintCurrency(Currency);

        if (clsInputValidate::ReadBool("You want to update this currency? "))
        {
            Currency.setRate(clsInputValidate::ReadPositive<double>("Enter new rate: "));
            _PrintCurrency(Currency);
        }
        else
        {
            std::cout << "Update cancelled." << std::endl;
        }
    }
};

