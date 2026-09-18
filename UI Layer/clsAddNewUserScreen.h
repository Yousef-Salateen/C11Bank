#pragma once
#include "clsScreen.h"
#include "../External Libs/clsInputValidate.h"
#include "../Middle Layer/clsUser.h"
#include "../Global.h"

class clsAddNewUserScreen :
    protected clsScreen
{
private:
    static void _PrintUser(const clsUser& User)
    {
        std::cout << "\nUser Card:";
        std::cout << "\n_________________";
        std::cout << "\nFirst Name: " << User.FirstName();
        std::cout << "\nLast Name: " << User.LastName();
        std::cout << "\nFull Name: " << User.FullName();
        std::cout << "\nEmail: " << User.Email();
        std::cout << "\nPhone: " << User.Phone();
        std::cout << "\nUsername: " << User.Username();
        std::cout << "\nPassword: " << User.Password();
        std::cout << "\nPermissions: " << User.Permissions();
        std::cout << "\n_________________" << std::endl;
    }

    static void _ReadUser(clsUser& User)
    {
        User.setFirstName(clsInputValidate::Read<std::string>("First Name: "));
        User.setLastName(clsInputValidate::Read<std::string>("Last Name: "));
        User.setEmail(clsInputValidate::Read<std::string>("Email: "));
        User.setPhone(clsInputValidate::Read<std::string>("Phone: "));
        User.setPassword(clsInputValidate::Read<std::string>("Password: "));
        User.setPermissions(_ReadPermissions());
    }

    static int _ReadPermissions()
    {
        int Permissions = 0;

        if (clsInputValidate::ReadBool("Do you want to give all permissions to this user? "))
        {
            Permissions = enPermissions::eAll;
            return Permissions;
        }
        if (clsInputValidate::ReadBool("Do you want to give List Clients permission? "))
        {
            Permissions |= enPermissions::eListClients;
        }
        if (clsInputValidate::ReadBool("Do you want to give Add New Client permission?"))
        {
            Permissions |= enPermissions::eAddNewClient;
        }
        if (clsInputValidate::ReadBool("Do you want to give Delete Client permission?"))
        {
            Permissions |= enPermissions::eDeleteClient;
        }
        if (clsInputValidate::ReadBool("Do you want to give Update Client permission?"))
        {
            Permissions |= enPermissions::eUpdateClient;
        }
        if (clsInputValidate::ReadBool("Do you want to give Find Client permission?"))
        {
            Permissions |= enPermissions::eFindClient;
        }
        if (clsInputValidate::ReadBool("Do you want to give Transactions permission?"))
        {
            Permissions |= enPermissions::eTransactions;
        }
        if (clsInputValidate::ReadBool("Do you want to give Manage Users permission?"))
        {
            Permissions |= enPermissions::eManageUsers;
        }

        return Permissions;
    }

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

