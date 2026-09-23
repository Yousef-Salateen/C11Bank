#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "../Global.h"

class clsTransferlogScreen
	: protected clsScreen
{
private:
	static void _PrintLoginLine(const clsTransferInfo& TransferInfo)
	{
		std::cout << "|" << std::left << std::setw(40) << TransferInfo.DateLine();
		std::cout << "|" << std::left << std::setw(15) << TransferInfo.FromAcc();
		std::cout << "|" << std::left << std::setw(15) << TransferInfo.ToAcc();
		std::cout << "|" << std::left << std::setw(15) << TransferInfo.TransferAmount();
		std::cout << "|" << std::left << std::setw(10) << TransferInfo.NewFromAccBalance();
		std::cout << "|" << std::left << std::setw(10) << TransferInfo.NewToAccBalance();
		std::cout << "|" << std::left << std::setw(15) << TransferInfo.Username();
		std::cout << std::endl;
	}

public:
	static void ListTransfers()
	{
		std::string Title = "Client List Screen";
		std::string SubTitle = "(" + std::to_string(Clients.Amount()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);

		std::cout << "|" << std::left << std::setw(40) << "DateLine";
		std::cout << "|" << std::left << std::setw(15) << "f.Acc Number";
		std::cout << "|" << std::left << std::setw(15) << "t.Acc Number";
		std::cout << "|" << std::left << std::setw(15) << "Transferred";
		std::cout << "|" << std::left << std::setw(10) << "f.Balance";
		std::cout << "|" << std::left << std::setw(10) << "t.Balance";
		std::cout << "|" << std::left << std::setw(15) << "Username" << std::endl;
		std::cout << "\n____________________________________________________________________________________________________________________" << std::endl;

		if (Clients.Amount())
			for (size_t i = 0; i < TransferLogs.Amount(); i++)
			{
				_PrintLoginLine(TransferLogs.Item(i));
			}
		else
			std::cout << "No clients are found\n";

		std::cout << "\n____________________________________________________________________________________________________________________" << std::endl;
	}
};

