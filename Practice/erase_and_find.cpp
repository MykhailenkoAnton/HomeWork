#include <iostream>
#include <set>
#include<algorithm>
int main()
{
    std::multiset<int> mySet({33, 61,  56, 23, 12, 3, 1, 1, 3, 4, 4, 1 , 33 ,12});

    for (auto x : mySet)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    auto it = std::find(mySet.begin(), mySet.end(), 1);
    mySet.erase(it);
   
    for (auto x : mySet)
    {
        std::cout << x << ' ';
    }
    
    return 0;
}