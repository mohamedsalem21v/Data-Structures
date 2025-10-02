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
class MyStack
{
public:
    Node<T> *top;
    MyStack()
    {
        top = nullptr;
    }

    bool empty()
    {
        return (top == nullptr);
    }

    bool found(T item)
    {
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            if (temp->data == item)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void push(T item)
    {
        Node<T> *newnode = new Node<T>();
        newnode->data = item;
        newnode->next = top;
        top = newnode; 
    }

    void pop()
    {
        if (empty())
            return void(cout << "The stack is empty." << endl);
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }

    T peek()
    {
        return top->data;
    }

    void display()
    {
        Node<T> *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    MyStack<int> st;    
    return 0;
}
