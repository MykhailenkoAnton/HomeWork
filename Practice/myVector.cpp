#include <iostream>


namespace MyV
{
    class myVector
    {
    private:
        int _capacity = 0;
        int _size = 0;
        int * _array = nullptr;
    private:
        std::ostream & out( std::ostream &os ) const {
            os << _array;
            return os;
        }
    public:
        myVector() {}
        myVector(int size);
        friend std::ostream & operator<<(std::ostream & os, const myVector & mv);
        int & operator[](int & index);
        const int & operator[](int & index) const;
        ~myVector();
    };
    
    myVector::~myVector() 
    {
        delete [] _array;
    }

    myVector::myVector(int size) : _size(size), _capacity(size)
    {
        _array = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            _array[i] = 0;
        }
    }

    int & myVector::operator[](int & index)
    {
        return _array[index];
    }

    const int & myVector::operator[](int & index) const
    {
        return _array[index];
    }

    std::ostream & operator<<(std::ostream & os, const myVector & mv)
    {
        return mv.out(os);
    }
}



const int MAX = 10;
int main()
{
    MyV::myVector mv(MAX);

    for (int i = 0; i < MAX; i++)
    {
        std::cout << mv[i] << ' ';
    }
    return 0;
}