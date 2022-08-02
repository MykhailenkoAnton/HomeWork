#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

class MyClass
{
public:
    void DoWork_ONE()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "WORK Started in DoWork_ONE ====== id threed = " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "WORK STOP in DoWork_ONE ====== id threed = " << std::this_thread::get_id() << std::endl;
    }
    void DoWork_TWO(int a)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "WORK Started in DoWork_TWO ====== id threed = " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "Dowork_TWO = " << a << std::endl;
        std::cout << "WORK STOP in DoWork_TWO ====== id threed = " << std::this_thread::get_id() << std::endl;
    }
    int Sum(int a, int b)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "WORK Started in Sum ====== id threed = " << std::this_thread::get_id() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "WORK STOP in Sum ====== id threed = " << std::this_thread::get_id() << std::endl;
        return a + b;
    }
};
int main()
{   
    int result;
    MyClass mc;
    // auto result_sum = [&result, &mc]() {result = mc.Sum(2, 6);};
    // std::thread t11(result_sum);
    // std::thread t11(&MyClass::DoWork_TWO, mc, 15);
    std::thread t11([&mc](){
        mc.DoWork_TWO(13);
    });
    for (int i = 0; i < 10; i++)
    {
       std::cout << i + 1 << "\tID thread = " << std::this_thread::get_id() << "\tmain works\n";
       std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
    }
    t11.join();
    // std::cout << "Result = " << result << std::endl;
    return 0;
}
