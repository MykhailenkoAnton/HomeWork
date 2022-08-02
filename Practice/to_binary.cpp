// Распечатать произвольное число в двоичной системе исчисления.
// Описание.
// Написать функцию, принимающую на вход произвольное целочисленное значение и возвращающую 
// строку, содержащую его представление в двоичной системе исчисления.

#include <iostream>
#include <ctime>
#include <string>
std::string Foo(int & num);
int main()
{
    std::srand(time(0));
    int number = rand() % 513;
    std::cout << number << std::endl;
    std::string this_binary_num = Foo(number);
    std::cout << this_binary_num << std::endl;
    return 0;
}
std::string Foo(int & num)
{
    std::string str = "";
    for (int i = 0; num > i; num = num / 2)
    {
        if (num % 2 == 0)
        {
            str.insert(str.begin(), 1, '0');
        }
        else
        {
            str.insert(str.begin(), 1, '1');
        }
    }
    return str;
}
