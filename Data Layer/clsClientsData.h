#pragma once

#include "../External Libs/clsFiles.h"
#include "../Middle Layer/clsClient.h"
#include <fstream>
#include <vector>
#include "clsClassData.h"

//This class responsible for loading and saving clients data to and from a file
//This class is irresponsible for what happens to the data after it is loaded from the file, and what happens to the data before it is saved to the file
//After data is loaded from the file, it is the responsibility of the caller to manage the data
//and before saving the data to the file, it is the responsibility of the caller to prepare the data for saving
class clsClientsData
	: public clsClassData<clsClientsData, clsClient>
{
private:
	inline static const std::string _ClientsFileName = "Clients.txt";
	inline static const std::string _Seperator = "#//#";

	enum enInfoPos : char { _FirstName = 0, _LastName, _Email, _Phone, _AccNumber, _PinCode, _Balance };
public:

	static clsClient ConvertLineToObject(const std::string& Line)
	{
		std::vector<std::string> vClientData = clsFiles::SeperateLineData(Line, _Seperator);

		if (vClientData.empty())
		{
			return clsClient::EmptyObject();
		}

		return clsClient(vClientData.at(enInfoPos::_FirstName), vClientData.at(enInfoPos::_LastName), vClientData.at(enInfoPos::_Email),
			vClientData.at(enInfoPos::_Phone), vClientData.at(enInfoPos::_AccNumber), vClientData.at(enInfoPos::_PinCode),
			std::stod(vClientData.at(enInfoPos::_Balance)), clsClient::enMode::_UpdateMode);
	}

	static std::string ConvertObjectToLine(const clsClient* Object)
	{
		return Object->FirstName() + _Seperator + Object->LastName() + _Seperator + Object->Email() + _Seperator + Object->Phone() + _Seperator +
			Object->AccNumber() + _Seperator + Object->PinCode() + _Seperator + std::to_string(Object->Balance());
	}

	friend class clsData;
};
