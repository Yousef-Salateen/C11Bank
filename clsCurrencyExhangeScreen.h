#pragma once

#include "UI Layer/clsScreen.h"
#include "clsCurrencyExchange.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCalculatorScreen.h"

class clsCurrencyExhangeScreen :
    protected clsScreen
{
private:
	enum enExchangeMenuOptions
	{
		eListCurrencies = 1,
		eFindCurrency,
		eUpdateRate,
		eCalculator,
		eExit
	};

	static enExchangeMenuOptions _ReadExchangeMenuOption()
	{
		return static_cast<enExchangeMenuOptions>(clsInputValidate::ReadInRange<int>("\nChoose what do you want to do? [1 to 5] : ",
			1, enExchangeMenuOptions::eExit));
	}

	static void _PerformExchangeMenuOption(enExchangeMenuOptions ExchangeMenuOption)
	{
		switch (ExchangeMenuOption)
		{
		case enExchangeMenuOptions::eListCurrencies:
			_ShowListCurrenciesScreen();
			_WaitForEnter();
			break;
		case enExchangeMenuOptions::eFindCurrency:
			_ShowFindCurrenciesScreen();
			_WaitForEnter();
			break;
		case enExchangeMenuOptions::eUpdateRate:
			_ShowUpdateRateScreen();
			_WaitForEnter();
			break;
		case enExchangeMenuOptions::eCalculator:
			_ShowCalculator();
			_WaitForEnter();
			break;
		case enExchangeMenuOptions::eExit:
			_ShowExitScreen();
			_WaitForEnter();
			break;
		default:
			std::cout << "Invalid option! Please try again.\n";
			break;
		}
	}

	static void _ShowListCurrenciesScreen()
	{
		clsListCurrenciesScreen::ListCurrencies();
		_ClearScreen();
	}

	static void _ShowFindCurrenciesScreen()
	{
		_ClearScreen();
		clsFindCurrencyScreen::FindCurrency();
	}

	static void _ShowUpdateRateScreen()
	{
		_ClearScreen();
		clsUpdateRateScreen::UpdateCurrency();
	}

	static void _ShowCalculator()
	{
		_ClearScreen();
		clsCalculatorScreen::Calculate();
	}

	static void _ShowExitScreen()
	{
		_ClearScreen();
		std::cout << "Exiting the menu.\n";
	}

public:
	static void ShowExchangeScreen()
	{

		enExchangeMenuOptions ExhangeMenuOption;
		do
		{
			_ClearScreen();
			_DrawScreenHeader("EXCHANGE MENU SCREEN");
			std::cout << std::setw(37) << std::left << "" << "[1] List Currencies.\n";
			std::cout << std::setw(37) << std::left << "" << "[2] Find Currency.\n";
			std::cout << std::setw(37) << std::left << "" << "[3] Update Rate.\n";
			std::cout << std::setw(37) << std::left << "" << "[4] Calculator.\n";
			std::cout << std::setw(37) << std::left << "" << "[5] Exit.\n";

			ExhangeMenuOption = _ReadExchangeMenuOption();
			_PerformExchangeMenuOption(ExhangeMenuOption);
		} while (ExhangeMenuOption != enExchangeMenuOptions::eExit);

	}
};

