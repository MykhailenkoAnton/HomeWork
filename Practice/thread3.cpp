
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
void Foo();
int main()
{
    std::thread As = std::thread(Foo);
    std::cout << "Main three id = " << std::this_thread::get_id();
    std::cout << std::endl;
    As.join();
    return 0;
}
void Foo()
{
    std::cout << "Foo three id = " << std::this_thread::get_id();
    std::cout << std::endl;
}

void Threand_ONE()
{
    for (int i = 0; i < 10; i++)
    {
       std::cout << i + 1 << "\tID thread = " << std::this_thread::get_id() << "\tThreand_ONE\n";
       std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
    }
}

void Threand_TWO()
{
    for (int i = 0; i < 10; i++)
    {
       std::cout << i + 1 << "\tID thread = " << std::this_thread::get_id() << "\tThreand_TWO\n";
       std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
    }
}

void Threand_THREE()
{
    for (int i = 0; i < 10; i++)
    {
       std::cout << i + 1 << "\tID thread = " << std::this_thread::get_id() << "\tThreand_THREE\n";
       std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
    }
}

int Sum(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "WORK STARTED in DoWork ====== id threed = " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "WORK STOPPED in DoWork ====== id threed = " << std::this_thread::get_id() << std::endl;
    return a + b;
}
int main()
{
    int result;
    auto l1 = [&result]() { result = Sum(2, 5);};
    std::thread t1(l1);
    for (int i = 0; i < 10; i++)
    {
       std::cout << i + 1 << "\tID thread = " << std::this_thread::get_id() << "\tmain works\n";
       std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
    }
    t1.join();
    std::cout << "Sum result = " << result << std::endl;
    return 0;
}
