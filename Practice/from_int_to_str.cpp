#include <iostream>
#include <string>

std::string FromStrToInt(int num)
{
    std::string result;
    for (int i = num; i >= 1; i /= 10)
    {
        char temo = (i % 10) + '0';
        result.insert(result.begin(), 1, temo);
    }
    return result;
}

int main()
{
    std::cout << "Enter a str numbers: ";
    int num;
    std::cin >> num;

    std::string result = FromStrToInt(num);
    std::cout << result << std::endl;
}