#include <iostream>
#include <string>
#include <cstring>

bool IsPolindrom(const std::string & str)
{
    std::string newStr;
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            newStr += str[i];
            std::cout << newStr << std::endl;
        }
        else
        {
            continue;
        }
    }
    
    for (int i = 0, j = newStr.size() - 1; i < j; i++, j--)
    {
        if (newStr[i] != newStr[j])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string str;
    std::cout << "Enter a string: ";
    getline(std::cin, str);
    bool result = IsPolindrom(str);
    
    if (result)
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";
    }
    
    return 0;
}