#pragma once

#include "clsPerson.h"
#include <string>

class clsClient :
    public clsPerson
{
private:
	std::string _AccNumber;
	std::string _PinCode;
	double _Balance = 0.0;
	bool _MarkedForDelete = false;

	void _setMode(enMode Mode)
	{
		_Mode = Mode;
	}

	void _setMarkedForDelete(bool MarkedForDelete)
	{
		_MarkedForDelete = MarkedForDelete;
	}

	static clsClient _EmptyObject()
	{
		return clsClient("", "", "", "", "", "", 0.0, enMode::_EmptyMode);
	}

public:
	clsClient(const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone,
		const std::string& AccNumber, const std::string& PinCode, double Balance, enMode Mode)
		: clsPerson(FirstName, LastName, Email, Phone, Mode), _AccNumber(AccNumber), _PinCode(PinCode), _Balance(Balance)
	{

	}

	std::string AccNumber() const
	{
		return _AccNumber;
	}

	std::string PinCode() const
	{
		return _PinCode;
	}

	double Balance() const
	{
		return _Balance;
	}
	
	bool IsEmpty() const
	{
		return _Mode == enMode::_EmptyMode;
	}

	bool MarkedForDelete() const
	{
		return _MarkedForDelete;
	}

	void setAccNumber(const std::string& AccNumber)
	{
		_AccNumber = AccNumber;
	}

	void setPinCode(const std::string& PinCode)
	{
		_PinCode = PinCode;
	}

	bool setBalance(double Balance)
	{
		if (Balance < 0)
			return false;

		_Balance = Balance;
		return true;
	}

	friend class clsClientsData;
	friend class clsClientManager;
};
