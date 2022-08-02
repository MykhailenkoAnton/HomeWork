#include <iostream>
#include <string>
bool Foo(const std::string & str);
int main()
{
    std::string str = "9+3-(56-5)-9+(3-56)-5(())";
    bool result = Foo(str);
    if (result)
    {
        std::cout << "right!\n";
    }
    else
    {
        std::cout << "no!\n";
    }
}
bool Foo(const std::string & str)
{
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            count++;
        }
        else if(str[i] == ')')
        {
            count--;
        }
    }
    return count == 0;
}