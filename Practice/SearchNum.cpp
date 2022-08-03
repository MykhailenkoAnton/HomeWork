#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
void Show(int x)
{
    std::cout << x << ' ';
}

int main()
{
    std::vector<int> v1 = {1, 13, 14, 16, 17, 12, 10, 2, 4}; // 12 10 2 4
    std::vector<int> v2 = {1, 13, 14, 16, 17, 28, 11, 32, 44}; // 28 11 32 44
    std::vector<int> v3;
    for(auto & x : v1)
    {
        auto it = std::find(v2.begin(), v2.end(), x);
        if (it == v2.end())
        {
            v3.push_back(x);
        }
    }
    for(auto & x : v2)
    {
        auto it = std::find(v1.begin(), v1.end(), x);
        if (it == v1.end())
        {
            v3.push_back(x);
        }
    }
    std::for_each(v3.begin(), v3.end(), Show);
    return 0;
}