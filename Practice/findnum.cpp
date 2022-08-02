#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v = {1, 3, 5, 2, 1, 6, 1, 12};
    int num = 1;
    int k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != num)
        {
            v[k] = v[i];
            k++;
        }
    }
    for (auto x : v)
    {
        std::cout << x << ' ';
    }
    return 0;
}
