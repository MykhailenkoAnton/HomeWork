#include <iostream>
#include <string>
void revertString(std::string & str);
int main()
{
    std::cout << "Enter str:\n";
    std::string str;
    std::cin >> str;
    revertString(str);
    std::cout << str;
    return 0;
}
void revertString(std::string & str)
{
    // int j = str.size() - 1;
    // int i = 0;
    // while (i < j)
    // {
    //     char ch = str[i];
    //     str[i] = str[j];
    //     str[j] = ch;
    //     i++;
    //     j--;
    // }
    int length = str.size();
    for( int i = 0; i < (length/2); ++i)
    {
        std::swap(str[i], str[length - i - 1]);
    }
}