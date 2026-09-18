#pragma once

extern enum enPermissions : short;

#include "clsPerson.h"
#include <string>

class clsUser :
    public clsPerson
{
private:
	std::string _Username;
	std::string _Password;
	int _Permissions = 0;

public:
	clsUser(const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone,
		const std::string& Username, const std::string& Password, int Permissions, enMode Mode)
		: clsPerson(FirstName, LastName, Email, Phone, Mode), _Username(Username), _Password(Password), _Permissions(Permissions)
	{

	}

	static clsUser EmptyObject()
	{
		return clsUser("", "", "", "", "", "", 0, enMode::_EmptyMode);
	}

	std::string Username() const
	{
		return _Username;
	}

	std::string Password() const
	{
		return _Password;
	}

	int Permissions() const
	{
		return _Permissions;
	}

	bool IsEmpty() const
	{
		return _Mode == enMode::_EmptyMode;
	}

	void setUsername(const std::string& Username)
	{
		_Username = Username;
	}

	void setPassword(const std::string& Password)
	{
		_Password = Password;
	}

	void setPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	bool HasPermission (enPermissions Permission) const
	{
		return (_Permissions & Permission) == Permission;
	}

	friend class clsUsersData;
	friend class clsUserManager;
	friend class clsSession;
};
