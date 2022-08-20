#include <iostream>

struct Node;
template <typename Type>
class MyList
{
public:
	class Iterator
	{
	public:
		Iterator(Node * node) : myNode(node) {}
		bool operator!=(const Iterator& it) { return myNode != it.myNode; }
		Iterator& operator++() { myNode = myNode->next; return *this; }
		Type& operator*() { return myNode->data; }
	private:
		Node* myNode;
	};
public:
	MyList() : head(nullptr), tail(nullptr), size(0) {}
	void push_back(const Type& value);
	void push_front(const Type& value);
	void pop_back();
	void pop_front();
	void Remove(const Type& value);
	void Reverse();

	MyList(const MyList& otherList);
	MyList& operator=(const MyList& otherList);
	MyList(MyList&& otherList) noexcept;
	MyList& operator=(MyList&& otherList) noexcept;

	Iterator Begin();
	Iterator End();

	Type& front();
	const Type& front() const;
	Type& back();
	const Type& back() const;
	
	bool isEmpry() const;
	bool find(const Type& value);
	void clear();
	int Size() const;
private:
	struct Node
	{
		Type data;
		Node* previos;
		Node* next;
	};
private:
	Node* head;
	Node* tail;
	int size;
};

template <typename Type>
typename MyList<Type>::Iterator MyList<Type>::Begin()
{
	Iterator Start(head);
	return Start;
}

template <typename Type>
typename MyList<Type>::Iterator MyList<Type>::End()
{
	Iterator Finish(tail->next);
	return Finish;
}

template <typename Type>
void MyList<Type>::push_back(const Type& value)
{
	if (head == nullptr)
	{
		head = new Node{ value, nullptr, nullptr };
		tail = head;
	}
	else
	{
		tail->next = new Node{ value, tail, nullptr };
		tail = tail->next;
	}

	size++;
}

template <typename Type>
void MyList<Type>::push_front(const Type& value)
{
	if (head == nullptr)
	{
		head = new Node{ value, nullptr, nullptr };
		tail = head;
	}
	else
	{
		head->previos = new Node{ value, nullptr, head };
		head = head->previos;
	}
	size++;
}

template <typename Type>
void MyList<Type>::pop_back()
{
	if (head == nullptr)
	{
		return;
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* current_tail = tail;
		tail = tail->previos;
		tail->next = nullptr;
		delete current_tail;
	}
	size--;
}

template <typename Type>
void MyList<Type>::pop_front()
{
	if (head == nullptr)
	{
		return;
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* current_head = head;
		head = head->next;
		head->previos = nullptr;
		delete current_head;
	}
	size--;
}

template <typename Type>
void MyList<Type>::clear()
{
	if (size > 0)
	{
		while (head != nullptr)
		{
			Node* current = head;
			head = head->next;
			delete current;
			size--;
		}
		tail = nullptr;
	}
}

template <typename Type>
int MyList<Type>::Size() const
{
	return size;
}

template <typename Type>
bool MyList<Type>::isEmpry() const
{
	return size == 0;
}

template <typename Type>
Type& MyList<Type>::front()
{
	return head->data;
}

template <typename Type>
const Type& MyList<Type>::front() const
{
	return head->data;
}

template <typename Type>
Type& MyList<Type>::back()
{
	return tail->data;
}

template <typename Type>
const Type& MyList<Type>::back() const
{
	return tail->data;
}

template <typename Type>
bool MyList<Type>::find(const Type& value)
{
	if (size > 0)
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->data == value)
			{
				return true;
			}
			current = current->next;
		}
	}
	return false;
}

template <typename Type>
MyList<Type>::MyList(const MyList& otherList)
	: head(nullptr), tail(nullptr), size(0)
{
	if (this != &otherList && otherList.size > 0)
	{
		head = new Node{ otherList.head->data, nullptr, nullptr };

		Node* current = head;
		Node* currentOtherList = otherList.head->next;

		while (currentOtherList != nullptr)
		{
			current->next = new Node{ currentOtherList->data, current, nullptr };
			current = current->next;
			currentOtherList = currentOtherList->next;
		}
		tail = current;
		size = otherList.size;
	}
}

template <typename Type>
MyList<Type>& MyList<Type>::operator=(const MyList& otherList)
{
	if (this != &otherList && otherList.size > 0)
	{
		clear();

		head = new Node{ otherList.head->data, nullptr, nullptr };

		Node* current = head;
		Node* currentOtherList = otherList.head->next;

		while (currentOtherList != nullptr)
		{
			current->next = new Node{ currentOtherList->data, current, nullptr };
			current = current->next;
			currentOtherList = currentOtherList->next;
		}
		tail = current;
		size = otherList.size;
	}
	return *this;
}

template <typename Type>
MyList<Type>::MyList(MyList&& otherList) noexcept
	: head(otherList.head), tail(otherList.tail), size(otherList.size) 
{
	otherList.head = nullptr;
	otherList.tail = nullptr;
	otherList.size = 0;
}

template <typename Type>
MyList<Type>& MyList<Type>::operator=(MyList&& otherList) noexcept
{
	if (this != &otherList)
	{
		clear();

		head = otherList.head;
		tail = otherList.tail;
		size = otherList.size;

		otherList.head = nullptr;
		otherList.tail = nullptr;
		otherList.size = 0;
	}
	return *this;
}

template <typename Type>
void MyList<Type>::Remove(const Type& value)
{
	if (size > 0)
	{
		if (head->next == nullptr)
		{
			if (head->data == value)
			{
				pop_back();
			}
		}
		else
		{
			Node* current = head;
			while (current != nullptr)
			{
				if (current->data == value)
				{
					if (current == head)
					{
						pop_front();
						return;
					}
					else if (current == tail)
					{
						pop_back();
						return;
					}
					else
					{
						current->next->previos = current->previos;
						current->previos->next = current->next;
						delete current;
						size--;
						return;
					}
					
				}
				current = current->next;
			}
		}
		
	}
	else
	{
		std::cout << "Error: List is empty\n";
	}
}

template <typename Type>
void MyList<Type>::Reverse()
{
	if (size > 1)
	{
		tail = head;
		Node* current = head;
		Node* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->previos;
			current->previos = current->next;
			current->next = temp;
			current = current->previos;
		}
		if (temp != nullptr)
		{
			head = temp->previos;
		}
	}
	else
	{
		std::cout << "List has 1 element\n";
	}
}

int main()
{
	MyList<double> list1;
	for (double i = 0.5; i <= 15; i += 0.7)
	{
		list1.push_back(i);
	}


	for (auto i = list1.Begin(); i != list1.End(); ++i)
	{
		std::cout << *i << ' ';
	}

	std::cout << std::endl;
	return 0;
}