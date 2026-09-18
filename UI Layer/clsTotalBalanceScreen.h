#pragma once

#include "clsScreen.h"
#include "../Global.h"
#include "../Middle Layer/clsClient.h"
#include "../External Libs/clsUtility.h"

class clsTotalBalanceScreen :
    protected clsScreen
{
private:
	static void _PrintClientBalanceLine(const clsClient& Client)
	{
		std::cout << "|" << std::left << std::setw(15) << Client.AccNumber();
		std::cout << "|" << std::left << std::setw(40) << Client.FullName();
		std::cout << "|" << std::left << std::setw(10) << Client.Balance() << std::endl;
	}

public:
	static void PrintClientList()
	{
		std::string Title = "Client Balance List Screen";
		std::string SubTitle = "(" + std::to_string(Clients.Amount()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);

		std::cout << "|" << std::left << std::setw(15) << "Account Number";
		std::cout << "|" << std::left << std::setw(40) << "Name";
		std::cout << "|" << std::left << std::setw(10) << "Balance" << std::endl;
		std::cout << "\n____________________________________________________________________________________________________________________" << std::endl;

		double TotalBalances = Clients.GetTotalBalance();

		if (Clients.Amount())
			for (size_t i = 0; i < Clients.Amount(); i++)
			{
				_PrintClientBalanceLine(Clients.Item(i));
			}
		else
			std::cout << "No clients are found\n";

		std::cout << "\n____________________________________________________________________________________________________________________" << std::endl;

		std::cout << "\t\t\t\tTotal Balances: " << TotalBalances;
		std::cout << "\n\t\t\t\t" << clsUtility::NumberToText(TotalBalances) << std::endl;
	}

};

