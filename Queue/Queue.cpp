#include <bits/stdc++.h>
#define sp " "
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
};

class MyQueue
{
public:
    Node *front;
    Node *rear;
    int sz;

    MyQueue()
    {
        front = nullptr;
        rear = nullptr;
        sz = 0;
    }

    bool empty()
    {
        return (sz == 0);
    }

    bool found(int value)
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int count()
    {
        Node *temp = front;
        int counter = 0;
        while (temp != nullptr)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void EnQueue(int value)
    {
        Node *newnode = new Node();
        newnode->data = value;
        if (empty())
            front = rear = newnode;
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        sz++;
    }

    void DeQueue()
    {
        Node *temp = front;
        if (empty())
            return void(cout << "The queue is empty.\n");
        front = front->next;
        delete temp;
        sz--;
        if (front == nullptr)
            rear = nullptr;
    }

    void display()
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    MyQueue q;
    q.EnQueue(10);
    q.EnQueue(20);
    q.display();
    q.DeQueue();
    q.display();

    return 0;
}