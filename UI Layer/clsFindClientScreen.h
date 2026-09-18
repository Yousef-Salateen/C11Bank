#pragma once

#include "clsClientScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsFindClientScreen :
    protected clsClientScreen
{
public:
	static void FindClient()
	{
		if (_AccessMessage(clsSession::CurrentUser.HasPermission(enPermissions::eFindClient)))
			return;

		_DrawScreenHeader("Update Client Screen");
		std::string AccNumber = clsInputValidate::Read<std::string>("Please Enter a Valid Account Number: ");

		while (!Clients.IsClientExist(AccNumber))
		{
			AccNumber = clsInputValidate::Read <std::string>("Account Number is not found, enter another one: ");
		}

		clsClient Client = Clients.Find(AccNumber);
		if (!Client.IsEmpty())
		{
			std::cout << "\nClient Found Successfully!\n";
			_PrintClient(Client);
		}
		else
		{
			std::cout << "\nClient Not Found!\n";
		}
	}
};

