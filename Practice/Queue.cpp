#include <iostream>


class MyQueue
{
public:
	MyQueue(int Size = 10);
	~MyQueue();

	void push_back(const int& value);
	void pop_front();
	void clear();
	void Show();

	bool isEmpty();
	bool isFull();

	int sizeQ();
private:
	struct Node
	{
		int data;
		Node* next;
	};
private:
	Node* head;
	Node* tail;
	int SizeCount;
	int StaticSize;
};

MyQueue::MyQueue(int Size)
{
	head = nullptr;
	tail = nullptr;
	SizeCount = 0;
	StaticSize = Size;
}


MyQueue::~MyQueue()
{
}

void MyQueue::push_back(const int& value)
{
	if (!isFull())
	{
		if (tail == nullptr)
		{
			head = new Node{ value, nullptr };
			tail = head;
			std::cout << "Added in QUEUE " << value << "\n";
		}
		else
		{
			tail->next = new Node{ value, nullptr };
			tail = tail->next;
			std::cout << "Added in QUEUE " << value << "\n";
		}
		SizeCount++;
	}
	else
	{
		std::cout << "Sorry, Queue is full\n";
	}
	
}

void MyQueue::pop_front()
{
	if (!isEmpty())
	{
		if (head == nullptr)
		{
			return;
		}
		else if (head->next == nullptr)
		{
			std::cout << "Remove from QUEUE " << head->data << "\n";
			delete head;
			tail = nullptr;
		}
		else
		{
			std::cout << "Remove from QUEUE " << head->data << "\n";
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		SizeCount--;
	}
	else
	{
		std::cout << "Sorry, Queue already empty\n";
	}
}

int MyQueue::sizeQ()
{
	return SizeCount;
}

bool MyQueue::isEmpty()
{
	return SizeCount == 0;
}

bool MyQueue::isFull()
{
	return SizeCount == StaticSize;
}

void MyQueue::clear()
{
	Node* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;

		delete temp;
		SizeCount--;
	}
}

void MyQueue::Show()
{
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->data << ' ';
		current = current->next;
	}
}

int main()
{

	MyQueue mq;

	for (int i = 0; i < 11; i++)
	{
		mq.push_back(i + 1);
	}
	
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	mq.pop_front();
	return 0;
}