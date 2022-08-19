#include <iostream>
namespace FW
{
    // My Forward List
    template <typename Type>
    class forward_list
    {
    private:
        struct Node
        {
            Type data;
            Node* next;
        };
    public:
        // Iterator for my List
        class Iterator
        {
        public:
            Iterator(Node* newNode);
            bool operator!=(const Iterator& other);
            Iterator& operator++();
            Iterator& operator++(int);
            Type& operator*();
        private:
            Node* node;
        };

    public:
        //
        Iterator begin();
        Iterator end();
        //
        forward_list();
        ~forward_list();
        void clear();
        void push_back(const Type& value);
        void push_front(const Type& value);
        void pop_back();
        void pop_front();
        bool find(const Type& value);
        void remove(const Type& value);
        bool isEmpty() const;
        int size() const;

        forward_list(const forward_list& fw);
        forward_list(forward_list&& fw) noexcept;

        forward_list& operator=(const forward_list& fw);
        forward_list& operator=(forward_list&& fw) noexcept;

    private:
        
        Node * head;
        Node * tail;
    };

    // myForwardList realisation
    template <typename Type>
    void forward_list<Type>::clear()
    {
        Node * temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;

            delete temp;
        }
        
    }

 
    template <typename Type>
    forward_list<Type>::forward_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    template <typename Type>
    forward_list<Type>::~forward_list()
    {
        clear();
    }

    template <typename Type>
    void forward_list<Type>::push_back(const Type& value)
    {
        if (tail == nullptr)
        {
            head = new Node{value, nullptr};
            tail = head;
        }
        else
        {
            tail->next = new Node{value, nullptr};
            tail = tail->next;
        }
    }

    template <typename Type>
    void forward_list<Type>::push_front(const Type& value)
    {
        if (head == nullptr)
        {
            head = new Node{value, nullptr};
            tail = head;
        }
        else
        {
            Node * temp = new Node{value, head};
            head = temp;
        }
    }

    template <typename Type>
    void forward_list<Type>::pop_back()
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
            Node * previos = head;
            Node * current = head;
            while (current->next != nullptr)
            {
                previos = current;
                current = current->next;
            }
            tail = previos;
            delete current;
            tail->next = nullptr;
        }
    }

    template <typename Type>
    void forward_list<Type>::pop_front()
    {
        if (head == nullptr)
        {
            return;
        }
        else if (head->next == nullptr)
        {
            delete head;
            tail = nullptr;
        }
        else
        {
            Node * temp = head;
            head = head->next;
            delete temp;
        }
    }

    template <typename Type>
    bool forward_list<Type>::find(const Type& value)
    {
        if (head == nullptr)
        {
            return false;
        }
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    template <typename Type>
    void forward_list<Type>::remove(const Type& value)
    {
        Node* previos = nullptr;
        Node* current = head;
        while (current != nullptr)
        {
            if (current->data == value)
            {
                if (previos == nullptr)
                {
                    head = head->next;
                }
                else
                {
                    previos->next = current->next;
                }
                delete current;
                return;
            }
            previos = current;
            current = current->next;
        }
    }

    template <typename Type>
    bool forward_list<Type>::isEmpty() const
    {
        return head == nullptr;
    }

    template <typename Type>
    int forward_list<Type>::size() const
    {
        int count = 0;
        Node* current = head;
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    template <typename Type>
    forward_list<Type>::forward_list(const forward_list<Type>& fw)
    {
        if (fw.head == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = new Node{ fw.head->data, nullptr };

            Node* current = head;
            Node* fwCurrent = fw.head;

            while (fwCurrent->next != nullptr)
            {
                current->next = new Node{ fwCurrent->next->data, nullptr };
                current = current->next;
                fwCurrent = fwCurrent->next;
            }
            tail = current;
        }
    }

    template <typename Type>
    forward_list<Type>& forward_list<Type>::operator=(const forward_list<Type>& fw)
    {
        if (this != &fw)
        {
            clear();
            if (fw.head == nullptr)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = new Node{ fw.head->data, nullptr };

                Node* current = head;
                Node* fwCurrent = fw.head;

                while (fwCurrent->next != nullptr)
                {
                    current->next = new Node{ fwCurrent->next->data, nullptr };
                    current = current->next;
                    fwCurrent = fwCurrent->next;
                }
                tail = current;
            }
        }

        return *this;
    }

    template <typename Type>
    forward_list<Type>::forward_list(forward_list<Type>&& fw) noexcept
        : head(fw.head), tail(fw.tail)
    {
        fw.head = nullptr;
        fw.tail = nullptr;
    }
    
    template <typename Type>
    forward_list<Type>& forward_list<Type>::operator=(forward_list<Type>&& fw) noexcept
    {
        if (this != &fw)
        {
            clear();
            head = fw.head;
            tail = fw.tail;
            fw.head = nullptr;
            fw.tail = nullptr;
        }
        return *this;
    }

    template <typename Type>
    typename forward_list<Type>::Iterator forward_list<Type>::begin()
    {
        Iterator StartIt(head);
        return StartIt;
    }

    template <typename Type>
    typename forward_list<Type>::Iterator forward_list<Type>::end()
    {
        Iterator EndIt(tail->next);
        return EndIt;
    }


    // Irerator realisation

    template <typename Type>
    forward_list<Type>::Iterator::Iterator(Node* newNode) : node(newNode)
    {
    }

    template <typename Type>
    typename bool forward_list<Type>::Iterator::operator!=(const Iterator& other)
    {
        return node != other.node;
    }

    template <typename Type>
    typename forward_list<Type>::Iterator& forward_list<Type>::Iterator::operator++()
    {
        node = node->next;
        return *this;
    }

    template <typename Type>
    typename forward_list<Type>::Iterator& forward_list<Type>::Iterator::operator++(int)
    {
        Iterator temp(*this);
        node = node->next;
        return temp;
    }

    template <typename Type>
    typename Type& forward_list<Type>::Iterator::operator*()
    {
        return node->data;
    }
}

int main()
{
    FW::forward_list<int> list3;

    for (int i = 0; i < 5; i++)
    {
        list3.push_back(i + 15);
        
    }
    
    for (auto i = list3.begin(); i != list3.end(); ++i)
    {
        *i += 8.13;
        std::cout << *i << ' ';
    }

    return 0;
}