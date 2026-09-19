#pragma once

#include "clsUser.h"
#include "../Global.h"

class clsSession
{
public:
	inline static clsUser CurrentUser = (clsUser::EmptyObject());
	inline static short LoginTries = 3;
	~clsSession()
	{
		CurrentUser = clsUser::EmptyObject();
	}

};