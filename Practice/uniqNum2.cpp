#include <iostream>
#include <algorithm>
#include <set>
const int MAX = 10;
// 13, 13, 13, 42, 111, 42, 12, 12, 22, 13
int uniq(int * arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
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
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int arr[MAX] = {13, 13, 13, 42, 103, 42, 12, 12, 12, 13};

    int result = uniq(arr, MAX);
    if (result == -1)
    {
        std::cout << "Not num\n";
    }
    else
    {
        std::cout << "result " << result << std::endl;
    }
    
    return 0;
}