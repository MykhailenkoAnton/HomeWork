#include <iostream>
#include <string>
#define CALL(s1, s2) Tmax(s1, s2)

bool Tmax(const std::string s1, const std::string s2)
{
    return s1.size() > s2.size();
}
int main()
{
    std::string st1;
    std::string st2;
    std::cout << "Enter st1: ";
    std::getline(std::cin, st1);
    std::cout << "Enter st2: ";
    std::getline(std::cin, st2);
    if (CALL(st1, st2))
    {
        std::cout << "st1 more";
    }
    else
    {
        std::cout << "st2 more";
    }
}