#include <iostream>
#include <memory>
class A
{
public:
    void Show(){std::cout << "A\n";}
    A() {std::cout << "Cons\n";}
    ~A() {std::cout << "Des\n";}
};
void Deleter(int * a)
{
    std::cout << "Deleter\n";
    delete a;
}
int main()
{
    {
        std::shared_ptr<int> ptr{new int{}, Deleter};
        // ptr->Show 
        std::shared_ptr<int>::element_type var;
        std::cout << std::endl;
        var = 10;
        std::cout << var;
    }
    return 0;
}