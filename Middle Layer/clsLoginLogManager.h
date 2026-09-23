#pragma once

extern short _EncryptionKey;

#include "clsManager.h"
#include "clsLoginInfo.h"
#include "../Global.h"

class clsLoginLogManager :
    public clsManager<clsLoginInfo>
{
public:
	clsLoginLogManager() : clsManager(clsData::LoadLoginLogs)
	{
		for (clsLoginInfo* Info : _vItems)
		{
			Info->setPassword(clsUtility::DecryptText(Info->Password(), _EncryptionKey));
		}
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
		clsLoginInfo temp = LoginInfo;
		_vItems.emplace_back(new clsLoginInfo(temp));

		temp.setPassword(clsUtility::DecryptText(temp.Password(), _EncryptionKey));
		clsData::SaveLogin(clsLoginData::ConvertObjectToLine(&temp));
	}
};

