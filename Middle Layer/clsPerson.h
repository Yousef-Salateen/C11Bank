#pragma once

#include <string>

class clsPerson
{
private:
	std::string _FirstName;
	std::string _LastName;
	std::string _Email;
	std::string _Phone;

public:
	clsPerson(const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone) :
		_FirstName(FirstName), _LastName(LastName), _Email(Email), _Phone(Phone)
	{

	}

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
