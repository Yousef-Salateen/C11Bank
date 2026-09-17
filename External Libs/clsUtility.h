#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime> 
#include <utility>

class clsUtility
{
public:
    enum enNumType : char { integer, even, odd };

    static void SeedMyRand(void)
    {
        srand((unsigned)time(NULL));
    }

    static int RandomInteger(int start, int end)
    {
        return rand() % (end - start + 1) + start;
    }

    enum enCharType : char { eSmall, eCapital, eDigit, eSpecial, eMix };

    static char RandomCharacter(enCharType Type = enCharType::eMix)
    {
        if (Type == enCharType::eMix)
            Type = static_cast<enCharType>(RandomInteger(0, 2));
        switch (Type)
        {
        case enCharType::eSmall:
            return static_cast<char>(RandomInteger('a', 'z'));
        case enCharType::eCapital:
            return static_cast<char>(RandomInteger('A', 'Z'));
        case enCharType::eDigit:
            return static_cast<char>(RandomInteger('0', '9'));
        case enCharType::eSpecial:
            return static_cast<char>(RandomInteger(32, 47));
        }
    }

    static std::string RandomWord(short length, enCharType Type = enCharType::eMix)
    {
        std::string word(length, ' ');

        for (short i = 0; i < length; i++)
        {
            word[i] = RandomCharacter(Type);
        }

        return word;
    }

    static std::string RandomKey(enCharType Type = enCharType::eMix)
    {
        std::string key;

        key.append(RandomWord(4, Type) + '-');
        key.append(RandomWord(4, Type) + '-');
        key.append(RandomWord(4, Type) + '-');
        key.append(RandomWord(4, Type));

        return key;
    }

    static std::vector<int> VectorWithRandomNumbers(int From, int To, int size = 1)
    {
        std::vector<int> vInts(size);

        for (int i = 0; i < size; i++)
            vInts[i] = RandomInteger(From, To);

        return vInts;
    }

    static std::vector<std::string> VectorWithRandomWords(short length, int size = 1, enCharType Type = enCharType::eMix)
    {
        std::vector<std::string> vWords(size);

        for (int i = 0; i < size; i++)
            vWords[i] = RandomWord(length, Type);

        return vWords;
    }

    static std::vector<std::string> VectorWithRandomKeys(int size = 1, enCharType Type = enCharType::eMix)
    {
        std::vector<std::string> vKeys(size);

        for (int i = 0; i < size; i++)
            vKeys[i] = RandomKey(Type);

        return vKeys;
    }

    template<typename T>
    static void Shuffle(std::vector<T>& range)
    {
        size_t size = range.size();
        for (int i = 0; i < size; i++)
        {
            std::swap(range[0], range[RandomInteger(i, size - 1)]);
        }
    }

    static std::string Tabs(short NumberOfTabs)
    {
        std::string t(NumberOfTabs, ' ');

        for (int i = 0; i < NumberOfTabs; i++)
        {
            t[i] = '\t';
        }
        return t;

    }

    static std::string EncryptText(std::string Text, short EncryptionKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = Text[i] + EncryptionKey;
        }

        return Text;

    }

    static std::string DecryptText(std::string Text, short EncryptionKey)
    {

        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = Text[i] - EncryptionKey;
        }

        return Text;

    }

    static int RandomEvenNum(int start, int end)
    {
        int RandomNum = RandomInteger(start + 1, end);

        return RandomNum & ~1;
    }

    static int RandomOddNum(int start, int end)
    {
        int RandomNum = RandomInteger(start, end - 1);

        return RandomNum | 1;
    }

    static int RandomNumber(int start, int end, enNumType type = enNumType::integer)
    {
        switch (type)
        {
        case enNumType::even:
            return RandomEvenNum(start, end);
        case enNumType::odd:
            return RandomOddNum(start, end);
        case enNumType::integer: default:
            return RandomInteger(start, end);
        }
    }

    static bool CoinFlip()
    {
        return static_cast<bool>(RandomInteger(0, 1));
    }

    static std::string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            std::string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            std::string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }
};