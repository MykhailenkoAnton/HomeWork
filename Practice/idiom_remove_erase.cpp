#include <iostream>
#include <vector>
#include <algorithm>
void Show(const std::vector<int> & vect)
{
    for (auto x : vect)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> myV = {1, 3, 4, 3, 5, 3, 6, 7, 9, 23, 4, 3, 12};
    Show(myV);

    auto last = std::remove(myV.begin(), myV.end(), 3);
    myV.erase(last, myV.end());

    // myV.erase(std::remove(myV.begin(), myV.end(), 3), myV.end()); 
    
    Show(myV);
    return 0;
}