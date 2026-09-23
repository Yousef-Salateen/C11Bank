#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsUser.h"
#include "../External Libs/clsInputValidate.h"
#include "../Global.h"

class clsUserScreen :
    protected clsScreen
{
protected:
    enum enDisplayInfo { eAll = 1, ePassword, ePhone, ePernissions };

	static void _PrintUserLine(const clsUser& User, enDisplayInfo ToDisplay = enDisplayInfo::eAll)
	{
		std::cout << "|" << std::left << std::setw(15) << User.Username();
		std::cout << "|" << std::left << std::setw(40) << User.FullName();

        switch (ToDisplay)
        {
        case enDisplayInfo::eAll:
        case enDisplayInfo::ePassword:
            std::cout << "|" << std::left << std::setw(10) << User.Password();
            if (ToDisplay != enDisplayInfo::eAll) break;

        case enDisplayInfo::ePhone:
            std::cout << "|" << std::left << std::setw(15) << User.Phone();
            if (ToDisplay != enDisplayInfo::eAll) break;

        case enDisplayInfo::ePernissions:
            std::cout << "|" << std::left << std::setw(10) << User.Permissions();
            if (ToDisplay != enDisplayInfo::eAll) break;
        }

        std::cout << std::endl;
	}

	static void _PrintUser(const clsUser& User)
	{
		std::cout << "\nUser Card:";
		std::cout << "\n_________________";
		std::cout << "\nFirst Name: " << User.FirstName();
		std::cout << "\nLast Name: " << User.LastName();
		std::cout << "\nFull Name: " << User.FullName();
		std::cout << "\nEmail: " << User.Email();
		std::cout << "\nPhone: " << User.Phone();
		std::cout << "\nUsername: " << User.Username();
		std::cout << "\nPassword: " << User.Password();
		std::cout << "\nPermissions: " << User.Permissions();
		std::cout << "\n_________________" << std::endl;
	}

    static void _ReadUser(clsUser& User)
    {
        User.setFirstName(clsInputValidate::Read<std::string>("First Name: "));
        User.setLastName(clsInputValidate::Read<std::string>("Last Name: "));
        User.setEmail(clsInputValidate::Read<std::string>("Email: "));
        User.setPhone(clsInputValidate::Read<std::string>("Phone: "));
        User.setPassword(clsInputValidate::Read<std::string>("Password: "));
        User.setPermissions(_ReadPermissions());
    }

    static int _ReadPermissions()
    {
        int Permissions = 0;

        if (clsInputValidate::ReadBool("Do you want to give all permissions to this user? "))
        {
            Permissions = enPermissions::eAll;
            return Permissions;
        }
        if (clsInputValidate::ReadBool("Do you want to give List Clients permission? "))
        {
            Permissions |= enPermissions::eListClients;
        }
        if (clsInputValidate::ReadBool("Do you want to give Add New Client permission?"))
        {
            Permissions |= enPermissions::eAddNewClient;
        }
        if (clsInputValidate::ReadBool("Do you want to give Delete Client permission?"))
        {
            Permissions |= enPermissions::eDeleteClient;
        }
        if (clsInputValidate::ReadBool("Do you want to give Update Client permission?"))
        {
            Permissions |= enPermissions::eUpdateClient;
        }
        if (clsInputValidate::ReadBool("Do you want to give Find Client permission?"))
        {
            Permissions |= enPermissions::eFindClient;
        }
        if (clsInputValidate::ReadBool("Do you want to give Transactions permission?"))
        {
            Permissions |= enPermissions::eTransactions;
        }
        if (clsInputValidate::ReadBool("Do you want to give Manage Users permission?"))
        {
            Permissions |= enPermissions::eManageUsers;
        }
        if (clsInputValidate::ReadBool("Do you want to give Show Logs permission?"))
        {
            Permissions |= enPermissions::eListLoginLogs;
        }
        return Permissions;
    }
};

