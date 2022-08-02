#include <iostream>
const int SIZE = 5;

void BubleSort(int * arr, size_t size)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = SIZE - 1; j > i; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[SIZE] = {3, 4, 1, 2, 6};

    BubleSort(arr, SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}