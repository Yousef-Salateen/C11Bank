#pragma once

#include <string>

class clsPerson
{
private:
	std::string _FirstName;
	std::string _LastName;
	std::string _Email;
	std::string _Phone;

protected:
	enum enMode : char { _EmptyMode = 0, _UpdateMode, _AddNewMode };

	enMode _Mode;

	bool _MarkedForDelete = false;

	void _setMode(enMode Mode)
	{
		_Mode = Mode;
	}

	void _setMarkedForDelete(bool MarkedForDelete)
	{
		_MarkedForDelete = MarkedForDelete;
	}

public:
	clsPerson(const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone, enMode Mode = enMode::_EmptyMode) :
		_FirstName(FirstName), _LastName(LastName), _Email(Email), _Phone(Phone), _Mode(Mode)
	{

	}

	virtual ~clsPerson() = default;

	std::string FirstName() const
	{
		return _FirstName;
	}

	std::string LastName() const
	{
		return _LastName;
	}

	std::string FullName() const 
	{
		return _FirstName + " " + _LastName;
	}

	std::string Email() const 
	{ 
		return _Email;
	}

	std::string Phone() const
	{ 
		return _Phone;
	}

	bool MarkedForDelete() const
	{
		return _MarkedForDelete;
	}

	void setFirstName(const std::string& FirstName)
	{
		_FirstName = FirstName;
	}

	void setLastName(const std::string& LastName)
	{
		_LastName = LastName;
	}

	void setEmail(const std::string& Email)
	{
		_Email = Email;
	}

	void setPhone(const std::string& Phone)
	{
		_Phone = Phone;
	}
};
