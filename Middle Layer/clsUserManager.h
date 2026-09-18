#pragma once

extern enum enPermissions : short;

#include <vector>
#include "clsManager.h"
#include "clsUser.h"
#include "../Data Layer/clsData.h"
#include "clsSession.h"

class clsUserManager :
    public clsManager <clsUser> 
{
private:
	clsUser* _Find(const std::string& Username) const
	{
		for (const clsUser* User : _vItems)
		{
			if (User->Username() == Username)
			{
				return const_cast<clsUser*>(User);
			}
		}

		return nullptr;
	}

	clsUser* _Find(const std::string& Username, const std::string& Password) const
	{
		for (const clsUser* User : _vItems)
		{
			if (User->Username() == Username && User->Password() == Password)
			{
				return const_cast<clsUser*>(User);
			}
		}
		return nullptr;
	}

	void _AddUser(clsUser* User)
	{
		_vItems.emplace_back(User);
	}

	void _UpdateUser(clsUser* User, const clsUser& NewInfo)
	{
		*User = NewInfo;
	}

	void _DeleteUser(clsUser* User)
	{
		size_t index = _PtrIndex(User);
		if (index != -1)
		{
			delete User;
			_vItems.erase(_vItems.begin() + index);
		}
	}

public:
	clsUserManager() : clsManager(clsData::LoadUsers)
	{

	}

	~clsUserManager()
	{
		Save();
		for (clsUser* User : _vItems)
		{
			delete User;
		}
	}

	bool IsUserExist(const std::string& Username) const
	{
		return _Find(Username) != nullptr;
	}

	clsUser Find(const std::string& Username) const
	{
		clsUser* User = _Find(Username);

		return User ? *User : clsUser::EmptyObject();
	}

	clsUser Find(const std::string& Username, const std::string& Password) const
	{
		clsUser* User = _Find(Username, Password);

		return User ? *User : clsUser::EmptyObject();
	}

	enSaveResult SaveUser(const clsUser& User)
	{
		if (User.IsEmpty())
		{
			return clsManager::enSaveResult::eFailedEmptyObject;
		}
		if (User._Mode != clsUser::enMode::_UpdateMode 
			&& IsUserExist(User.Username()))
		{
			return clsManager::enSaveResult::eFailedExistingUsername;
		}

		switch (User._Mode)
		{
		case clsUser::enMode::_AddNewMode:
			_AddUser(new clsUser(User));
			break;

		case clsUser::enMode::_UpdateMode:
			clsUser* ptrUser = _Find(User.Username());
			_UpdateUser(ptrUser, User);
			break;
		}

		Save();

		return clsManager::enSaveResult::eSucceeded;
	}

	bool Delete(const std::string& Username)
	{
		clsUser* User = _Find(Username);

		if (User)
		{
			_DeleteUser(User);
			Save();
			return true;
		}
		else
		{
			return false;
		}
	}

	clsUser AddNewObject()
	{
		return clsUser("", "", "", "", "", "", 0, clsPerson::enMode::_AddNewMode);
	}

	clsUser User(size_t index)
	{
		if (index >= 0 && index < _vItems.size())
			return *_vItems[index];
		return clsUser::EmptyObject();
	}

	bool HasPermission(const std::string& Username, enPermissions Permission)
	{
		clsUser* User = _Find(Username);
		return User ? User->HasPermission(Permission) : false;
	}
};

