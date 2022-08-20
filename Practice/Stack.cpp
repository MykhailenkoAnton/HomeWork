#include <iostream>

class MyStack
{
public:
	MyStack(int size = 10);
	~MyStack();
	bool push_back(const int& value);
	bool pop_back();

	bool isFull();
	bool isEmpty();

	int size();
private:
	int * element;
	int top;
	int Size;
};

MyStack::MyStack(int size)
{
	Size = size;
	element = new int[Size];
	top = 0;
}

MyStack::~MyStack()
{
	delete [] element;
}

int MyStack::size()
{
	return top;
}

bool MyStack::push_back(const int& value)
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

bool MyStack::pop_back()
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

bool MyStack::isFull()
{
	return top == Size;
}

bool MyStack::isEmpty()
{
	return top == 0;
}



int main()
{
	MyStack MS;

	for (int i = 0; i < 11; i++)
	{
		MS.push_back(i + 1);
	}

	std::cout << "size = " << MS.size() << std::endl;

	for (int i = 0; i < 11; i++)
	{
		MS.pop_back();
	}

	std::cout << "size = " << MS.size() << std::endl;
	return 0;
}