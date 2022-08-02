#include <iostream>
int pows(int a, int b)
{
    int result = 1;
    for (int i = 0; i < b; i++)
    {
        result *= a;
    }
    return result;
}
int main()
{
    std::cout << "Enter number: ";
    int num1, num2;
    std::cin >> num1;
    std::cout << "Enter powNumber: ";
    std::cin >> num2;
    int num3 = pows(num1, num2);
    std::cout << num3 << std::endl;
    return 0;
}
