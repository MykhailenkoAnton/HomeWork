#include <iostream>
namespace FW
{
    class forward_list
    {
    public:
        forward_list();
        ~forward_list();
        void clear();
        void push_back(const int & value);
        void push_front(const int & value);
        void pop_back();
        void pop_front();
    public:
        void show() const;
    private:
        struct Node
        {
            int data;
            Node *next;
        };
        Node * head;
        Node * tail;
    };

    void forward_list::clear()
    {
        Node * temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;

            delete temp;
        }
        
    }

    void forward_list::show() const
    {
        Node * temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << ' ';
            temp = temp->next;
        }
        
    }

    forward_list::forward_list()
    {
        head = nullptr;
        tail = nullptr;
    }

    forward_list::~forward_list()
    {
        clear();
    }

    void forward_list::push_back(const int & value)
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

    void forward_list::push_front(const int & value)
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

    void forward_list::pop_back()
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

    void forward_list::pop_front()
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
}

int main()
{
    FW::forward_list list1;

    for (int i = 0; i < 5; i++)
    {
        list1.push_back(i + 1);
    }
    
    list1.show();
    std::cout << std::endl;
    list1.push_front(14);
    list1.show();
    std::cout << std::endl;
    list1.pop_back();
    list1.show();
    std::cout << std::endl;

    list1.pop_front();
    list1.show();
    std::cout << std::endl;
    return 0;
}