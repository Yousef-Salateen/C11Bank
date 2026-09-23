#pragma once

#include <string>

class clsLoginInfo
{
private:
	std::string _DateLine;
	std::string _Username;
	std::string _Password;
	int _Permissions = 0;
	bool _MarkedForDelete = false;

public:
	clsLoginInfo(const std::string& DateLine, const std::string& Username, const std::string& Password, int Permissions) :
		_DateLine(DateLine), _Username(Username), _Password(Password), _Permissions(Permissions)
	{

	}

	void setDateLine(const std::string& DateLine)
	{
		_DateLine = DateLine;
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

	void setMarkedForDelete(bool MarkedForDelete)
	{
		_MarkedForDelete = MarkedForDelete;
	}

	std::string DateLine() const
	{
		return _DateLine;
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

	bool MarkedForDelete() const
	{
		return _MarkedForDelete;
	}

	static clsLoginInfo EmptyObject()
	{
		return clsLoginInfo("", "", "", 0);
	}

	friend class clsLoginData;
	friend class clsLoginLogManager;
};

