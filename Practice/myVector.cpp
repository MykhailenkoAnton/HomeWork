#include <iostream>
#include <memory>

// insert
// erase

namespace MyV
{
    class myVector
    {
    private:
        int _capacity = 1;
        int _size = 0;
        int * _array = nullptr;
    private:
        std::ostream & out( std::ostream &os ) const {
            os << _array;
            return os;
        }
        void clearMemory()
        {
            for (auto it = this->begin() + _size; it != end(); it++)
            {
                delete it;
            }
        }


    public:

        template <typename T>
        class Iterator
        {
        private:
            T * type = nullptr;
        public:
            Iterator(T * t);
            ~Iterator();
            Iterator & operator=(const Iterator & other);
            Iterator & operator++();
            Iterator & operator++(int i);
            T & operator*();
            // T * operator->();
            T * operator+(int index);
        };
    public:
        myVector();
        myVector(int size);
        myVector(const myVector & mv);
        myVector & operator=(const myVector & mv);
        myVector(myVector && mv) noexcept;
        myVector & operator=(myVector && mv) noexcept;
        ~myVector();

        int & operator[](int & index);
        const int & operator[](int & index) const;
        int & operator*();
        const int & operator*() const;
        int * operator+(int index);

        Iterator<int> begin();
        int * end();

        int size() const;
        int capacity() const;
        bool isEmpty() const;
        void reallocationMemory();
        void Show();
        void push_back(const int & value);
        void push_front(const int & value);
        void pop_back();
        void pop_front();
        void clear();
        void swap(myVector & mv);
        void reverse();
        void insert(int * it, const int & value)
        {
            std::cout << it << std::endl;
            if (!isEmpty())
            {
                if (_capacity <= _size)
                {
                    reallocationMemory();
                }
            }

        }
    public:
        friend std::ostream & operator<<(std::ostream & os, const myVector & mv);
    };
    
    myVector::myVector()
    {
        _array = new int[_capacity];
    }

    myVector::~myVector() 
    {
        delete [] _array;
    }

    myVector::myVector(int size) : _size(size), _capacity(size)
    {
        _array = new int[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _array[i] = 0;
        }
    }

    int myVector::size() const
    {
        return _size;
    }

    int myVector::capacity() const
    {
        return _capacity;
    }

    int & myVector::operator[](int & index)
    {
        return _array[index];
    }

    bool myVector::isEmpty() const
    {
        return _size == 0;
    }

    const int & myVector::operator[](int & index) const
    {
        return _array[index];
    }

    std::ostream & operator<<(std::ostream & os, const myVector & mv)
    {
        return mv.out(os);
    }

    myVector::Iterator<int> myVector::begin() 
    {
        return Iterator<int>(_array);
    }

    int * myVector::end() 
    {
        return _array + _size;
    }

    int & myVector::operator*()
    {
        return *_array;
    }

    const int & myVector::operator*() const
    {
        return *_array;
    }

    int * myVector::operator+(int index)
    {
        return _array + index;
    }

    void myVector::push_back(const int & value)
    {
        if (_capacity <= _size)
        {
            reallocationMemory();
        }
        _array[_size] = value;
        ++_size;
    }

    void myVector::push_front(const int & value)
    {
        if (_capacity <= _size)
        {
            reallocationMemory();
        }
        for (int i =_size + 1; i > 0; i--)
        {
            _array[i] = _array [i - 1];
        }
        _array[0] = value;
        _size++;
    }

    void myVector::pop_back()
    {
        if(!isEmpty())
        {
            --_size;
            clearMemory();
        }
    }

