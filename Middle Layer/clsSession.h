#pragma once

#include "clsUser.h"
#include "../Global.h"

class clsSession
{
public:
	clsUser CurrentUser;
	
	clsSession(const std::string& Username, const std::string& Password)
		: CurrentUser(Users.Find(Username, Password))
	{
		
	}

	~clsSession()
	{
		CurrentUser = Users.Find("", "");
	}
};

