#include <iostream>
const int SIZE = 5;

int findN(int * arr, int size, int key)
{
    for (int i = 0; i < 10; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[5] = {3, 14, 16, 12, 13};

    std::cout << "Enter a key: ";
    int key;
    std::cin >> key;
    int result = findN(arr, SIZE, key);
    if (result != - 1)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }
    
}