#pragma once

#include "clsClientScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsDepositScreen
	: protected clsClientScreen
{
public:
    static void Deposit()
    {
        _DrawScreenHeader("Deposit Screen");
        std::string AccNumber = clsInputValidate::Read<std::string>("Please Enter a Valid Account Number : ");

        while (!Clients.IsClientExist(AccNumber))
        {
            AccNumber = clsInputValidate::Read <std::string>("Account Number does not exist, enter another one: ");
        }

        clsClient Client = Clients.Find(AccNumber);
        _PrintClient(Client);

        double Amount = clsInputValidate::ReadPositive<double>("Please Enter the Amount to Deposit: ");
        if (clsInputValidate::ReadBool("Are you sure you want to deposit " + std::to_string(Amount) + " to account " + AccNumber + "?"))
        {
            Clients.DepositTo(Amount, AccNumber);
            std::cout << "Deposit Successful! New Balance: " << Client.Balance() + Amount << std::endl;
        }
        else
        {
            std::cout << "Deposit Cancelled." << std::endl;
        }
    }
};