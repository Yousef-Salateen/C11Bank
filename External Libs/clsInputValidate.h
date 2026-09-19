#pragma once

#include <iostream>
#include <string>
#include <limits>

class clsInputValidate
{
public:
    static bool IsValidInput(const std::string& ErrorMsg)
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << ErrorMsg << std::endl;
            return false;
        }

        return true;
    }

    template<typename T>
    static T Read(const std::string& Msg, const std::string& ErrorMsg = "Invalid input! Try again.")
    {
        T var;

        do
        {
            std::cout << Msg;
            std::cin >> var;
        } while (!IsValidInput(ErrorMsg));

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return var;
    }

    template<typename T>
    static T ReadPositive(const std::string& Msg, const std::string& ErrorMsg = "Invalid input! Try again.")
    {
        T var;

        do
        {
            var = Read<T>(Msg, ErrorMsg);
        } while (var < 0);

        return var;
    }

    static std::string ReadLine(const std::string& Msg)
    {
        std::string str;

        std::cout << Msg;
        std::getline(std::cin >> std::ws, str);

        return str;
    }

    static bool ReadBool(const std::string& Msg)
    {
        char answer = Read<char>(Msg + " (y/n): ");

        return (answer == 'y' || answer == 'Y');
    }

    template <typename T>
    static bool IsBetween(const T& var, const T& start, const T& end)
    {
        return !(var > end || var < start);
    }

    template <typename T>
    static T ReadInRange(const std::string& Msg, const T& start, const T& end, const std::string& ErrorMsg = "Invalid input! Try again.", 
        const std::string& RangeError = "Input outside of range!")
    {
        T var;

        var = Read<T>(Msg, ErrorMsg);
        while (!IsBetween<T>(var, start, end))
        {
            std::cout << RangeError << "\n";
            var = Read<T>(Msg, ErrorMsg);
        }

        return  var;
    }
};