#include <iostream>
const int SIZE = 5;


void InSort(int * arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j;
        for(j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[SIZE] = {3, 4, 11, 2, 6};

    InSort(arr, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}