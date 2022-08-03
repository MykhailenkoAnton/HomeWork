#include <iostream>
#include <string>
#define STR(s1, s2) s1.size() < s2.size()

int main()
{
    std::string st1;
    std::string st2;
    std::cout << "enter st1: ";
    std::getline(std::cin, st1);
    std::cout << "enter st2: ";
    std::getline(std::cin, st2);
    if(STR(st1, st2))
    {
        std::cout << "True\n";
    }
    else
    {
        std::cout << "False\n";
    }
    return 0;
}