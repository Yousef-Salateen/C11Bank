#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsSession.h"
#include "../External Libs/clsInputValidate.h"

class clsLoginScreen :
    protected clsScreen
{
private:
    static void _Login()
    {
		std::string Username = clsInputValidate::Read<std::string>("Please Enter Your Username: ");
		std::string Password = clsInputValidate::Read<std::string>("Please Enter Your Password: ");

		clsSession Session(Username, Password);

		while (Session.CurrentUser.IsEmpty())
		{
			std::cout << "\nInvalid Username or Password, please try again.\n";
			Username = clsInputValidate::Read<std::string>("Please Enter Your Username: ");
			Password = clsInputValidate::Read<std::string>("Please Enter Your Password: ");
			Session = clsSession(Username, Password);
		}
    }
public:

    static void Login()
    {
		_DrawScreenHeader("Login Screen");
		_Login();
    }
};

