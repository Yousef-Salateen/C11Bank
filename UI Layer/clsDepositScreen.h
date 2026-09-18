#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsDepositScreen
	: protected clsScreen
{
    static void _PrintClient(const clsClient& Client)
    {
        std::cout << "\nClient Card:";
        std::cout << "\n_________________";
        std::cout << "\nFirst Name: " << Client.FirstName();
        std::cout << "\nLast Name: " << Client.LastName();
        std::cout << "\nFull Name: " << Client.FullName();
        std::cout << "\nEmail: " << Client.Email();
        std::cout << "\nPhone: " << Client.Phone();
        std::cout << "\nAccount Number: " << Client.AccNumber();
        std::cout << "\nPin Code: " << Client.PinCode();
        std::cout << "\nBalance: " << Client.Balance();
        std::cout << "\n_________________" << std::endl;
    }

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

        double Amount = clsInputValidate::Read<double>("Please Enter the Amount to Deposit: ");
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