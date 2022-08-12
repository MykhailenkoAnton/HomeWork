#include <iostream>
#include <memory>
namespace MyV
{
    template <typename Type>
    class myVector
    {
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
            T * operator++();
            T * operator++(int i);
            T * operator--();
            T & operator*();
            T * operator->();
            T * operator+(int index);
            T * operator-(int index);
            bool operator==(const Iterator & other);
            bool operator!=(const Iterator & other);
        };
    public:
        myVector();
        myVector(Type size);
        myVector(const myVector<Type> & mv);
        myVector<Type> & operator=(const myVector<Type> & mv);
        myVector(myVector<Type> && mv) noexcept;
        myVector<Type> & operator=(myVector<Type> && mv) noexcept;
        ~myVector();

        Type & operator[](Type & index);
        const Type & operator[](Type & index) const;
        Type & operator*();
        const Type & operator*() const;
        Type * operator+(Type index);
        
        Iterator<Type> begin();
        Iterator<Type> end();

        int size() const;
        int capacity() const;
        bool isEmpty() const;
        void reallocationMemory();
        void Show();
        void push_back(const Type & value);
        void push_front(const Type & value);
        void pop_back();
        void pop_front();
        void clear();
        void swap(myVector<Type> & mv);
        void reverse();
        void insert(Type * it, const Type & value);
        void insert(Type * it1, Type * it2, Type * it3);
        void erase(Type * it);
        void erase(Type * it1, Type * it2);
        void erase(const Iterator<Type> & it1, Type * it2);
        void erase(Type * it1, const Iterator<Type> & it2);
    public:
        friend std::ostream & operator<<(std::ostream & os, const myVector & mv)
        {
            return mv.out(os);
        }
        friend bool operator !=(Type * it, const Iterator<Type> & it2)
        {
            myVector<Type>::Iterator<Type> IT(it);
            return IT != it2;
        }

