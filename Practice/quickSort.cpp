#include <iostream>
const int SIZE = 5;

// быстрая сортировка
void QuickSort(int arr[], int first, int last)
{
    int middle = arr[(first + last) / 2];
    int i = first;
    int j = last;
    do
    {
        while (arr[i] < middle)
        {
            i++;
        }
        while (arr[j] > middle)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > first)
    {
        QuickSort(arr, first, j);
    }
    if (i < last)
    {
        QuickSort(arr, i, last);
    }
}


int main()
{
    int arr[SIZE] = {3, 14, 11, 2, 6};

    QuickSort(arr, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    
    return 0;
}