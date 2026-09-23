#pragma once

#include "clsScreen.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalanceScreen.h"
#include "clsTransferScreen.h"

class clsTransactionsMenu :
    protected clsScreen
{
private:
	enum enTransactionMenuOptions
	{
		eDeposit = 1,
		eWithdraw,
		eTotalBalance,
		eTransfer,
		eExit
	};

	static enTransactionMenuOptions _ReadTransactionMenuOption()
	{
		return static_cast<enTransactionMenuOptions>(clsInputValidate::ReadInRange<int>("\nChoose what do you want to do? [1 to 5] : ",
			1, enTransactionMenuOptions::eExit));
	}

	static void _PerformTransactionMenuOption(enTransactionMenuOptions TransactionMenuOption)
	{
		switch (TransactionMenuOption)
		{
		case enTransactionMenuOptions::eDeposit:
			_ShowDepositScreen();
			_WaitForEnter();
			break;
		case enTransactionMenuOptions::eWithdraw:
			_ShowWithdrawScreen();
			_WaitForEnter();
			break;
		case enTransactionMenuOptions::eTotalBalance:
			_ShowTotalBalanceScreen();
			_WaitForEnter();
			break;
		case enTransactionMenuOptions::eExit:
			_ShowExitScreen();
			_WaitForEnter();
			break;
		case enTransactionMenuOptions::eTransfer:
			_ShowTransferScreen();
			_WaitForEnter();
			break;
		default:
			std::cout << "Invalid option! Please try again.\n";
			break;
		}
	}

	static void _ShowDepositScreen()
	{
		_ClearScreen();
		clsDepositScreen::Deposit();
	}

	static void _ShowWithdrawScreen()
	{
		_ClearScreen();
		clsWithdrawScreen::Withdraw();
	}

	static void _ShowTotalBalanceScreen()
	{
		_ClearScreen();
		clsTotalBalanceScreen::PrintClientList();
	}

	static void _ShowTransferScreen()
	{
		_ClearScreen();
		clsTransferScreen::Transfer();
	}

	static void _ShowExitScreen()
	{
		_ClearScreen();
		std::cout << "Exiting the menu.\n";
	}

public:
	static void ShowTransactionScreen()
	{
		if (_AccessMessage(clsSession::CurrentUser.HasPermission(enPermissions::eTransactions)))
		{
			_WaitForEnter();
			return;
		}

		enTransactionMenuOptions MainMenuOption;
		do
		{
			_ClearScreen();
			_DrawScreenHeader("TRANSACTION MENU SCREEN");
			std::cout << std::setw(37) << std::left << "" << "[1] Deposit.\n";
			std::cout << std::setw(37) << std::left << "" << "[2] Withdraw.\n";
			std::cout << std::setw(37) << std::left << "" << "[3] Total Balance.\n";
			std::cout << std::setw(37) << std::left << "" << "[4] Transfer.\n";
			std::cout << std::setw(37) << std::left << "" << "[5] Exit.\n";

			MainMenuOption = _ReadTransactionMenuOption();
			_PerformTransactionMenuOption(MainMenuOption);
		} while (MainMenuOption != enTransactionMenuOptions::eExit);

	}
};

