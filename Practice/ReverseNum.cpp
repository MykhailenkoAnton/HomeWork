#include <iostream>


//cout 
// void Reverse(int n);

// int main()
// {
//     int num = 1564;
//     std::cout << num << std::endl;
//     Reverse(num);
//     return 0;
// }

// void Reverse(int n)
// {
//     if (n < 10)
//     {
//         std::cout << n;
//         return;
//     }
//     else
//     {
//         std::cout << n % 10;
//         Reverse(n /10);
//     }

// }

// return int

int Reverse(int n);

int main()
{
    int num = 1564;
    std::cout << num << std::endl;
    std::cout << Reverse(num);
    return 0;
}

int sum, rem = 0;
int Reverse(int n)
{
    if (n < 1)
    {
        return 0;
    }
    else
    {
        rem = n % 10;
        sum = sum * 10 + rem;
        Reverse(n /10);
    }
    return sum;
}
