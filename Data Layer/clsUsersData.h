#pragma once

#include "../External Libs/clsFiles.h"
#include "../Middle Layer/clsUser.h"
#include <fstream>
#include <vector>

//This class responsible for loading and saving users data to and from a file
//This class is irresponsible for what happens to the data after it is loaded from the file, and what happens to the data before it is saved to the file
//After data is loaded from the file, it is the responsibility of the caller to manage the data
//and before saving the data to the file, it is the responsibility of the caller to prepare the data for saving
class clsUsersData
{
	inline static const std::string _UsersFileName = "Users.txt";
	inline static const std::string _Seperator = "#//#";

	enum enInfoPos : char { _FirstName = 0, _LastName, _Email, _Phone, _Username, _Password, _Permissions };
public:

	static clsUser ConvertLineToUser(const std::string& Line)
	{
		std::vector<std::string> vUserData = clsFiles::SeperateLineData(Line, _Seperator);

		if (vUserData.empty())
		{
			return clsUser::_EmptyObject();
		}

		return clsUser(vUserData.at(enInfoPos::_FirstName), vUserData.at(enInfoPos::_LastName), vUserData.at(enInfoPos::_Email),
			vUserData.at(enInfoPos::_Phone), vUserData.at(enInfoPos::_Username), vUserData.at(enInfoPos::_Password),
			stoi(vUserData.at(enInfoPos::_Permissions)), clsUser::enMode::_UpdateMode);
	}

	static std::vector<clsUser*> LoadUsersDataFromFile(const std::string& FileName)
	{
		std::vector<clsUser*> vUsers;
		std::fstream File(FileName, std::ios::in);

		std::vector<std::string> vData = clsFiles::LoadDataFromFile(File);
		vUsers.reserve(vData.size());

		for (const std::string& Line : vData)
		{
			vUsers.emplace_back(new clsUser(ConvertLineToUser(Line)));
		}

		File.close();

		return vUsers;
	}

	static std::string ConvertUserToLine(const clsUser* User)
	{
		return User->FirstName() + _Seperator + User->LastName() + _Seperator + User->Email() + _Seperator + User->Phone() + _Seperator +
			User->Username() + _Seperator + User->Password() + _Seperator + std::to_string(User->Permissions());
	}

	static void SaveUsersDataToFile(const std::string& FileName, const std::vector<clsUser*>& vUsers)
	{
		std::fstream File(FileName, std::ios::out);
		std::vector <std::string> vData;
		vData.reserve(vUsers.size());

		for (const clsUser* User : vUsers)
		{
			if (User && !User->MarkedForDelete())
			{
				vData.emplace_back(ConvertUserToLine(User));
			}
		}

		clsFiles::SaveDataToFile(File, vData);
		File.close();
	}

	friend class clsData;
};
