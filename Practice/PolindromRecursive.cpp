#include <iostream>
#include <string>
bool Polindrom(const std::string & str, int start, int size);

int main()
{
    std::string str = "rar";
    bool result = Polindrom(str, 0, str.size());

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

bool Polindrom(const std::string & str, int start, int size)
{
    if (size == 1)
    {
        return true;
    }
    else if (str[start] != str[size - 1])
    {
        return false;
    }
    else
    {
        Polindrom(str, start + 1, size - 1);
    }
    
    return true;
}

