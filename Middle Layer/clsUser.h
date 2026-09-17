#pragma once

#include "clsPerson.h"
#include <string>

class clsUser :
    public clsPerson
{
private:
	enum enMode : char { _EmptyMode = 0, _UpdateMode, _AddNewMode };

	enMode _Mode;
	std::string _Username;
	std::string _Password;
	int _Permissions = 0;
	bool _MarkedForDelete = false;

	void _setMode(enMode Mode)
	{
		_Mode = Mode;
	}

	void _setPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	void _setMarkedForDelete(bool MarkedForDelete)
	{
		_MarkedForDelete = MarkedForDelete;
	}

public:
	clsUser(const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone,
		const std::string& Username, const std::string& Password, int Permissions, enMode Mode)
		: clsPerson(FirstName, LastName, Email, Phone), _Username(Username), _Password(Password), _Permissions(Permissions), _Mode(Mode)
	{
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

	bool MarkedForDelete() const
	{
		return _MarkedForDelete;
	}

	void setUsername(const std::string& Username)
	{
		_Username = Username;
	}

	void setPassword(const std::string& Password)
	{
		_Password = Password;
	}

};
