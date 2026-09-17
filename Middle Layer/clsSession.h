#pragma once

#include "clsUser.h"
#include "../Global.h"

//#include "../UI Layer/clsLoginScreen.h"

class clsSession
{
private:
	clsUser _CurrentUser;

public:
	clsSession(const std::string& Username, const std::string& Password)
		: _CurrentUser(Users.Find(Username, Password))
	{
		
	}

	~clsSession()
	{
		_CurrentUser = Users.Find("", "");
	}
};

