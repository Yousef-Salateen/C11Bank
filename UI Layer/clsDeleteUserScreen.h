#pragma once

#include "clsScreen.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"

class clsDeleteUserScreen :
    protected clsScreen
{
private:
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

public:
	static void DeleteUser()
	{
		_DrawScreenHeader("Delete User Screen");
		std::string Username = clsInputValidate::Read<std::string>("Please Enter a Valid Username: ");

		while (!Users.IsUserExist(Username))
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

