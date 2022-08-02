#include <iostream>
int Fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    
    return Fibonacci(n - 1) + Fibonacci(n - 2);

    // int a = 0;
    // int b = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     a = a + b;
    //     b = a - b;
    // }
    // return a;    
}

int main()
{
    std::cout << Fibonacci(7) << std::endl;
    return 0;
}
