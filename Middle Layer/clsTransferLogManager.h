#pragma once

#include "clsManager.h"
#include "clsTransferInfo.h"

class clsTransferLogManager :
    public clsManager<clsTransferInfo>
{
public:
	clsTransferLogManager() : clsManager(clsData::LoadTransferLogs)
	{
	}

	~clsTransferLogManager()
	{
		for (clsTransferInfo* TransferInfo : _vItems)
		{
			delete TransferInfo;
		}
	}

	void AddNewLog(const clsTransferInfo& TransferInfo)
	{
		_vItems.emplace_back(new clsTransferInfo(TransferInfo));
		clsData::SaveTransfer(clsTransferData::ConvertObjectToLine(_vItems.back()));
	}
};

