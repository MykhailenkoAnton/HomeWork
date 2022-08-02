#include <iostream>
#include <list>
int foo(int n)
{
    return (n == 1) ? 1 : n * foo(n - 1);
}
int main()
{
    std::cout << foo(6);
    return 0;
}