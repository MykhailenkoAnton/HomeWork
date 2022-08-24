#include <iostream>
#include <string>

template <typename T>
class MyUnPtr
{
public:
	T& operator*();
	T* operator->();
	T* get();

	MyUnPtr(T* ptr);
	MyUnPtr(const MyUnPtr&) = delete;
	MyUnPtr(MyUnPtr&& other) noexcept;
	MyUnPtr& operator=(MyUnPtr&& other) noexcept;
	~MyUnPtr();
	MyUnPtr();

	friend std::ostream& operator<<(std::ostream& os, const MyUnPtr<T>& my);
private:
	T* ptr_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const MyUnPtr<T>& my)
{
	os << my.ptr_;
	return os;
}

template <typename T>
T* MyUnPtr<T>::get()
{
	return ptr_;
}

template <typename T>
MyUnPtr<T>::MyUnPtr() : ptr_(nullptr)
{
}

template <typename T>
MyUnPtr<T>::MyUnPtr(T* ptr) : ptr_(ptr)
{
}

template <typename T>
MyUnPtr<T>::~MyUnPtr()
{
	delete ptr_;
}

template <typename T>
T& MyUnPtr<T>::operator*()
{
	return *ptr_;
}

template <typename T>
T* MyUnPtr<T>::operator->()
{
	return ptr_;
}

template <typename T>
MyUnPtr<T>::MyUnPtr(MyUnPtr<T> && other) noexcept
{
	ptr_ = other.ptr_;
	other.ptr_ = nullptr;
}

template <typename T>
MyUnPtr<T>& MyUnPtr<T>::operator=(MyUnPtr<T>&& other) noexcept
{
	if (this != &other)
	{
		delete ptr_;
		ptr_ = other.ptr_;
		other.ptr_ = nullptr;
	}
	return *this;
}

class A
{
public:
	A() { std::cout << "Const\n"; }
	~A() { std::cout << "Dest\n"; }
	int Get() { return a; }
	void Set(int n) { a = n; }
private:
	int a = 5;
};

int main()
{
	{
		MyUnPtr<A> ptr = new A();

		ptr->Set(13);
		std::cout << ptr->Get() << std::endl;

		MyUnPtr<A> pt1(std::move(ptr));
		
		std::cout << pt1->Get() << std::endl;
	}

	MyUnPtr<int> ptr2 = new int(10);

	if (ptr2.get())
	{
		std::cout << *ptr2 << std::endl;
	}
	else
	{
		std::cout << "not valid\n";
	}
	return 0;
}