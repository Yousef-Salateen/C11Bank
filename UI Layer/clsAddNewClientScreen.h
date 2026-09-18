#pragma once

#include "clsScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsAddNewClientScreen :
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

    static void _ReadClient(clsClient& Client)
    {
        Client.setFirstName(clsInputValidate::Read<std::string>("First Name: "));
        Client.setLastName(clsInputValidate::Read<std::string>("Last Name: "));
        Client.setEmail(clsInputValidate::Read<std::string>("Email: "));
        Client.setPhone(clsInputValidate::Read<std::string>("Phone: "));
        Client.setPinCode(clsInputValidate::Read<std::string>("Pin Code: "));
        Client.setBalance(clsInputValidate::Read<double>("Balance: "));
    }

public:

    static void AddClient()
    {
        if (_AccessMessage(clsSession::CurrentUser.HasPermission(enPermissions::eAddNewClient)))
            return;

        _DrawScreenHeader("Add New Client Screen");
        std::string AccNumber = clsInputValidate::Read<std::string>("Please Enter a Valid Account Number : ");

        while (Clients.IsClientExist(AccNumber))
        {
            AccNumber = clsInputValidate::Read <std::string>("Account Number already exists, enter another one: ");
        }

        clsClient Client = Clients.AddNewObject(AccNumber);

        _ReadClient(Client);

        clsManager<clsClient>::enSaveResult SaveResult;
        SaveResult = Clients.SaveClient(Client);

        switch (SaveResult)
        {
        default: case clsManager<clsClient>::enSaveResult::eFailedEmptyObject:
            std::cout << "Failed the save, object is empty" << std::endl;
            break;

        case clsManager<clsClient>::enSaveResult::eFailedExistingAccNumber:
            std::cout << "Failed the save, account number already exists" << std::endl;
            break;

        case clsManager<clsClient>::enSaveResult::eSucceeded:
            std::cout << "\nAdded Successfully\n";
            _PrintClient(Client);
            break;
        }
    }
};