    private:
        int _capacity = 1;
        int _size = 0;
        Type * _array = nullptr;
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
    };
    

    // Vector
    template <typename Type>
    myVector<Type>::myVector()
    {
        _array = new Type[_capacity];
    }

    template <typename Type>
    myVector<Type>::~myVector() 
    {
        delete [] _array;
    }

    template <typename Type>
    myVector<Type>::myVector(Type size) : _size(size), _capacity(size)
    {
        _array = new Type[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _array[i] = 0;
        }
    }

    template <typename Type>
    int myVector<Type>::size() const
    {
        return _size;
    }

    template <typename Type>
    int myVector<Type>::capacity() const
    {
        return _capacity;
    }

    template <typename Type>
    Type & myVector<Type>::operator[](Type & index)
    {
        return _array[index];
    }

    template <typename Type>
    bool myVector<Type>::isEmpty() const
    {
        return _size == 0;
    }

    template <typename Type>
    const Type & myVector<Type>::operator[](Type & index) const
    {
        return _array[index];
    }

    template <typename Type>
    myVector<Type>::Iterator<Type> myVector<Type>::begin() 
    {
        return Iterator<Type> (_array);
    }

    template <typename Type>
    myVector<Type>::Iterator<Type> myVector<Type>::end() 
    {
        return Iterator<Type> (_array + _size);
    }

    template <typename Type>
    Type & myVector<Type>::operator*()
    {
        return *_array;
    }

    template <typename Type>
    const Type & myVector<Type>::operator*() const
    {
        return *_array;
    }

    template <typename Type>
    Type * myVector<Type>::operator+(Type index)
    {
        return _array + index;
    }

    template <typename Type>
    void myVector<Type>::push_back(const Type & value)
    {
        if (_capacity <= _size)
        {
            reallocationMemory();
        }
        _array[_size] = value;
        ++_size;
    }

    template <typename Type>
    void myVector<Type>::push_front(const Type & value)
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

    template <typename Type>
    void myVector<Type>::pop_back()
    {
        if(!isEmpty())
        {
            --_size;
            clearMemory();
        }
    }

    template <typename Type>
    void myVector<Type>::pop_front()
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

    template <typename Type>
    void myVector<Type>::clear()
    {
        while (!isEmpty())
        {
            this->pop_back();
        }
    }

    template <typename Type>
    void myVector<Type>::swap(myVector<Type> & mv)
    {
        myVector<Type> temp = mv;
        mv = *this;
        *this = temp;
    }

    template <typename Type>
    void myVector<Type>::reverse()
    {
        for (int i = 0, j = _size - 1; i < j; i++, j--)
        {
            Type temp = _array[i];
            _array[i] = _array[j];
            _array[j] = temp;
        }
    }

    template <typename Type>
    void myVector<Type>::Show()
    {
        for (int i = 0; i < _size; i++)
        {
            std::cout << _array[i] << ' ';
        }
    }

    template <typename Type>
    void myVector<Type>::reallocationMemory()
    {
        _capacity *= 2;
        Type * temp = _array;
        _array = new Type[_capacity];
        for (int i = 0; i < _size; i++)
        {
            _array[i] = temp[i];
        }
        delete temp;
    }

    template <typename Type>
    void myVector<Type>::insert(Type * it, const Type & value)
    {
        MyV::myVector<Type>::Iterator<Type> now = it;
        if (!isEmpty())
        {
            if (_capacity <= _size)
            {
                reallocationMemory();
            }
            ++_size;
            for (auto it = end(); it != now; --it)
            {
                *it = *(it - 1);
            }
            *(now + 1) = value;
        }
        else
        {
            push_back(value);
        }
    }

    template <typename Type>
    void myVector<Type>::insert(Type * it1, Type * it2, Type * it3)
    {
        
        Iterator<Type> It_2(it2);
        Iterator<Type> It_3(it3);

        Iterator<Type> START(it1);
        if (!isEmpty())
        {
            if (_capacity <= _size)
            {
                reallocationMemory();
            }
            while (It_2 != It_3)
            {
                ++_size;
                for (auto it = end(); it != START; --it)
                {
                    *it = *(it - 1);
                }
                --It_3;
                *(START) = *It_3;
            }
        }
        else
        {
            while (It_2 != It_3)
            {
                push_back(*It_2);
                It_2++;
            }
        }
    }

    template <typename Type>
    void myVector<Type>::erase(Type * it)
    {
        Iterator<Type> IT_1(it);
        for (auto it = IT_1 + 1; it != end(); it++)
        {
            *(it - 1) = *it;
            if (!(it != end()))
            {
                throw "NOOO!\n";
            }
            
        }
        clearMemory();
        --_size;
        
    }

    template <typename Type>
    void myVector<Type>::erase(Type * it1, Type * it2)
    {
        Iterator<Type> IT_1(it1);
        Iterator<Type> IT_2(it2);
        while (IT_1 != IT_2)
        {
            for (auto it = IT_1 + 1; it != end(); it++)
            {
                if (!(it != end()))
                {
                    throw "NOOO!\n";
                }
                *(it - 1) = *it;
            }
            clearMemory();
            --_size;
            --IT_2;
        }
    }

    template <typename Type>
    void myVector<Type>::erase(const Iterator<Type> & it1, Type * it2)
    {
        Iterator<Type>IT_2(it2);
        Iterator<Type> IT_1(it1);
        while (IT_1 != IT_2)
        {
            for (auto it = IT_1 + 1; it != end(); it++)
            {
                if (!(it != end()))
                {
                    throw "NOOO!\n";
                }
                *(it - 1) = *it;
            }
            clearMemory();
            --_size;
            --IT_2;
        }
    }

    template <typename Type>
    void myVector<Type>::erase(Type * it1, const Iterator<Type> & it2)
    {
        Iterator<Type>IT_2(it2);
        Iterator<Type> IT_1(it1);
        while (IT_1 != IT_2)
        {
            for (auto it = IT_1 + 1; it != end(); it++)
            {
                if (!(it != end()))
                {
                    throw "EXPECTED\n";
                }
                
                *(it - 1) = *it;
            }
            clearMemory();
            --_size;
            --IT_2;
        }
    }

    template <typename Type>
    myVector<Type>::myVector(const myVector<Type> & mv)
    {
        _array = new Type[mv._capacity];
        _size = mv._size;
        _capacity = _capacity;
        for (int i = 0; i < _size; i++)
        {
            _array[i] = mv._array[i];
        }
    }

    template <typename Type>
    myVector<Type> & myVector<Type>::operator=(const myVector & mv)
    {
        if (this == &mv)
        {
            return *this;
        }
        delete [] _array;
        _array = new Type[mv._capacity];
        _size = mv._size;
        _capacity = _capacity;
        for (int i = 0; i < _size; i++)
        {
            _array[i] = mv._array[i];
        }
        return *this;
    }

    template <typename Type>
    myVector<Type>::myVector(myVector<Type> && mv) noexcept 
    : _array(mv._array)
    , _size(mv._size)
    , _capacity(mv._capacity)
    {
        mv._array = nullptr;
    }

    template <typename Type>
    myVector<Type> & myVector<Type>::operator=(myVector<Type> && mv) noexcept
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
    template <typename Type>
    template <typename T>
    myVector<Type>::Iterator<T>::Iterator(T * t) : type(t)
    {
    }
    
    template <typename Type>
    template <typename T>
    myVector<Type>::myVector::Iterator<T>::~Iterator()
    {
    }

    template <typename Type>
    template <typename T>
    myVector<Type>::Iterator<T> & myVector<Type>::Iterator<T>::operator=(const Iterator & other)
    {
        if (this != &other)
        {
            type = other.type;
        }
        return *this;
    }

    template <typename Type>
    template <typename T>
    T * myVector<Type>::Iterator<T>::operator++()
    {
        ++type;
        return type;
    }

    template <typename Type>
    template <typename T>
    T * myVector<Type>::Iterator<T>::operator++(int i)
    {
        T * temp(type);
        ++type;
        return temp;
    }

    template <typename Type>
    template <typename T>
    T & myVector<Type>::Iterator<T>::operator*()
    {
        return *type;
    }

    template <typename Type>
    template <typename T>
    T* myVector<Type>::Iterator<T>::operator->()
    {
        return type;
    }

    template <typename Type>
    template <typename T>
    T * myVector<Type>::Iterator<T>::operator+(int index)
    {
        return type + index;
    }

    template <typename Type>
    template <typename T>
    bool myVector<Type>::Iterator<T>::operator==(const Iterator & other)
    {
        return type == other.type;
    }

    template <typename Type>
    template <typename T>
    bool myVector<Type>::Iterator<T>::operator!=(const Iterator & other)
    {
        return !(*this == other);
    }

    template <typename Type>
    template <typename T>
    T * myVector<Type>::Iterator<T>::operator--()
    {
        --type;
        return type;
    }

    template <typename Type>
    template <typename T>
    T * myVector<Type>::Iterator<T>::operator-(int index)
    {
        return type - index;
    }
}

#include <vector>
int main()
{
    
    MyV::myVector<double> a1;
    a1.push_back(13.5);
    a1.push_back(323.31);
    a1.push_back(123.131);
	
    for (auto i = a1.begin(); i != a1.end(); i++)
    {
        std::cout << *i << ' ';
    }
	std::cin.get();
    return 0;
}