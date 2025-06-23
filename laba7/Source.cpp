#include "header.h"

int main()
{
std::string str;
std::string delim{" .,!?"};

std::cout << "Input string: \n";
getline(std::cin, str);
std::string result{CheckString(str)};
std::cout << '\n' << result;
return 0;
}