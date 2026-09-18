#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>"

class clsWithdrawScreen :
    protected clsScreen
{
private:
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

        double Amount = clsInputValidate::Read<double>("Please Enter the Amount to Withdraw: ");
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

