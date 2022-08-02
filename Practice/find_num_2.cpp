#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::vector<int> myVect {1, 3, 5 , 7, 8, 9};
    auto it = std::find_if(myVect.begin(), myVect.end(), [](int x){
        return x % 2 == 0;
    });
    if (it != myVect.end())
    {
        std::cout << *it << " Found!\n";
    }
    return 0;
}
