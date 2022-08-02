#include <iostream>
#include <memory>
class A
{
public:
    A()
    {
        std::cout << "Contructor!\n";
    }
    ~A() {
        std::cout << "Destructor!\n";
    }
};
int main()
{
        try
        {
            std::unique_ptr<A> ptr(new A());
            throw 1;
        }
        catch(int)
        {
        }
    return 0;
}