#include <iostream>
#include <string>

int FromStrToInt(const std::string &str)
{
    int num = 0;
    for (int i = 0; i < str.size(); i++)
    {
        num = num * 10 + str[i] - 0x30;
    }
    return num;
}

int main()
{
    std::cout << "Enter a str numbers: ";
    std::string str;
    getline(std::cin, str);

    int result = FromStrToInt(str);
    std::cout << result << std::endl;
}