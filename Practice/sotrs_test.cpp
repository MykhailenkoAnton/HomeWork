#include <iostream>
const int SIZE = 10;

//bubble sort
// void AnySortr(int * arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = size - 1; i < j; j--)
//         {
//             if (arr[i] > arr[j])
//             {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
            
//         }
        
//     }
    
// }

// insert
void AnySortr(int * arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
    
}

void Show(int * arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int arr[SIZE] = {13, 23, 11, 1, 12, 2, 4, 13, 0, -1};

    Show(arr, SIZE);
    
    AnySortr(arr, SIZE);

    Show(arr, SIZE);
    return 0;
}