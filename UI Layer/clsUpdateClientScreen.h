#pragma once

#include "clsClientScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsUpdateClientScreen :
    protected clsClientScreen
{
public:
	static void UpdateClient()
	{
		if (_AccessMessage(clsSession::CurrentUser.HasPermission(enPermissions::eUpdateClient)))
			return;

		_DrawScreenHeader("Update Client Screen");
		std::string AccNumber = clsInputValidate::Read<std::string>("Please Enter a Valid Account Number: ");

		while (!Clients.IsClientExist(AccNumber))
		{
			AccNumber = clsInputValidate::Read <std::string>("Account Number is not found, enter another one: ");
		}

		clsClient Client = Clients.Find(AccNumber);
		_PrintClient(Client);

		std::cout << "\nUpdate Client Info";
		std::cout << "\n____________________\n";

		_ReadClient(Client);

		clsManager<clsClient>::enSaveResult SaveResult;

		SaveResult = Clients.SaveClient(Client);

		switch (SaveResult)
		{
		default: case Clients.enSaveResult::eFailedEmptyObject:
			std::cout << "Failed the save, object is empty" << std::endl;
			break;

		case Clients.enSaveResult::eSucceeded:
			std::cout << "\nUpdated Successfully\n";
			_PrintClient(Client);
			break;
		}
	}
};

