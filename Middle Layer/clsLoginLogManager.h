#pragma once

#include "clsManager.h"
#include "clsLoginInfo.h"

class clsLoginLogManager :
    public clsManager<clsLoginInfo>
{
public:
	clsLoginLogManager() : clsManager(clsData::LoadLoginLogs)
	{
	}
	
	~clsLoginLogManager()
	{
		for (clsLoginInfo* LoginInfo : _vItems)
		{
			delete LoginInfo;
		}
	}

	void AddNewLog(const clsLoginInfo& LoginInfo)
	{
		_vItems.emplace_back(new clsLoginInfo(LoginInfo));
		clsData::SaveLogin(clsLoginData::ConvertObjectToLine(_vItems.back()));
	}
};

