#pragma once

#include <iostream>
#include <iomanip>

class clsScreen
{
protected:
	static void _DrawScreenHeader(const std::string& Title, const std::string& SubTitle = "")
	{
		std::cout << std::setw(37) << std::left << "" << "_________________________\n\n";
		std::cout << std::setw(37) << std::left << "" << Title << "\n";
		if (!SubTitle.empty())
		{
			std::cout << std::setw(37) << std::left << "" << SubTitle << "\n";
		}
		std::cout << std::setw(37) << std::left << "" << "_________________________\n\n";
	}

	static bool _AccessMessage(bool HasAccess)
	{
		if (HasAccess)
			return false;
		else
		{
			_DrawScreenHeader("You don't have access to this. Contact your admin");
			return true;
		}
	}

	static void _WaitForEnter()
	{
		std::cout << "\nPress Enter to continue...";
		std::cin.get();
	}

	static void _ClearScreen()
	{
		std::cout << "\033[2J\033[1;1H";
	}
};

