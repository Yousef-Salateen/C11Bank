#pragma once

#include "clsClientsData.h"
#include "clsUsersData.h"

//This is the class used to handle saving and loading data from files, it is a wrapper class for clsClientsData and clsUsersData classes
class clsData
{
public:
	static std::vector<clsClient*> LoadClients()
	{
		return clsClientsData::LoadClientsDataFromFile(clsClientsData::_ClientsFileName);
	}

	static void Save(const std::vector<clsClient*>& vClients)
	{
		clsClientsData::SaveClientsDataToFile(clsClientsData::_ClientsFileName, vClients);
	}
	
	static std::vector<clsUser*> LoadUsers()
	{
		return clsUsersData::LoadUsersDataFromFile(clsUsersData::_UsersFileName);
	}
	
	static void Save(const std::vector<clsUser*>& vUsers)
	{
		clsUsersData::SaveUsersDataToFile(clsUsersData::_UsersFileName, vUsers);
	}
};
