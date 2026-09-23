#pragma once

#include <string>

class clsTransferInfo
{
private:
	std::string _DateLine;
	std::string _FromAcc;
	std::string _ToAcc;
	double _TransferAmount = 0.0;
	double _NewFromAccBalance = 0.0;
	double _NewToAccBalance = 0.0;
	std::string _Username;
	bool _MarkedForDelete = false;

public:
	clsTransferInfo(const std::string& DateLine, const std::string& FromAcc, const std::string& ToAcc, double TransferAmount, 
					double NewFromAccBalance, double NewToAccBalance, const std::string& Username) :
		_DateLine(DateLine), _FromAcc(FromAcc), _ToAcc(ToAcc), _TransferAmount(TransferAmount), _NewFromAccBalance(NewFromAccBalance),
		_NewToAccBalance(NewToAccBalance), _Username(Username)
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

	void setFromAcc(const std::string& FromAcc)
	{
		_FromAcc = FromAcc;
	}

	void setToAcc(const std::string& ToAcc)
	{
		_ToAcc = ToAcc;
	}

	void setTransferAmount(double TransferAmount)
	{
		_TransferAmount = TransferAmount;
	}

	void setNewFromAccBalance(double NewFromAccBalance)
	{
		_NewFromAccBalance = NewFromAccBalance;
	}

	void setNewToAccBalance(double NewToAccBalance)
	{
		_NewToAccBalance = NewToAccBalance;
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

	std::string FromAcc() const
	{
		return _FromAcc;
	}

	std::string ToAcc() const
	{
		return _ToAcc;
	}

	double TransferAmount() const
	{
		return _TransferAmount;
	}

	double NewFromAccBalance() const
	{
		return _NewFromAccBalance;
	}

	double NewToAccBalance() const
	{
		return _NewToAccBalance;
	}

	bool MarkedForDelete() const
	{
		return _MarkedForDelete;
	}

	static clsTransferInfo EmptyObject()
	{
		return clsTransferInfo("", "", "", 0.0, 0.0, 0.0, "");
	}

	friend class clsTransferData;
	friend class clsTransferLogManager;
};

