#include "header.h"

int main()
{
    char input[300]{};
    char result[300]{};
    char word[100]{};
    int32_t maxUnique{};
    int32_t resultLen{};

    std::cout << "Input string:\n";
    std::cin.getline(input, 300);

    int32_t i{};
    int32_t wordLen{};
    bool seen[256]{};
    while (true) 
    {
        char ch = input[i];

        if (!isDelimiter(ch) && ch != '\0')
        {
            word[wordLen++] = ch;
            ++i;
        }
        else
        {
            if (wordLen > 0)
            {
                word[wordLen] = '\0';
                std::memset(seen, 0, sizeof(seen));
                int32_t uniqueCount{};

                for (int32_t j{}; j < wordLen; ++j)
                {
                    unsigned char c = word[j];
                    if (!seen[c])
                    {
                        seen[c] = true;
                        ++uniqueCount;
                    }
                }

                if (uniqueCount > maxUnique)
                {
                    std::strcpy(result, word);
                    resultLen = std::strlen(result);
                    maxUnique = uniqueCount;
                }
                else if (uniqueCount == maxUnique)
                {
                    std::strcat(result + resultLen, ", ");
                    std::strcat(result + resultLen, word);
                    resultLen = std::strlen(result);
                }

                wordLen = 0;
            }
            if (ch == '\0')
            {
                break;
            }
            ++i;
        }
    }

    std::cout << "Result:\n" << result << '\n';
    return 0;
}