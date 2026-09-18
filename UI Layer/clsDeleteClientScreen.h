#pragma once

#include "clsClientScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsDeleteClientScreen :
    protected clsClientScreen
{
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

