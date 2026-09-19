#pragma once

#include "clsUserScreen.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"

class clsUpdateUserScreen :
    protected clsUserScreen
{
public:
	static void UpdateUser()
	{
		_DrawScreenHeader("Update User Screen");
		std::string Username = clsInputValidate::Read<std::string>("Please Enter a Valid Username: ");

		while (!Users.IsUserExist(Username) || Username == "admin")
		{
			Username = clsInputValidate::Read <std::string>("Username is not found, enter another one: ");
		}

		clsUser User = Users.Find(Username);
		_PrintUser(User);

		std::cout << "\nUpdate User Info";
		std::cout << "\n____________________\n";

		_ReadUser(User);

		clsManager<clsUser>::enSaveResult SaveResult;

		SaveResult = Users.SaveUser(User);

		switch (SaveResult)
		{
		default: case clsManager<clsUser>::enSaveResult::eFailedEmptyObject:
			std::cout << "Failed the save, object is empty" << std::endl;
			break;

		case clsManager<clsUser>::enSaveResult::eSucceeded:
			std::cout << "\nUpdated Successfully\n";
			_PrintUser(User);
			break;
		}
	}
};

