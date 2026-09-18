#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsDeleteClientScreen :
    protected clsScreen
{
private:
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

public:
	static void DeleteClient()
	{
		if (_AccessMessage(clsSession::CurrentUser.HasPermission(enPermissions::eDeleteClient)))
			return;

		_DrawScreenHeader("Delete Client Screen");
		std::string AccNumber = clsInputValidate::Read<std::string>("Please Enter a Valid Account Number: ");

		while (!Clients.IsClientExist(AccNumber))
		{
			AccNumber = clsInputValidate::Read <std::string>("Account Number is not found, enter another one: ");
		}

		clsClient Client = Clients.Find(AccNumber);
		_PrintClient(Client);

		if (clsInputValidate::ReadBool("Are you sure you want to delete this client?"))
		{
			if (Clients.Delete(AccNumber))
			{
				std::cout << "Client deleted successfully" << std::endl;
			}
			else
			{
				std::cout << "Client was not deleted" << std::endl;
			}
		}
	}
};

