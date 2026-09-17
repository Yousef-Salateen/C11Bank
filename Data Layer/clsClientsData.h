#pragma once

#include "../External Libs/clsFiles.h"
#include "../Middle Layer/clsClient.h"
#include <fstream>
#include <vector>

//This class responsible for loading and saving clients data to and from a file
//This class is irresponsible for what happens to the data after it is loaded from the file, and what happens to the data before it is saved to the file
//After data is loaded from the file, it is the responsibility of the caller to manage the data
//and before saving the data to the file, it is the responsibility of the caller to prepare the data for saving
class clsClientsData
{
private:
	inline static const std::string _ClientsFileName = "Clients.txt";
	inline static const std::string _Seperator = "#//#";

	enum enInfoPos : char { _FirstName = 0, _LastName, _Email, _Phone, _AccNumber, _PinCode, _Balance };
public:

	static clsClient ConvertLineToClient(const std::string& Line)
	{
		std::vector<std::string> vClientData = clsFiles::SeperateLineData(Line, _Seperator);

		if (vClientData.empty())
		{
			return clsClient::_EmptyObject();
		}

		return clsClient(vClientData.at(enInfoPos::_FirstName), vClientData.at(enInfoPos::_LastName), vClientData.at(enInfoPos::_Email),
			vClientData.at(enInfoPos::_Phone), vClientData.at(enInfoPos::_AccNumber), vClientData.at(enInfoPos::_PinCode),
			std::stod(vClientData.at(enInfoPos::_Balance)), clsClient::enMode::_UpdateMode);
	}

	static std::vector<clsClient*> LoadClientsDataFromFile(const std::string& FileName)
	{
		std::vector<clsClient*> vClients;
		std::fstream File(FileName, std::ios::in);

		std::vector<std::string> vData = clsFiles::LoadDataFromFile(File);
		vClients.reserve(vData.size());

		for (const std::string& Line : vData)
		{
				vClients.emplace_back(new clsClient(ConvertLineToClient(Line)));
		}

		File.close();

		return vClients;
	}

	static std::string ConvertClientToLine(const clsClient* Client)
	{
		return Client->FirstName() + _Seperator + Client->LastName() + _Seperator + Client->Email() + _Seperator + Client->Phone() + _Seperator +
			Client->AccNumber() + _Seperator + Client->PinCode() + _Seperator + std::to_string(Client->Balance());
	}

	static void SaveClientsDataToFile(const std::string& FileName, const std::vector<clsClient*>& vClients)
	{
		std::fstream File(FileName, std::ios::out);
		std::vector <std::string> vData;
		vData.reserve(vClients.size());

		for (const clsClient* Client : vClients)
		{
			if (Client && !Client->MarkedForDelete())
			{
				vData.emplace_back(ConvertClientToLine(Client));
			}
		}

		clsFiles::SaveDataToFile(File, vData);
		File.close();
	}
};
