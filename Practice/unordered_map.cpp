#include <iostream>
#include <unordered_map>
#include <ctime>
const int MAX = 10;



int main()
{
    std::srand(time(0));
    std::unordered_map<char, int> myMap;
    for (int i = 0; i < MAX; i++)
    {
        myMap[char('a' + rand() % ('z' - 'a'))] = 1 + rand() % 100;
    }
    // reset:
    // for (auto & pair : myMap)
    // {
    //     if (pair.second % 2 == 0)
    //     {
    //         std::cout << pair.first << " " << pair.second <<  std::endl;
    //         myMap.erase(pair.first);
    //         goto reset;
    //     }
    // }
    decltype(myMap) newMap;
    for (auto&& iMap : myMap)
    {
        if ((iMap.second % 2) == 0)
        {
            newMap.emplace(std::move(iMap));
        }
    }
    for (auto & p : newMap)
    {
        std::cout << p.first << " " << p.second <<  std::endl;
    }
}


