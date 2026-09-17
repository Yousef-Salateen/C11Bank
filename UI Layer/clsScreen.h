#pragma once

#include "../Global.h"
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
};

