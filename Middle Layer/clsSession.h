#pragma once

#include "clsUser.h"
#include "../Global.h"

class clsSession
{
public:
	inline static clsUser CurrentUser = (clsUser::EmptyObject());

	~clsSession()
	{
		CurrentUser = Users.Find("", "");
	}

};