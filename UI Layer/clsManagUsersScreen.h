#pragma once

#include "clsScreen.h"
#include <iostream>
#include <iomanip>
#include "../External Libs/clsInputValidate.h"
#include "../Middle Layer/clsSession.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserscreen.h"
#include "clsDeleteUserScreen.h"

class clsManagUsersScreen :
    protected clsScreen
{
private:
	enum enManageUsersOptions
	{
		eShowUsersList = 1,
		eAddNewUser,
		eDeleteUser,
		eUpdateUser,
		eFindUser,
		eExit
	};

	static enManageUsersOptions _ReadManageUsersOption()
	{
		return static_cast<enManageUsersOptions>(clsInputValidate::ReadInRange<int>("\nChoose what do you want to do? [1 to 6] : ",
			1, enManageUsersOptions::eExit));
	}

	static void _PerformManageUsersOption(enManageUsersOptions ManageUsersOption)
	{
		switch (ManageUsersOption)
		{
		case enManageUsersOptions::eShowUsersList:
			_ShowUsersListScreen();
			_WaitForEnter();
			break;
		case enManageUsersOptions::eAddNewUser:
			_ShowAddNewUserScreen();
			_WaitForEnter();
			break;
		case enManageUsersOptions::eDeleteUser:
			_ShowDeleteUserScreen();
			_WaitForEnter();
			break;
		case enManageUsersOptions::eUpdateUser:
			_ShowUpdateUserScreen();
			_WaitForEnter();
			break;
		case enManageUsersOptions::eFindUser:
			_ShowFindUserScreen();
			_WaitForEnter();
			break;
		case enManageUsersOptions::eExit:
			_ShowExitScreen();
			_WaitForEnter();
			break;
		default:
			std::cout << "Invalid option! Please try again.\n";
			break;
		}
	}

	static void _ShowUsersListScreen()
	{
		_ClearScreen();
		clsListUsersScreen::PrintUserList();
	}

	static void _ShowAddNewUserScreen()
	{
		_ClearScreen();
		clsAddNewUserScreen::AddUser();
	}

	static void _ShowDeleteUserScreen()
	{
		_ClearScreen();
		clsDeleteUserScreen::DeleteUser();
	}

	static void _ShowUpdateUserScreen()
	{
		_ClearScreen();
		//clsUpdateUserScreen::UpdateUser();
	}

	static void _ShowFindUserScreen()
	{
		_ClearScreen();
		//clsFindUserScreen::FindUser();
	}

	static void _ShowExitScreen()
	{
		_ClearScreen();
		std::cout << "Exiting the menu.\n";
	}

public:
	static void ShowManageUsersScreen()
	{
		if (_AccessMessage(clsSession::CurrentUser.HasPermission(enPermissions::eManageUsers)))
		{
			_WaitForEnter();
			return;
		}

		enManageUsersOptions ManageUsersOption;
		do
		{
			_ClearScreen();
			_DrawScreenHeader("MANAGE USERS SCREEN");
			std::cout << std::setw(37) << std::left << "" << "[1] Show Users List.\n";
			std::cout << std::setw(37) << std::left << "" << "[2] Add New User.\n";
			std::cout << std::setw(37) << std::left << "" << "[3] Delete User.\n";
			std::cout << std::setw(37) << std::left << "" << "[4] Update User Info.\n";
			std::cout << std::setw(37) << std::left << "" << "[5] Find User.\n";
			std::cout << std::setw(37) << std::left << "" << "[6] Exit.\n";

			ManageUsersOption = _ReadManageUsersOption();
			_PerformManageUsersOption(ManageUsersOption);
		} while (ManageUsersOption != enManageUsersOptions::eExit);

	}
};

