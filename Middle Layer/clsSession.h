#pragma once

#include "clsUser.h"
#include "../Global.h"
#include "../External Libs/clsDate.h"
#include "../Data Layer/clsData.h"

class clsSession
{
public:
	inline static clsUser CurrentUser = (clsUser::EmptyObject());
	inline static short LoginTries = 3;

	clsSession() = default;

	clsSession(const clsUser& User)
	{
		CurrentUser = User;
		LoginTries = 3;

		std::vector<std::string> vLogLine;

		vLogLine.push_back(clsDate::GetSystemDateTimeString());
		vLogLine.push_back(CurrentUser.Username());
		vLogLine.push_back(CurrentUser.Password());
		vLogLine.push_back(std::to_string(CurrentUser.Permissions()));

		clsData::SaveLog(vLogLine);
	}

	~clsSession()
	{
		CurrentUser = clsUser::EmptyObject();
		LoginTries = 3;
	}

};