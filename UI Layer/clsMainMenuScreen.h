#pragma once

#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "../External Libs/clsInputValidate.h"
#include "clsListClientsScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"

class clsMainMenuScreen :
    protected clsScreen
{
private:
	enum enMainMenuOptions
	{
		eShowClientsList = 1,
		eAddNewClient,
		eDeleteClient,
		eUpdateClient,
		eFindClient,
		eShowTransactionsScreen,
		eManageUsersScreen,
		eLogout
	};

	static enMainMenuOptions _ReadMainMenuOption()
	{
		return static_cast<enMainMenuOptions>(clsInputValidate::ReadInRange<int>("\nChoose what do you want to do? [1 to 8] : ",
			1, enMainMenuOptions::eLogout));
	}

	static void _ClearScreen()
	{
		std::cout << "\033[2J\033[1;1H";
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::eShowClientsList:
			_ShowClientsListScreen();
			_WaitForEnter();
			break;
		case enMainMenuOptions::eAddNewClient:
			_ShowAddNewClientScreen();
			_WaitForEnter();
			break;
		case enMainMenuOptions::eDeleteClient:
			_ShowDeleteClientScreen();
			_WaitForEnter();
			break;
		case enMainMenuOptions::eUpdateClient:
			_ShowUpdateClientScreen();
			_WaitForEnter();
			break;
		case enMainMenuOptions::eFindClient:
			_ShowFindClientScreen();
			_WaitForEnter();
			break;
		case enMainMenuOptions::eShowTransactionsScreen:
			_ShowTransactionsScreen();
			break;
		case enMainMenuOptions::eManageUsersScreen:
			_ShowManageUsersScreen();
			break;
		case enMainMenuOptions::eLogout:
			_Logout();
			break;
		default:
			std::cout << "Invalid option! Please try again.\n";
			break;
		}
	}

	static void _ShowClientsListScreen()
	{
		_ClearScreen();
		clsListClientsScreen::PrintClientList();
	}

	static void _ShowAddNewClientScreen()
	{
		_ClearScreen();
		clsAddNewClientScreen::AddClient();
	}

	static void _ShowDeleteClientScreen()
	{
		_ClearScreen();
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen()
	{
		_ClearScreen();
		std::cout << "List will be done here.";
	}

	static void _ShowFindClientScreen()
	{
		_ClearScreen();
		std::cout << "List will be done here.";
	}

	static void _ShowTransactionsScreen()
	{
		_ClearScreen();
		std::cout << "List will be done here.";
	}

	static void _ShowManageUsersScreen()
	{
		_ClearScreen();
		std::cout << "List will be done here.";
	}

	static void _Logout()
	{
		_ClearScreen();
	}

public:
	static void ShowMainMenuScreen()
	{
		enMainMenuOptions MainMenuOption;
		do
		{
			_ClearScreen();
			_DrawScreenHeader("MAIN MENU SCREEN");
			std::cout << std::setw(37) << std::left << "" << "[1] Show Clients List.\n";
			std::cout << std::setw(37) << std::left << "" << "[2] Add New Client.\n";
			std::cout << std::setw(37) << std::left << "" << "[3] Delete Client.\n";
			std::cout << std::setw(37) << std::left << "" << "[4] Update Client Info.\n";
			std::cout << std::setw(37) << std::left << "" << "[5] Find Client.\n";
			std::cout << std::setw(37) << std::left << "" << "[6] Show Transactions Screen.\n";
			std::cout << std::setw(37) << std::left << "" << "[7] Manage Users Screen.\n";
			std::cout << std::setw(37) << std::left << "" << "[8] Logout.\n";

			MainMenuOption = _ReadMainMenuOption();
			_PerformMainMenuOption(MainMenuOption);
		} while (MainMenuOption != enMainMenuOptions::eLogout);

	}
};

