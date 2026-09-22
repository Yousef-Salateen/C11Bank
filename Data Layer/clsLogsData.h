#pragma once

#include "../External Libs/clsFiles.h"

class clsLogsData
{
	inline static const std::string _LoginLogsFile = "LoginLogs.txt";
	inline static const std::string _Seperator = "#//#";
public:

	static std::string ConvertVectorToLogLine(const std::vector<std::string>& vLogLine)
	{
		std::string LogLine;

		for (const std::string& word: vLogLine)
		{
			LogLine.append(word + _Seperator);
		}

		return LogLine.substr(0, LogLine.length() - _Seperator.length());
	}

	static void AddLogToFile(const std::string& FileName, const std::vector<std::string>& vLogLine)
	{
		std::fstream File(FileName, std::ios::out | std::ios::app);

		clsFiles::AddLineToFile(File, ConvertVectorToLogLine(vLogLine));

		File.close();
	}

	friend class clsData;
};

