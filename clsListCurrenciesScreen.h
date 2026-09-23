#pragma once

#include "UI Layer/clsScreen.h"
#include "clsCurrencyExchange.h"

class clsListCurrenciesScreen :
    protected clsScreen
{
private:
    static void _PrintCurrencyRecordLine(const clsCurrencyExchange& Currency)
    {

        std::cout << std::setw(8) << std::left << "" << "| " << std::setw(30) << std::left << Currency.Country();
        std::cout << "| " << std::setw(8) << std::left << Currency.CurrencyCode();
        std::cout << "| " << std::setw(45) << std::left << Currency.CurrencyName();
        std::cout << "| " << std::setw(10) << std::left << Currency.Rate() << std::endl;

    }

public:
    static void ListCurrencies()
    {
        std::vector<clsCurrencyExchange> vCurrencies = clsCurrencyExchange::GetCurrencyList();

        std::string Title = "\t  Currencies List Screen";
        std::string SubTitle = "\t    (" + std::to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);
        std::cout << std::setw(8) << std::left << "" << "\n\t_______________________________________________________";
        std::cout << "_______________________________________________\n" << std::endl;

        std::cout << std::setw(8) << std::left << "" << "| " << std::left << std::setw(30) << "Country";
        std::cout << "| " << std::left << std::setw(8) << "Code";
        std::cout << "| " << std::left << std::setw(45) << "Name";
        std::cout << "| " << std::left << std::setw(10) << "Rate/(1$)";
        std::cout << std::setw(8) << std::left << "" << "\n\t_______________________________________________________";
        std::cout << "_______________________________________________\n" << std::endl;

        if (!vCurrencies.size())
        {
            std::cout << "\t\t\t\tNo Currencies Available In the System!";
        }

        else
            for (const clsCurrencyExchange& C : vCurrencies)
            {
                _PrintCurrencyRecordLine(C);
            }
        std::cout << std::setw(8) << std::left << "" << "\n\t_______________________________________________________";
        std::cout << "_______________________________________________\n" << std::endl;
    }
};

