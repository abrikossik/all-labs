#include "header.h"

bool IsDigitOnly(const std::string& word)
{
    return (!word.empty() && std::all_of(word.begin(), word.end(), isdigit));
}


bool IsAlphaOnly(const std::string& word)
{
    return (!word.empty() && std::all_of(word.begin(), word.end(), isalpha));
}


bool IsAlnumMixed(const std::string& word)
{
    return !word.empty() && std::any_of(word.begin(), word.end(), isdigit) && std::any_of(word.begin(), word.end(), ::isalpha);
}


std::string CheckWord(std::string& string)
{
    if (IsDigitOnly(string) && string.length() < 7)
    {
        return std::string(string.rbegin(), string.rend());
    }

    else if (IsAlnumMixed(string))

    {
        std::string result = string;
        for (char& ch : result)
        {
            if (std::islower(ch))
            {
                ch = std::toupper(ch);
            }
        }
        return result;
    }

    else if (IsAlphaOnly(string))

    {
        std::string result = string;
        for (char& ch : result)
        {
            ch = std::tolower(ch);
        }
        return result;
    }
    return string;
}


std::string CheckString(std::string& input)
{
    std::string result, word;
    bool was_space = true;

    for (char ch : input)
    {
        if (std::isalnum(ch))
        {
            word += ch;
            was_space = false;
        }

        else

        {
            if (!word.empty())
            {
                if (!result.empty()) result += ' ';
                result += CheckWord(word);
                word.clear();
            }
            was_space = true;
        }
    }

    if (!word.empty())
    {
        if (!result.empty()) result += ' ';
        result += CheckWord(word);
    }

    return result;
}
