#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsSession.h"
#include "../External Libs/clsInputValidate.h"
#include "clsMainMenuScreen.h"
#include "../Global.h"

class clsLoginScreen :
    protected clsScreen
{
private:
    static void _Login()
    {
		clsSession Session;

		std::string Username = clsInputValidate::Read<std::string>("Please Enter Your Username: ");
		std::string Password = clsInputValidate::Read<std::string>("Please Enter Your Password: ");

		Session.CurrentUser = Users.Find(Username, Password);
		while (Session.CurrentUser.IsEmpty())
		{
			std::cout << "\nInvalid Username or Password, please try again.";
			std::cout << "\nYou have " << --Session.LoginTries << " tries left\n";
			if (!Session.LoginTries)
				return;

			Username = clsInputValidate::Read<std::string>("Please Enter Your Username: ");
			Password = clsInputValidate::Read<std::string>("Please Enter Your Password: ");
			Session.CurrentUser = Users.Find(Username, Password);
		}

		clsMainMenuScreen::ShowMainMenuScreen();
    }

public:

    static void Login()
    {
		_DrawScreenHeader("Login Screen");
		_Login();
    }
};

