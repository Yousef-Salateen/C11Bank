#pragma once

extern enum enPermissions;

#include <vector>
#include "clsManager.h"
#include "clsUser.h"
#include "../Data Layer/clsData.h"

class clsUserManager :
    protected clsManager
{
private:
	std::vector<clsUser*> _vUsers;

	clsUser* _Find(const std::string& Username) const
	{
		for (const clsUser* User : _vUsers)
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
		for (const clsUser* User : _vUsers)
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
		_vUsers.emplace_back(User);
	}

	void _UpdateUser(clsUser* User, const clsUser& NewInfo)
	{
		*User = NewInfo;
	}

	size_t _PtrIndex(clsUser* ptr)
	{
		for (size_t i = 0; i < _vUsers.size(); i++)
		{
			if (_vUsers[i] == ptr)
			{
				return i;
			}
		}

		return -1;
	}

	void _DeleteUser(clsUser* User)
	{
		size_t index = _PtrIndex(User);
		if (index != -1)
		{
			delete User;
			_vUsers.erase(_vUsers.begin() + index);
		}
	}

public:
	clsUserManager() : _vUsers(clsData::LoadUsers())
	{

	}

	~clsUserManager()
	{
		Save();
		for (clsUser* User : _vUsers)
		{
			delete User;
		}
	}

	void Save() const
	{
		clsData::Save(_vUsers);
	}

	bool IsUserExist(const std::string& Username) const
	{
		return _Find(Username) != nullptr;
	}

	clsUser Find(const std::string& Username) const
	{
		clsUser* User = _Find(Username);

		return User ? *User : clsUser::_EmptyObject();
	}

	clsUser Find(const std::string& Username, const std::string& Password) const
	{
		clsUser* User = _Find(Username, Password);

		return User ? *User : clsUser::_EmptyObject();
	}

	enSaveResult SaveUser(const clsUser& User)
	{
		if (User.IsEmpty())
		{
			return clsManager::enSaveResult::eFailedEmptyObject;
		}
		if (IsUserExist(User.Username()))
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
			return true;
		}
		else
		{
			return false;
		}
	}

	clsUser AddNewObject()
	{
		return clsUser("", "", "", "", "", "", 0.0, clsPerson::enMode::_AddNewMode);
	}

	clsUser User(size_t index)
	{
		if (index >= 0 && index < _vUsers.size())
			return *_vUsers[index];
		return clsUser::_EmptyObject();
	}

	bool HasPermission(const std::string& Username, enPermissions Permission)
	{
		clsUser* User = _Find(Username);
		return User->HasPermission(Permission);
	}
};

