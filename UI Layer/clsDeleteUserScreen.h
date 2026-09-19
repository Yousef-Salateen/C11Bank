#pragma once

#include "clsUserScreen.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"

class clsDeleteUserScreen :
    protected clsUserScreen
{
public:
	static void DeleteUser()
	{
		_DrawScreenHeader("Delete User Screen");
		std::string Username = clsInputValidate::Read<std::string>("Please Enter a Valid Username: ");

		while (!Users.IsUserExist(Username) || Username == "admin")
		{
			Username = clsInputValidate::Read <std::string>("Username is not found, enter another one: ");
		}

		clsUser User = Users.Find(Username);
		_PrintUser(User);

		if (clsInputValidate::ReadBool("Are you sure you want to delete this user?"))
		{
			if (Users.Delete(Username))
			{
				std::cout << "User deleted successfully" << std::endl;
			}
			else
			{
				std::cout << "User was not deleted" << std::endl;
			}
		}
	}
};

