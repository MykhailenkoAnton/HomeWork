#include <iostream>
#include <algorithm>

const int SIZE = 10;

// бинарный поиск только после сортировки
bool biSearch(int * arr, int size, int n)
{
    int leftSide = 0;
    int rightSide = size - 1;
    
    while(leftSide <= rightSide)
    {
        int middle = (leftSide + rightSide) / 2;
        if(n == arr[middle])
            return true;
        else if(n > arr[middle])
            leftSide = middle + 1;
        else if(n < arr[middle])
            rightSide = middle - 1;
    }
    return false;
}

int main()
{
    int arr[SIZE] = {31, 11, 2, 3, 14, 16, 1, 0, 19, 10};
    std::sort(arr, arr + SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << ' ';
    }

    bool result = biSearch(arr, SIZE, 111);
    std::cout << std::endl;
    if (result)
    {
        std::cout << "Find\n";
    }
    else
    {
        std::cout << "No\n";
    }
    
    
}