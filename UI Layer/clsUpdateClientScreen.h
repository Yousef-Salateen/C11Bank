#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsUpdateClientScreen :
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

	static void _ReadClient(clsClient& Client)
	{
		Client.setFirstName(clsInputValidate::Read<std::string>("First Name: "));
		Client.setLastName(clsInputValidate::Read<std::string>("Last Name: "));
		Client.setEmail(clsInputValidate::Read<std::string>("Email: "));
		Client.setPhone(clsInputValidate::Read<std::string>("Phone: "));
		Client.setPinCode(clsInputValidate::Read<std::string>("Pin Code: "));
		Client.setBalance(clsInputValidate::Read<double>("Balance: "));
	}

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

