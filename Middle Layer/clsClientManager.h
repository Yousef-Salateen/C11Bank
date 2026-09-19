#pragma once

#include <vector>
#include "clsManager.h"
#include "clsClient.h"
#include "../Data Layer/clsData.h"

class clsClientManager 
	: public clsManager<clsClient>
{
private:
    double TotalBalance = 0.0;
	
	clsClient* _Find(const std::string& AccNumber) const
	{
		for (const clsClient* Client : _vItems)
		{
			if (Client->AccNumber() == AccNumber)
			{
				return const_cast<clsClient*>(Client);
			}
		}

		return nullptr;
	}

	clsClient* _Find(const std::string& AccNumber, const std::string& PinCode) const
	{
		for (const clsClient* Client : _vItems)
		{
			if (Client->AccNumber() == AccNumber && Client->PinCode() == PinCode)
			{
				return const_cast<clsClient*>(Client);
			}
		}
		return nullptr;
	}

	void _AddClient(clsClient* Client)
	{
		Client->_setMode(clsUser::enMode::_UpdateMode);
		_vItems.emplace_back(Client);
		TotalBalance += Client->Balance();
	}

	void _UpdateClient(clsClient* Client, const clsClient& NewInfo)
	{
		TotalBalance -= Client->Balance();
		*Client = NewInfo;
		TotalBalance += Client->Balance();
	}

	void _DeleteClient(clsClient* Client)
	{
		size_t index = _PtrIndex(Client);
		if (index != std::string::npos)
		{
			TotalBalance -= Client->Balance();
			delete Client;
			_vItems.erase(_vItems.begin() + index);
		}
	}

	void _Deposit(double Amount, clsClient* Client)
	{
		if(Client->setBalance(Client->Balance() + Amount))
			TotalBalance += Amount;

	}

	bool _Withdraw(double Amount, clsClient* Client)
	{
		if (Amount > Client->Balance())
			return false;

		bool SuccessfulWithdraw = Client->setBalance(Client->Balance() - Amount);
		if(SuccessfulWithdraw)
			TotalBalance -= Amount;

		return SuccessfulWithdraw;
	}

public:
	clsClientManager() : clsManager(clsData::LoadClients)
	{
		for (const clsClient* Client : _vItems)
		{
			TotalBalance += Client->Balance();
		}
	}

	~clsClientManager()
	{
		Save();
		for (clsClient* Client : _vItems)
		{
			delete Client;
		}
	}

	bool IsClientExist(const std::string& AccNumber) const
	{
		return _Find(AccNumber) != nullptr;
	}

	clsClient Find(const std::string& AccNumber) const
	{
		clsClient* Client = _Find(AccNumber);

		return Client ? *Client : clsClient::EmptyObject();
	}

	clsClient Find(const std::string& AccNumber, const std::string& PinCode) const
	{
		clsClient* Client = _Find(AccNumber, PinCode);

		return Client ? *Client : clsClient::EmptyObject();
	}

	enSaveResult SaveClient(const clsClient& Client)
	{
		if (Client.IsEmpty())
		{
			return clsManager::enSaveResult::eFailedEmptyObject;
		}
		if (Client._Mode != clsClient::enMode::_UpdateMode 
			&& IsClientExist(Client.AccNumber()))
		{
			return clsManager::enSaveResult::eFailedExistingAccNumber;
		}

		switch (Client._Mode)
		{
		case clsClient::enMode::_AddNewMode:
			_AddClient(new clsClient(Client));
			break;

		case clsClient::enMode::_UpdateMode:
			clsClient* ptrClient = _Find(Client.AccNumber());
			if(ptrClient)
				_UpdateClient(ptrClient, Client);
			else
				return clsManager::enSaveResult::eFailedEmptyObject;
			break;
		}

		Save();

		return clsManager::enSaveResult::eSucceeded;
	}

	bool Delete(const std::string& AccNumber)
	{
		clsClient* Client = _Find(AccNumber);

		if (Client)
		{
			_DeleteClient(Client);
			Save();
			return true;
		}
		else
		{
			return false;
		}
	}

	clsClient AddNewObject(const std::string& AccNumber)
	{
		return clsClient("", "", "", "", AccNumber, "", 0.0, clsPerson::enMode::_AddNewMode);
	}

	double GetTotalBalance() const
	{
		return TotalBalance;
	}

	void DepositTo(double Amount, const std::string& AccNumber)
	{
		clsClient* Client = _Find(AccNumber);
		if (Client)
		{
			_Deposit(Amount, Client);
			Save();
		}
		else
		{
			return;
		}
	}

	bool WithdrawFrom(double Amount, const std::string& AccNumber)
	{
		clsClient* Client = _Find(AccNumber);
		bool IsSuccessful = Client ? _Withdraw(Amount, Client) : false;

		if (IsSuccessful)
		{
			Save();
			return true;
		}
		else
		{
			return false;
		}
	}

};
