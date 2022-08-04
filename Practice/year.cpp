#include <iostream>
const int LEAP = 29;

bool isLeapYear(int x)
{
    if (x == LEAP)
    {
        return true;
    }
    return false;
}

int main()
{
    std::cout << "Enter please february's days: ";
    int days;
    std::cin >> days;

    bool result = isLeapYear(days);

    if (result)
    {
        std::cout << "Leap year\n";
    }
    else
    {
        std::cout << "Not leap year\n";
    }
    return 0;
}