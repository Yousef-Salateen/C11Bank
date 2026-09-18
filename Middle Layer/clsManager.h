#pragma once

#include "../Data Layer/clsData.h"

template <typename clsClass>

class clsManager
{
protected:
	std::vector<clsClass*> _vItems;

	enum enSaveResult : char { eFailedEmptyObject = 0, eSucceeded, eFailedExistingAccNumber, eFailedExistingUsername };

	size_t _PtrIndex(clsClass* Obj)
	{
		for (size_t i = 0; i < _vItems.size(); i++)
		{
			if (_vItems[i] == Obj)
			{
				return i;
			}
		}

		return std::string::npos;
	}

public:

	clsManager(std::vector<clsClass*>(*Load)())
		: _vItems(Load())
	{

	}

	void Save() const
	{
		clsData::Save(_vItems);
	}

	clsClass Item(size_t index)
	{
		if (index >= 0 && index < _vItems.size())
			return *_vItems[index];
		return clsClass::EmptyObject();
	}

	size_t Amount()
	{
		return _vItems.size();
	}
};

