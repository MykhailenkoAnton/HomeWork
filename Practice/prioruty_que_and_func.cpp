#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>
class More
{
public:
    More() {}
    ~More() {}
    bool operator()(int a, int b)
    {
        return a > b;
    }
};
int main()
{
    std::priority_queue<int, std::vector<int>, More> Myqueue;
    Myqueue.push(10);
    Myqueue.push(20);
    Myqueue.push(30);
    while (!Myqueue.empty())
    {
        int x = Myqueue.top();
        std::cout << x << std::endl;
        Myqueue.pop();
    }
    return 0;
}

