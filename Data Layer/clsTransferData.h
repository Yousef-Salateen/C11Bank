#pragma once

#include "clsClassData.h"
#include "../Middle Layer/clsTransferInfo.h"

class clsTransferData :
	public clsClassData<clsTransferData, clsTransferInfo>
{
private:
	inline static const std::string _TransferLogFile = "TransferLogs.txt";
	inline static const std::string _Seperator = "#//#";

public:
	static clsTransferInfo ConvertLineToObject(const std::string& Line)
	{
		std::vector<std::string> vTransferData = clsFiles::SeperateLineData(Line, _Seperator);

		if (vTransferData.empty())
		{
			return clsTransferInfo::EmptyObject();
		}

		return clsTransferInfo(vTransferData.at(0), vTransferData.at(1), vTransferData.at(2), std::stod(vTransferData.at(3)),
			std::stod(vTransferData.at(4)), std::stod(vTransferData.at(5)), vTransferData.at(6));
	}

	static std::string ConvertObjectToLine(const clsTransferInfo* Object)
	{
		return Object->DateLine() + _Seperator + Object->FromAcc() + _Seperator + Object->ToAcc() + _Seperator + std::to_string(Object->TransferAmount()) + _Seperator
			+ std::to_string(Object->NewFromAccBalance()) + _Seperator + std::to_string(Object->NewToAccBalance()) + _Seperator + Object->Username();
	}

	friend class clsData;
};

