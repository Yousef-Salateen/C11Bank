#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../External Libs/clsInputValidate.h"

class clsClientScreen :
    protected clsScreen
{
protected:
    enum enDisplayInfo {eAll = 1, ePinCode, ePhone, eBalance};
	static void _PrintClientLine(const clsClient& Client, enDisplayInfo ToDisplay = enDisplayInfo::eAll)
	{
        std::cout << "|" << std::left << std::setw(15) << Client.AccNumber();
        std::cout << "|" << std::left << std::setw(40) << Client.FullName();

        switch (ToDisplay)
        {
        case enDisplayInfo::eAll:
        case enDisplayInfo::ePinCode:
            std::cout << "|" << std::left << std::setw(10) << Client.PinCode();
            if (ToDisplay != enDisplayInfo::eAll) break;

        case enDisplayInfo::ePhone:
            std::cout << "|" << std::left << std::setw(15) << Client.Phone();
            if (ToDisplay != enDisplayInfo::eAll) break;

        case enDisplayInfo::eBalance:
            std::cout << "|" << std::left << std::setw(10) << Client.Balance();
            if (ToDisplay != enDisplayInfo::eAll) break;
        }

        std::cout << std::endl;
	}

    static void _PrintClient(const clsClient& Client)
    {
        std::cout << "\nClient Card:";
        std::cout << "\n_________________";
        std::cout << "\nFirst Name: " << Client.FirstName();
        std::cout << "\nLast Name: " << Client.LastName();
        std::cout << "\nFull Name: " << Client.FullName();
        std::cout << "\nEmail: " << Client.Email();
        std::cout << "\nPhone: " << Client.Phone();
        std::cout << "\nAccount Number: " << Client.AccNumber();
        std::cout << "\nPin Code: " << Client.PinCode();
        std::cout << "\nBalance: " << Client.Balance();
        std::cout << "\n_________________" << std::endl;
    }

    static void _ReadClient(clsClient& Client)
    {
        Client.setFirstName(clsInputValidate::Read<std::string>("First Name: "));
        Client.setLastName(clsInputValidate::Read<std::string>("Last Name: "));
        Client.setEmail(clsInputValidate::Read<std::string>("Email: "));
        Client.setPhone(clsInputValidate::Read<std::string>("Phone: "));
        Client.setPinCode(clsInputValidate::Read<std::string>("Pin Code: "));
        Client.setBalance(clsInputValidate::Read<double>("Balance: "));
    }
};

