#pragma once

#include "clsScreen.h"
#include "../Global.h"

class clsListClientsScreen
	: protected clsScreen
{
private:
	static void _PrintClientLine(const clsClient& Client)
	{
		std::cout << "|" << std::left << std::setw(15) << Client.AccNumber();
		std::cout << "|" << std::left << std::setw(40) << Client.FullName();
		std::cout << "|" << std::left << std::setw(10) << Client.PinCode();
		std::cout << "|" << std::left << std::setw(15) << Client.Phone();
		std::cout << "|" << std::left << std::setw(10) << Client.Balance() << std::endl;
	}

public:

	static void PrintClientList()
	{
		if (_AccessMessage(clsSession::CurrentUser.HasPermission( enPermissions::eListClients)))
			return;


		std::string Title = "Client List Screen";
		std::string SubTitle = "(" + std::to_string(Clients.Amount()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);

		std::cout << "|" << std::left << std::setw(15) << "Account Number";
		std::cout << "|" << std::left << std::setw(40) << "Name";
		std::cout << "|" << std::left << std::setw(10) << "Pin Code";
		std::cout << "|" << std::left << std::setw(15) << "Phone Number";
		std::cout << "|" << std::left << std::setw(10) << "Balance" << std::endl;
		std::cout << "\n____________________________________________________________________________________________________________________" << std::endl;

		if (Clients.Amount())
			for (size_t i = 0; i < Clients.Amount(); i++)
			{
				_PrintClientLine(Clients.Item(i));
			}
		else
			std::cout << "No clients are found\n";

		std::cout << "\n____________________________________________________________________________________________________________________" << std::endl;
	}
};