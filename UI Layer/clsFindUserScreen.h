#pragma once

#include "clsUserScreen.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"

class clsFindUserScreen :
    protected clsUserScreen
{
public:
	static void FindUser()
	{
		_DrawScreenHeader("Find User Screen");
		std::string Username = clsInputValidate::Read<std::string>("Please Enter a Valid Username: ");

		while (!Users.IsUserExist(Username))
		{
			Username = clsInputValidate::Read <std::string>("Username is not found, enter another one: ");
		}

		clsUser User = Users.Find(Username);
		if (!User.IsEmpty())
		{
			std::cout << "\nUser Found Successfully!\n";
			_PrintUser(User);
		}
		else
		{
			std::cout << "\nUser Not Found!\n";
		}
	}
};

