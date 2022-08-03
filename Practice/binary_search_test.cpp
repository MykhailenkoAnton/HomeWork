#include <iostream>
#include <algorithm>
bool Search(int * arr, int size, int key)
{
    int leftSide = 0;
    int rightSide = size - 1;

    while (leftSide <= rightSide)
    {
        int middle = (leftSide + rightSide) / 2;
        if (key == arr[middle])
        {
            return true;
        }
        else if (key > arr[middle])
        {
            leftSide = middle + 1;
        }
        else if (key < arr[middle])
        {
            rightSide = middle - 1;
        }
    }
    return false;
}

int main()
{
    int arr[10] = {31, 12, 23, 41, 11, 12, 10 , 9, 1, 0};
    std::sort(arr, arr + 10);

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << ' ';
    }

    int key;
    std::cout << "\nEnter key searching: ";
    std::cin >> key;
    
    bool result = Search(arr, 10, key);

    if (result)
    {
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No!\n";
    }
    
}