#pragma once
#include <iostream>
#include <cctype>
#include <vector>
#include <string>

class clsString
{

private:
    std::string _Value;

public:

    clsString(const std::string& Value)
    {
        _Value = Value;
    }

    clsString()
    {
        _Value = "";
    }

    void setString(const std::string& Value)
    {
        _Value = Value;
    }

    std::string String()
    {
        return _Value;
    }

    static void PrintFirstLetters(const std::string& str)
    {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && IsFirstLetter)
            {
                std::cout << str[i] << std::endl;
            }

            IsFirstLetter = str[i] == ' ' ? true : false;
        }
    }

    void PrintFirstLetters()
    {
        PrintFirstLetters(_Value);
    }

    static std::string UpperFirstLetters(std::string str)
    {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && IsFirstLetter)
            {
                str[i] = toupper(str[i]);
            }

            IsFirstLetter = str[i] == ' ' ? true : false;
        }

        return str;
    }

    void UpperFirstLetters()
    {
         setString(UpperFirstLetters(_Value));
    }

    static std::string LowerFirstLetters(std::string str)
    {
        bool IsFirstLetter = true;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && IsFirstLetter)
            {
                str[i] = tolower(str[i]);
            }

            IsFirstLetter = str[i] == ' ' ? true : false;
        }

        return str;
    }
    
    void LowerFirstLetters()
    {
        setString(LowerFirstLetters(_Value));
    }

    static std::string UpperAllLetters(std::string str)
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            str[i] = toupper(str[i]);
        }

        return str;
    }
    
    void UpperAllLetters()
    {
        setString(UpperAllLetters(_Value));
    }

    static std::string LowerAllLetters(std::string str)
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        return str;
    }
    
    void LowerAllLetters()
    {
        setString(LowerAllLetters(_Value));
    }

    static char InvertLetterCase(char letter)
    {
        return isupper(letter) ? tolower(letter) : toupper(letter);
    }

    static std::string InvertCase(std::string str)
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            str[i] = InvertLetterCase(str[i]);
        }

        return str;
    }
    
    void InvertCase()
    {
        setString(InvertCase(_Value));
    }

    static size_t CapitalLettersCount(const std::string& str)
    {
        size_t count = 0;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (isupper(str[i]))
            {
                count++;
            }
        }

        return count;
    }

    size_t CapitalLettersCount()
    {
        return CapitalLettersCount(_Value);
    }

    static size_t SmallLettersCount(const std::string& str)
    {
        size_t count = 0;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (islower(str[i]))
            {
                count++;
            }
        }

        return count;
    }

    size_t SmallLettersCount()
    {
        return SmallLettersCount(_Value);
    }

    static size_t LetterCount(const std::string& str, char letter, bool MatchCase = true)
    {
        size_t count = 0;
        const char LetterOtherCase = InvertLetterCase(letter);

        if (MatchCase)
        {
            for (char c : str)
            {
                if (c == letter)
                    count++;
            }
        }
        else
        {
            for (char c : str)
            {
                if (c == letter || c == LetterOtherCase)
                    count++;
            }
        }

        return count;
    }

    size_t LetterCount(char letter, bool MatchCase = true)
    {
        return LetterCount(_Value, letter, MatchCase);
    }

    static bool IsVowel(char letter)
    {
        letter = tolower(letter);

        return (letter == 'a') || (letter == 'e') || (letter == 'u') ||
            (letter == 'i') || (letter == 'o');
    }

    enum enToBeCount { Lower = 0, Upper = 1, Vowel = 2, All = 4 };

    static size_t CountLetters(const std::string& str, enToBeCount ToBeCount = enToBeCount::All)
    {
        if (ToBeCount == enToBeCount::All)
        {
            return str.length();
        }

        size_t count = 0;
        switch (ToBeCount)
        {
        case enToBeCount::Upper:
        {
            for (char c : str)
            {
                if (isupper(c))
                    count++;
            }
            break;
        }
        case enToBeCount::Lower:
        {
            for (char c : str)
            {
                if (islower(c))
                    count++;
            }
            break;
        }
        case enToBeCount::Vowel:
        {
            for (char c : str)
            {
                if (IsVowel(c))
                    count++;
            }
            break;
        }
        }
        return count;
    }

    size_t CountLetters(enToBeCount ToBeCount = enToBeCount::All)
    {
        return CountLetters(_Value, ToBeCount);
    }

    static size_t CountVowelInString(const std::string& str)
    {
        size_t count = 0;

        for (char c : str)
        {
            if (IsVowel(c))
                count++;
        }

        return count;
    }

    size_t CountVowelInString()
    {
        return CountVowelInString(_Value);
    }

    static void PrintVowelsInString(const std::string& str)
    {
        for (char c : str)
        {
            if (IsVowel(c))
                std::cout << c << '\t';
        }
    }

    void PrintVowelsInString()
    {
        PrintVowelsInString(_Value);
    }

    static std::string ExtractWord(const std::string& str, size_t start, const std::string& splitter = " ")
    {
        size_t index = str.find(splitter, start);
        size_t length = index == std::string::npos ? str.length() - start : index - start;

        return str.substr(start, length);
    }

    std::string ExtractWord(size_t start, const std::string& splitter = " ")
    {
        return ExtractWord(_Value, start, splitter);
    }

    static void PrintEachWord(const std::string& str)
    {
        std::string word = "";
        size_t counter = 0;

        while (counter < str.length())
        {
            if (str[counter] != ' ')
            {
                word = ExtractWord(str, counter);
                std::cout << word << std::endl;
                counter += word.length();
            }
            else
            {
                counter++;
            }
        }
    }

    void PrintEachWord()
    {
        PrintEachWord(_Value);
    }

    static size_t WordsCount(const std::string& str)
    {
        size_t count = 0;

        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                count++;

                while (i < str.length() && str[i] != ' ')
                {
                    i++;
                }
            }
        }

        return count;
    }

    size_t WordsCount()
    {
        return WordsCount(_Value);
    }

    static std::vector <std::string> Split(const std::string& str, const std::string& splitter)
    {
        std::vector <std::string> vWords;
        std::string word;
        size_t counter = 0;

        while (counter < str.length())
        {
            word = ExtractWord(str, counter, splitter);
            if (word != "")
                vWords.push_back(word);

            counter += word.length() + splitter.length();
        }

        return vWords;
    }

    std::vector <std::string> Split(const std::string& splitter = " ")
    {
        return Split(_Value, splitter);
    }

    static std::string TrimLeft(const std::string& str, const std::string& ToTrim)
    {
        if (ToTrim.empty()) return str;

        size_t pos;
        size_t counter = 0;

        while ((pos = str.find(ToTrim, counter)) != std::string::npos &&
            str.substr(counter, ToTrim.length()) == ToTrim)
        {
            counter += ToTrim.length();
        }

        return str.substr(counter, str.length() - counter);
    }
    
    void TrimLeft(const std::string& ToTrim)
    {
        setString(TrimLeft(_Value, ToTrim));
    }

    static std::string TrimRight(const std::string& str, const std::string& ToTrim)
    {
        if (ToTrim.empty()) return str;

        size_t pos;
        size_t counter = str.length() - ToTrim.length();

        while ((pos = str.find(ToTrim, counter)) != std::string::npos &&
            str.substr(counter, ToTrim.length()) == ToTrim)
        {
            counter -= ToTrim.length();
        }

        return str.substr(0, counter + ToTrim.length());
    }
    
    void TrimRight(const std::string& ToTrim)
    {
        setString(TrimRight(_Value, ToTrim));
    }

    static std::string TrimSpacesLeft(const std::string& str)
    {
        for (size_t i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                return str.substr(i, str.length() - i);
            }
        }

        return "";
    }
    
    void TrimSpacesLeft()
    {
        setString(TrimSpacesLeft(_Value));
    }

    static std::string TrimSpacesRight(const std::string& str)
    {
        for (int i = str.length() - 1; i >= 0; i--)
        {
            if (str[i] != ' ')
            {
                return str.substr(0, i + 1);
            }
        }

        return "";
    }
    
    void TrimSpacesRight()
    {
        setString(TrimSpacesRight(_Value));
    }

    static std::string Trim(const std::string& str, const std::string& ToTrim)
    {
        return TrimLeft(TrimRight(str, ToTrim), ToTrim);
    }
    
    void Trim(const std::string& ToTrim)
    {
        setString(Trim(_Value, ToTrim));
    }

    static std::string TrimSpaces(const std::string& str)
    {
        return TrimSpacesLeft(TrimSpacesRight(str));
    }
    
    void TrimSpaces()
    {
        setString(TrimSpaces(_Value));
    }

    static std::string JoinString(const std::vector <std::string>& vWords, const std::string& separator)
    {
        if (vWords.empty()) return "";

        std::string str = "";

        for (const std::string& word : vWords)
        {
            str.append(word);
            str.append(separator);
        }

        return str.substr(0, str.length() - separator.length());
    }

    static std::string JoinString(const std::string arr[], size_t length, const std::string& separator)
    {
        std::string str = "";

        for (size_t i = 0; i < length; i++)
        {
            str.append(arr[i]);
            str.append(separator);
        }

        return str.substr(0, str.length() - separator.length());
    }

    static std::string ReverseWords(const std::string& str)
    {
        if (str.empty()) return "";

        std::vector <std::string> vWords = Split(str, " ");
        std::string ReversedStr = "";

        std::vector<std::string>::iterator it = vWords.end();
        while (it != vWords.begin())
        {
            --it;
            ReversedStr.append(*it);
            ReversedStr.append(" ");
        }
        ReversedStr.pop_back();

        return ReversedStr;
    }

    void ReverseWords()
    {
        setString(ReverseWords(_Value));
    }

    static std::string ReplaceWord(std::string str, const std::string& WordToReplace, const std::string& NewWord)
    {
        size_t pos = 0;

        while ((pos = str.find(WordToReplace, pos)) != std::string::npos)
        {
            str.replace(pos, WordToReplace.length(), NewWord);
            pos += NewWord.length();
        }

        return str;
    }

    void ReplaceWord(const std::string& WordToReplace, const std::string& NewWord)
    {
        setString(ReplaceWord(_Value, WordToReplace, NewWord));
    }

    static void Replace(std::string& str, size_t pos, size_t WordLength, const std::string& NewWord)
    {
        std::string remainder = str.substr(pos + WordLength);
        str.erase(pos);
        str.append(NewWord);
        str.append(remainder);
    }

    void Replace(size_t pos, size_t WordLength, const std::string& NewWord)
    {
        Replace(_Value, pos, WordLength, NewWord);
    }

    static std::string cReplaceWord(const std::string& str, std::string WordToReplace, const std::string& NewWord, bool MatchCase = true)
    {
        std::vector <std::string> vWords = Split(str, " ");

        if (MatchCase)
        {
            for (std::string& word : vWords)
            {
                if (word == WordToReplace)
                {
                    word = NewWord;
                }
            }
        }
        else
        {
            WordToReplace = LowerAllLetters(WordToReplace);

            for (std::string& word : vWords)
            {
                if (LowerAllLetters(word) == WordToReplace)
                {
                    word = NewWord;
                }
            }
        }

        return JoinString(vWords, " ");
    }

    void cReplaceWord(const std::string& WordToReplace, const std::string& NewWord, bool MatchCase = true)
    {
        setString(cReplaceWord(_Value, WordToReplace, NewWord, MatchCase));
    }

    static std::string RemovePunct(const std::string& str)
    {
        std::string NewStr = "";

        for (size_t i = 0; i < str.length(); i++)
        {
            if (!ispunct(str[i]))
            {
                NewStr += str[i];
            }
        }

        return NewStr;
    }

    void RemovePunct()
    {
        setString(RemovePunct(_Value));
    }
};