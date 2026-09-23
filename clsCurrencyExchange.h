#pragma once

#include "External Libs/clsFiles.h"
#include <iostream>
#include <vector>
#include "External Libs/clsString.h"

class clsCurrencyExchange
{
private:
	enum enMode { _eEmptyMode, _eUpdateMode };
	enMode _Mode;

	std::string _Country;
	std::string _CurrencyCode;
	std::string _CurrencyName;
	double _Rate = 0.0;

	static clsCurrencyExchange _ConvertLineToRecord(const std::string& Line, const std::string& Seperator = "#//#")
	{
		std::vector<std::string> vInfo = clsFiles::SeperateLineData(Line, Seperator);
		return clsCurrencyExchange(vInfo[0], vInfo[1], vInfo[2], std::stod(vInfo[3]), _eUpdateMode);
	}

	static std::vector<clsCurrencyExchange> _LoadDataFromFile()
	{
		std::fstream File("Currencies.txt", std::ios::in);
		std::vector<std::string> vInfo = clsFiles::LoadDataFromFile(File);
		File.close();

		std::vector<clsCurrencyExchange> vObjects;
		vObjects.reserve(vInfo.size());

		for (const std::string& ObjInfo : vInfo)
		{
			vObjects.emplace_back(_ConvertLineToRecord(ObjInfo));
		}

		return vObjects;
	}

	static std::string _ConvertObjectToLine(const clsCurrencyExchange& Obj, const std::string& Seperator = "#//#")
	{
		return Obj.Country() + Seperator + Obj.CurrencyCode() + Seperator + Obj.CurrencyName() + Seperator +
			std::to_string(Obj.Rate());
	}

	static void _SaveDataToFile(const std::vector<clsCurrencyExchange>& vObjects)
	{
		std::fstream File("Currencies.txt", std::ios::out);
		std::vector<std::string> vInfo;
		vInfo.reserve(vObjects.size());


		for (const clsCurrencyExchange& Obj : vObjects)
		{
			vInfo.emplace_back(_ConvertObjectToLine(Obj));
		}

		clsFiles::SaveDataToFile(File, vInfo);
		File.close();
	}

	void _Update()
	{
		std::vector<clsCurrencyExchange> vObjects = _LoadDataFromFile();

		for (clsCurrencyExchange& Obj : vObjects)
		{
			if (Obj.CurrencyCode() == this->CurrencyCode())
			{
				Obj = *this;
				break;
			}
		}

		_SaveDataToFile(vObjects);
	}

	static clsCurrencyExchange _EmptyObject()
	{
		return clsCurrencyExchange("", "", "", 0.0, enMode::_eEmptyMode);
	}

public:
	clsCurrencyExchange(const std::string& Country, const std::string& CurrencyCode, const std::string& CurrencyName, double Rate,
						enMode Mode) : 
		_Country(Country), _CurrencyCode(CurrencyCode), _CurrencyName(CurrencyName), _Rate(Rate), _Mode(Mode)
	{

	}

	std::string Country() const
	{
		return _Country;
	}

	std::string CurrencyCode() const
	{
		return _CurrencyCode;
	}

	std::string CurrencyName() const
	{
		return _CurrencyName;
	}

	double Rate() const
	{
		return _Rate;
	}

	void setRate(double Rate)
	{
		_Rate = Rate;
		_Update();
	}

	static clsCurrencyExchange FindByCode(const std::string& CurrencyCode)
	{
		std::fstream File("Currencies.txt", std::ios::in);
		std::vector<std::string> vInfo = clsFiles::LoadDataFromFile(File);

		std::string Code = clsString::UpperAllLetters(CurrencyCode);
		for (const std::string& CurrencyInfo : vInfo)
		{
			clsCurrencyExchange Currency = _ConvertLineToRecord(CurrencyInfo);

			if (Currency.CurrencyCode() == Code)
			{
				return Currency;
			}
		}

		return _EmptyObject();
	}

	static clsCurrencyExchange FindByCountry(const std::string& CountryName)
	{
		std::fstream File("Currencies.txt", std::ios::in);
		std::vector<std::string> vInfo = clsFiles::LoadDataFromFile(File);

		std::string Country = clsString::UpperAllLetters(CountryName);
		for (const std::string& CurrencyInfo : vInfo)
		{
			clsCurrencyExchange Currency = _ConvertLineToRecord(CurrencyInfo);

			if (clsString::UpperAllLetters(Currency.Country()) == Country)
			{
				return Currency;
			}
		}

		return _EmptyObject();
	}

	bool IsEmpty()
	{
		return _Mode == enMode::_eEmptyMode;
	}

	static bool IsCurrencyExists(const std::string& CurrencyCode)
	{
		clsCurrencyExchange Currency = FindByCode(CurrencyCode);
		return !Currency.IsEmpty();
	}

	static std::vector<clsCurrencyExchange> GetCurrencyList()
	{
		return _LoadDataFromFile();
	}

	double ConvertToOtherCurrency(double Amount, const clsCurrencyExchange& Currency)
	{
		double USDAmount = Amount / this->Rate();

		if(Currency.CurrencyCode() == "USD")
			return USDAmount;
		else
		{
			double CalculatedAmount = USDAmount * Currency.Rate();
			return CalculatedAmount;
		}
	}
};

