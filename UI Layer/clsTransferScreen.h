#pragma once

#include "clsClientScreen.h"
#include "../Global.h"

class clsTransferScreen :
    protected clsClientScreen
{
public:
    static void Transfer()
    {
        _DrawScreenHeader("Withdraw Screen");

        std::string AccNumber = clsInputValidate::Read<std::string>("Please Enter a Valid Account Number To Transfer From: ");
        while (!Clients.IsClientExist(AccNumber))
        {
            AccNumber = clsInputValidate::Read <std::string>("Account Number does not exist, enter another one: ");
        }

        clsClient FromClient = Clients.Find(AccNumber);
        _PrintClient(FromClient, enDisplayInfo::eBalance);

        AccNumber = clsInputValidate::Read<std::string>("Please Enter a Valid Account Number To Transfer To: ");
        while (!Clients.IsClientExist(AccNumber) || AccNumber == FromClient.AccNumber())
        {
            AccNumber = clsInputValidate::Read <std::string>("Account Number does not exist/same accout as previous, enter another one: ");
        }

        clsClient ToClient = Clients.Find(AccNumber);
        _PrintClient(ToClient, enDisplayInfo::eBalance);

        double Amount = clsInputValidate::ReadPositive<double>("Please Enter the Amount to Transfer: ");
        if (clsInputValidate::ReadBool("Are you sure you want to transfer " + std::to_string(Amount) + "?"))
        {
            if (Clients.WithdrawFrom(Amount, FromClient.AccNumber()))
            {
                Clients.DepositTo(Amount, ToClient.AccNumber());
                std::cout << "Transfer Successful!" << std::endl;
                TransferLogs.AddNewLog(clsTransferInfo(clsDate::GetSystemDateTimeString(), FromClient.AccNumber(), ToClient.AccNumber(), 
                    Amount, FromClient.Balance() - Amount, ToClient.Balance() + Amount, clsSession::CurrentUser.Username()));

                _PrintClient(Clients.Find(FromClient.AccNumber()), enDisplayInfo::eBalance);
                _PrintClient(Clients.Find(ToClient.AccNumber()), enDisplayInfo::eBalance);
            }
            else
            {
                std::cout << "Transfer Failed! Insufficient Funds." << std::endl;
            }
        }
        else
        {
            std::cout << "Transfer Cancelled." << std::endl;
        }
    }
};

