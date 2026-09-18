#pragma once
#include "clsUserScreen.h"
#include "../External Libs/clsInputValidate.h"
#include "../Middle Layer/clsUser.h"
#include "../Global.h"

class clsAddNewUserScreen :
    protected clsUserScreen
{
public:

    static void AddUser()
    {
        _DrawScreenHeader("Add New User Screen");
        std::string Username = clsInputValidate::Read<std::string>("Please Enter a Valid Username : ");

        while (Users.IsUserExist(Username))
        {
            Username = clsInputValidate::Read<std::string>("Username already exists, enter another one: ");
        }

        clsUser User = Users.AddNewObject(Username);

        _ReadUser(User);

        clsManager<clsUser>::enSaveResult SaveResult;
        SaveResult = Users.SaveUser(User);

        switch (SaveResult)
        {
        default: case clsManager<clsUser>::enSaveResult::eFailedEmptyObject:
            std::cout << "Failed the save, object is empty" << std::endl;
            break;

        case clsManager<clsUser>::enSaveResult::eFailedExistingUsername:
            std::cout << "Failed the save, username already exists" << std::endl;
            break;

        case clsManager<clsUser>::enSaveResult::eSucceeded:
            std::cout << "\nAdded Successfully\n";
            _PrintUser(User);
            break;
        }
    }
};

