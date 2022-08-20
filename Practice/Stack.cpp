#include <iostream>

template <typename Type>
class MyStack
{
public:
	MyStack(Type size = 10);
	~MyStack();
	bool push_back(const Type& value);
	bool pop_back();

	bool isFull();
	bool isEmpty();

	int size();
private:
	Type* element;
	int top;
	int Size;
};

template <typename Type>
MyStack<Type>::MyStack(Type size)
{
	Size = size;
	element = new Type[Size];
	top = 0;
}

template <typename Type>
MyStack<Type>::~MyStack()
{
	delete [] element;
}

template <typename Type>
int MyStack<Type>::size()
{
	return top;
}

template <typename Type>
bool MyStack<Type>::push_back(const Type& value)
{
	if (!isFull())
	{
		element[top++] = value;
		std::cout << value << " added to STACK\n";
		return true;
	}

	std::cout << "Is Full Stack. Can't push back!\n";
	return false;

}

template <typename Type>
bool MyStack<Type>::pop_back()
{
	if (!isEmpty())
	{
		element[top--];
		std::cout << element[top] << " removed from STACK\n";
		return true;
	}
	else
	{
		std::cout << "Stack is empty.\n";
		return false;
	}
}

template <typename Type>
bool MyStack<Type>::isFull()
{
	return top == Size;
}

template <typename Type>
bool MyStack<Type>::isEmpty()
{
	return top == 0;
}



int main()
{
	MyStack<double> MS;

	for (double i = 0.14; i < 2.23; i += 0.15)
	{
		MS.push_back(i);
	}

	std::cout << "size = " << MS.size() << std::endl;

	for (int i = 0; i < 11; i++)
	{
		MS.pop_back();
	}

	std::cout << "size = " << MS.size() << std::endl;
	return 0;
}