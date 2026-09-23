#pragma once

#include "clsUser.h"
#include "../Global.h"
#include "../Data Layer/clsData.h"
#include "clsLoginLogManager.h"
#include "../External Libs/clsDate.h"

class clsSession
{
public:
	inline static clsUser CurrentUser = (clsUser::EmptyObject());
	inline static short LoginTries = 3;

	clsSession() = default;

	clsSession(const clsUser& User)
	{
		LoginTries = 3;
		CurrentUser = User;

		LoginLogs.AddNewLog(clsLoginInfo(clsDate::GetSystemDateTimeString(),
			CurrentUser.Username(), CurrentUser.Password(), CurrentUser.Permissions()));
	}

	~clsSession()
	{
		CurrentUser = clsUser::EmptyObject();
		LoginTries = 3;
	}

};