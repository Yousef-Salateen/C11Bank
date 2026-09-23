#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "../Global.h"

class clsLoginLogsScreen
	: protected clsScreen
{
private:
	static void _PrintLoginLine(const clsLoginInfo& LoginInfo)
	{
		std::cout << "|" << std::left << std::setw(40) << LoginInfo.DateLine();
		std::cout << "|" << std::left << std::setw(15) << LoginInfo.Username();
		std::cout << "|" << std::left << std::setw(10) << LoginInfo.Password();
		std::cout << "|" << std::left << std::setw(10) << LoginInfo.Permissions();
		std::cout << std::endl;
	}

public:
	static void ListLogins()
	{
		if (_AccessMessage(clsSession::CurrentUser.HasPermission(enPermissions::eListLoginLogs)))
			return;

		std::string Title = "Client List Screen";
		std::string SubTitle = "(" + std::to_string(Clients.Amount()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);

		std::cout << "|" << std::left << std::setw(40) << "Date";
		std::cout << "|" << std::left << std::setw(15) << "User Name";
		std::cout << "|" << std::left << std::setw(10) << "Password";
		std::cout << "|" << std::left << std::setw(10) << "Permissions" << std::endl;
		std::cout << "\n____________________________________________________________________________________________________________________" << std::endl;

		if (Clients.Amount())
			for (size_t i = 0; i < LoginLogs.Amount(); i++)
			{
				_PrintLoginLine(LoginLogs.Item(i));
			}
		else
			std::cout << "No clients are found\n";

		std::cout << "\n____________________________________________________________________________________________________________________" << std::endl;
	}
};

