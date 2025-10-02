#include <bits/stdc++.h>
#define sp " "
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
};

template <typename T>
class Linkedlist
{
public:
    Node<T> *head;
    Linkedlist()
    {
        head = nullptr;
    }

    bool empty()
    {
        return (head == nullptr);
    }

    void InsertFirst(int value)
    {
        Node<T> *newnode = new Node<T>();
        newnode->data = value;
        if (empty())
        {
            newnode->next = nullptr;
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << sp;
            temp = temp->next;
        }
    }

    int count()
    {
        Node<T> *temp = head;
        int cnt = 0;
        while (temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    bool found(T key)
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void append(T value)
    {
        Node<T> *newnode = new Node<T>();
        Node<T> *temp = head;
        if (empty())
            InsertFirst(value);
        else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            newnode->data = value;
            temp->next = newnode;
            newnode->next = nullptr;
        }
    }

    void InsertBefore(T newvalue, T item)
    {
        Node<T> *newnode = new Node<T>();
        newnode->data = newvalue;
        Node<T> *temp = head;

        if (found(item))
        {
            while (temp != nullptr and temp->next->data != item)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            return void(cout << "Item not found." << endl);
        }
    }

    void erase(T item)
    {
        if (empty())
            return void(cout << "The linked list is empty." << endl);
        if (!found(item))
            return void(cout << "Not found." << endl);
        Node<T> *prevptr = nullptr;
        Node<T> *delptr = head;
        if (head->data == item)
        {
            head = head->next;
            delete delptr;
        }
        else
        {
            while (delptr->data != item)
            {
                prevptr = delptr;
                delptr = delptr->next;
            }
            prevptr->next = delptr->next;
            delete delptr;
        }
    }
};

int main()
{
    Linkedlist<int> ls;
    return 0;

}
