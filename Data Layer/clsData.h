#pragma once

#include "clsClientsData.h"
#include "clsUsersData.h"
#include "clsLoginData.h"

//This is the class used to handle saving and loading data from files, it is a wrapper class for clsClientsData and clsUsersData classes
class clsData
{
public:
	static std::vector<clsClient*> LoadClients()
	{
		return clsClientsData::LoadDataFromFile(clsClientsData::_ClientsFileName);
	}

	static void Save(const std::vector<clsClient*>& vClients)
	{
		clsClientsData::SaveDataToFile(clsClientsData::_ClientsFileName, vClients);
	}
	
	static std::vector<clsUser*> LoadUsers()
	{
		return clsUsersData::LoadDataFromFile(clsUsersData::_UsersFileName);
	}
	
	static void Save(const std::vector<clsUser*>& vUsers)
	{
		clsUsersData::SaveDataToFile(clsUsersData::_UsersFileName, vUsers);
	}

	static std::vector<clsLoginInfo*> LoadLoginLogs()
	{
		return clsLoginData::LoadDataFromFile(clsLoginData::_LoginLogFile);
	}

	static void SaveLog(const std::string& LoginLogs)
	{
		clsLoginData::SaveLineToFile(clsLoginData::_LoginLogFile, LoginLogs);
	}
};
