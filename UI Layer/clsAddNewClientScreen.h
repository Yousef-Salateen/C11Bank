#pragma once

#include "clsClientScreen.h"
#include "../Middle Layer/clsClient.h"
#include "../Global.h"
#include "../External Libs/clsInputValidate.h"
#include <iostream>

class clsAddNewClientScreen :
    protected clsClientScreen
{
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

