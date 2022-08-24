#include <iostream>
typedef unsigned int uint;

template <typename Type>
class shr_ptr
{
public:
	shr_ptr();
	shr_ptr(Type * data);
	~shr_ptr();

	Type& operator*();
	Type* operator->();
	Type* get();

	shr_ptr(const shr_ptr& sp);
	shr_ptr& operator=(const shr_ptr& sp);

	shr_ptr(shr_ptr&& sp) noexcept;
	shr_ptr& operator=(shr_ptr&& sp) noexcept;

	uint GetCount();

private:
	void clean();
private:
	uint* ref_count;
	Type* data_;
};



template <typename Type>
void shr_ptr<Type>::clean()
{
	(*ref_count)--;
	if (*ref_count == 0)
	{
		if (data_ != nullptr)
		{
			delete data_;
		}
		delete ref_count;
	}
}

template <typename Type>
shr_ptr<Type>::shr_ptr() : data_(nullptr), ref_count(new uint(0))
{
}

template <typename Type>
shr_ptr<Type>::shr_ptr(Type* data) : data_(data), ref_count(new uint(1))
{
}

template <typename Type>
shr_ptr<Type>::shr_ptr(const shr_ptr& sp)
{
	data_ = sp.data_;
	ref_count = sp.ref_count;
	if (sp.data_ != nullptr)
	{
		(*ref_count)++;
	}
}

template <typename Type>
shr_ptr<Type>& shr_ptr<Type>::operator=(const shr_ptr& sp)
{
	if (this != &sp)
	{
		clean();
		data_ = sp.data_;
		ref_count = sp.ref_count;
		if (sp.data_ != nullptr)
		{
			(*ref_count)++;
		}
	}

	return *this;
}

template <typename Type>
shr_ptr<Type>::shr_ptr(shr_ptr && sp) noexcept
{
	data_ = sp.data_;
	ref_count = sp.ref_count;

	sp.ref_count = sp.data_ = nullptr;
}

template <typename Type>
shr_ptr<Type>& shr_ptr<Type>::operator=(shr_ptr&& sp) noexcept
{
	if (this != &sp)
	{
		clean();
		data_ = sp.data_;
		ref_count = sp.ref_count;

		sp.data_ = sp.ref_count = nullptr;
	}
	return *this;
}

template <typename Type>
shr_ptr<Type>::~shr_ptr()
{
	clean();
}

template <typename Type>
Type& shr_ptr<Type>::operator*()
{
	return *data_;
}

template <typename Type>
Type* shr_ptr<Type>::operator->()
{
	return data_;
}

template <typename Type>
uint shr_ptr<Type>::GetCount()
{
	return *ref_count;
}

template <typename Type>
Type* shr_ptr<Type>::get()
{
	return data_;
}



class MyClass
{
public:
	MyClass() { std::cout << "Constructor\n"; }
	~MyClass() { std::cout << "Destructor\n"; }
private:
};


int main()
{
	{
		shr_ptr<MyClass> ptr1 = new MyClass();
		{
			shr_ptr<MyClass> ptr2;
			ptr2 = ptr1;

			std::cout << ptr1.get() << std::endl;
			std::cout << ptr2.get() << std::endl;
		}

		
	}
	return 0;
}