    void myVector::pop_front()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < _size; i++)
            {
                _array[i] = _array[i + 1];
            }
            --_size;
            clearMemory();
        }
    }

    void myVector::clear()
    {
        while (!isEmpty())
        {
            this->pop_back();
        }
    }

    void myVector::swap(myVector & mv)
    {
        myVector temp = mv;
        mv = *this;
        *this = temp;
    }

    void myVector::reverse()
    {
        for (int i = 0, j = _size - 1; i < j; i++, j--)
        {
            int temp = _array[i];
            _array[i] = _array[j];
            _array[j] = temp;
        }
    }

    void myVector::Show()
    {
        for (int i = 0; i < _size; i++)
        {
            std::cout << _array[i] << ' ';
        }
    }

    void myVector::reallocationMemory()
    {
        _capacity *= 2;
        int * temp = _array;
        _array = new int[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _array[i] = temp[i];
        }
        delete temp;
    }


    myVector::myVector(const myVector & mv)
    {
        _array = new int[mv._capacity];
        _size = mv._size;
        _capacity = _capacity;
        for (int i = 0; i < _size; i++)
        {
            _array[i] = mv._array[i];
        }
    }

    myVector & myVector::operator=(const myVector & mv)
    {
        if (this == &mv)
        {
            return *this;
        }
        delete [] _array;
        _array = new int[mv._capacity];
        _size = mv._size;
        _capacity = _capacity;
        for (int i = 0; i < _size; i++)
        {
            _array[i] = mv._array[i];
        }
        return *this;
    }

    myVector::myVector(myVector && mv) noexcept 
    : _array(mv._array)
    , _size(mv._size)
    , _capacity(mv._capacity)
    {
        mv._array = nullptr;
    }
    myVector & myVector::operator=(myVector && mv) noexcept
    {
        if (this != &mv)
        {
            delete [] _array;
            _array = mv._array;
            _size = mv._size;
            _capacity = mv._capacity;
            mv._array = nullptr;
        }
        return *this;
    }

    //iterator
    template <typename T>
    myVector::Iterator<T>::Iterator(T * t) : type(t)
    {
    }
    
    template <typename T>
    myVector::myVector::Iterator<T>::~Iterator()
    {
    }

    template <typename T>
    myVector::Iterator<T> & myVector::Iterator<T>::operator=(const Iterator & other)
    {
        if (this != &other)
        {
            type = other.type;
        }
        return *this;
    }

    template <typename T>
    myVector::Iterator<T> & myVector::Iterator<T>::operator++()
    {
        ++type;
        return *type;
    }

    template <typename T>
    myVector::Iterator<T> & myVector::Iterator<T>::operator++(int i)
    {
        Iterator temp(type);
        ++type;
        return temp;
    }

    template <typename T>
    T & myVector::Iterator<T>::operator*()
    {
        return *type;
    }

    // template <typename T>
    // T* myVector::Iterator<T>::operator->()
    // {
    //     return type;
    // }

    template <typename T>
    T * myVector::Iterator<T>::operator+(int index)
    {
        return type + index;
    }
}

#include <vector>
int main()
{
    // MyV::myVector mv;
    // mv.push_back(101);
    // mv.push_back(10);
    // mv.push_back(1333);
    // mv.Show();
    // std::cout << std::endl;
    // MyV::myVector mv1(5);

    // for (int i = 0; i < 5; i++)
    // {
    //     mv1[i] = i + 13;
    // }
    // mv1.Show();
    // std::cout << std::endl;
    // std::cout << "mv capacity = " << mv.capacity() << " mv size = " << mv.size() << std::endl;
    // std::cout << "mv1 capacity = " << mv1.capacity() << " mv1 size = " << mv1.size() << std::endl;

    // mv1.push_back(201);
    // mv1.Show();
    // std::cout << std::endl;
    // std::cout << "mv capacity = " << mv.capacity() << " mv size = " << mv.size() << std::endl;
    // std::cout << "mv1 capacity = " << mv1.capacity() << " mv1 size = " << mv1.size() << std::endl;


    
    // mv1.push_front(101);
    // mv1.Show();
    // std::cout << std::endl;
    // std::cout << "mv capacity = " << mv.capacity() << " mv size = " << mv.size() << std::endl;
    // std::cout << "mv1 capacity = " << mv1.capacity() << " mv1 size = " << mv1.size() << std::endl;

    // mv1.pop_back();
    // mv1.Show();
    // std::cout << std::endl;
    // std::cout << "mv capacity = " << mv.capacity() << " mv size = " << mv.size() << std::endl;
    // std::cout << "mv1 capacity = " << mv1.capacity() << " mv1 size = " << mv1.size() << std::endl;

    // mv1.pop_front();
    // mv1.Show();
    // std::cout << std::endl;
    // std::cout << "mv capacity = " << mv.capacity() << " mv size = " << mv.size() << std::endl;
    // std::cout << "mv1 capacity = " << mv1.capacity() << " mv1 size = " << mv1.size() << std::endl;


    // mv1.clear();
    // mv1.Show();
    // std::cout << std::endl;
    // std::cout << "mv capacity = " << mv.capacity() << " mv size = " << mv.size() << std::endl;
    // std::cout << "mv1 capacity = " << mv1.capacity() << " mv1 size = " << mv1.size() << std::endl;


    MyV::myVector m1;

    m1.push_back(13);
    m1.push_back(14);
    m1.push_back(15);
    m1.push_back(1);
    m1.push_back(15);
    std::cout << "m1 = ";
    m1.Show();
    std::cout << std::endl;

    std::cout << (m1.begin() + 3);
    std::cout << std::endl;
    m1.insert(m1.begin() + 3, 19);
    m1.Show();
    std::cout << std::endl;

    // MyV::myVector m2;

    // m2.push_back(21);
    // m2.push_back(22);
    // m2.push_back(23);
    // std::cout << "m2 = ";
    // m2.Show();
    // std::cout << std::endl;

    // m1.swap(m2);
    // std::cout << "m1 = ";
    // m1.Show();
    // std::cout << std::endl;
    // std::cout << "m2 = ";
    // m2.Show();
    // std::cout << std::endl;
    // std::cout << "m2 reverse = ";
    // m2.reverse();
    // m2.Show();
    // std::cout << std::endl;

    
    
    return 0;
}