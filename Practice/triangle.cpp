#include <iostream>

void triangleRec(int n);

int main()
{
    triangleRec(6);
    return 0;
}

void triangleRec(int n)
{
    if (n == 0)
    {
        return;
    }

    triangleRec(n - 1);

    for(int i = 0; i < n; i++)
    {
        std::cout << n << ' ';
    }    
}