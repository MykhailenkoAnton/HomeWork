#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
std::mutex mtx;
void Show(char ch)
{
    mtx.lock();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    mtx.unlock();
}
int main()
{
    std::thread t1(Show, '*');
    std::thread t2(Show, '#');
    t1.join();
    t2.join();
    return 0;
}
