#pragma once

#include "clsClientScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsWithdrawScreen :
    protected clsClientScreen
{
public:
    static void Withdraw()
    {
        _DrawScreenHeader("Withdraw Screen");
        std::string AccNumber = clsInputValidate::Read<std::string>("Please Enter a Valid Account Number : ");

        while (!Clients.IsClientExist(AccNumber))
        {
            AccNumber = clsInputValidate::Read <std::string>("Account Number does not exist, enter another one: ");
        }

        clsClient Client = Clients.Find(AccNumber);
        _PrintClient(Client);

        double Amount = clsInputValidate::ReadPositive<double>("Please Enter the Amount to Withdraw: ");
        if (clsInputValidate::ReadBool("Are you sure you want to withdraw " + std::to_string(Amount) + " from account " + AccNumber + "?"))
        {
            if (Clients.WithdrawFrom(Amount, AccNumber))
            {
                std::cout << "Withdrawal Successful! New Balance: " << Client.Balance() - Amount << std::endl;
            }
            else
            {
                std::cout << "Withdrawal Failed! Insufficient Funds." << std::endl;
            }
        }
        else
        {
            std::cout << "Withdrawal Cancelled." << std::endl;
        }
    }
};

