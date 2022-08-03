#include <iostream>
#include <string>

void reverseStr(std::string & str)
{
    // int lenght = str.size();
    // for (int i = 0; i < (lenght / 2); i++)
    // {
    //     std::swap(str[i], str[lenght - i - 1]);
    // }

    // int i = 0;
    // int j = str.size() - 1;
    // while (i < j)
    // {
    //     char ch = str[i];
    //     str[i] = str[j];
    //     str[j] = ch;
    //     i++;
    //     j--;
    // }
    
    int lenght = str.size();
    for (int i = 0, j = lenght - 1; i < j; i++, j--)
    {
        std::swap(str[i], str[j]);
    }
}

int main()
{
    std::cout << "Etnter string to reverse: ";
    std::string str;
    std::getline(std::cin, str);

    reverseStr(str);

    std::cout << str << std::endl;
    return 0;
}