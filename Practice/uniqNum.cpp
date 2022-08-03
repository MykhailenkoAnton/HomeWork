#include <iostream>
#include <algorithm>
#include <set>
const int MAX = 10;
// 13, 13, 13, 42, 111, 42, 12, 12, 22, 13
void uniq(int * arr, int size)
{
    int temp;
    for (size_t i = 0; i < size; i++)
    {
        temp = arr[i];
        bool res = false;
        for (size_t j = 0; j < size; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (arr[i] == arr[j])
            {
                res = true;
                break;
            }
        }
        if(!res)
        {
            std::cout << arr[i] << ' ';
        }
    }
}

int main()
{
    int arr[MAX] = {13, 13, 13, 42, 111, 42, 12, 12, 22, 13};

    uniq(arr, MAX);
    
    return 0;
}