#include <bits/stdc++.h>
#define sp " "
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev; // Added prev pointer for doubly linked list
    Node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr; // Initialize prev pointer
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
            newnode->prev = nullptr; // No previous node for first element
            head = newnode;
        }
        else
        {
            newnode->next = head;
            newnode->prev = nullptr; // No previous node for first element
            head->prev = newnode;    // Set current head's prev to new node
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
            newnode->prev = temp;    // Set new node's prev to the last node
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
            // Handle the case where item is in the head
            if (head->data == item)
            {
                newnode->next = head;
                newnode->prev = nullptr;
                head->prev = newnode;
                head = newnode;
                return;
            }

            // Find the node with the item
            while (temp != nullptr && temp->data != item)
            {
                temp = temp->next;
            }

            // Insert before the node with the item
            newnode->next = temp;
            newnode->prev = temp->prev;
            temp->prev->next = newnode;
            temp->prev = newnode;
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
        
        Node<T> *delptr = head;

        // Find the node to delete
        while (delptr != nullptr && delptr->data != item)
        {
            delptr = delptr->next;
        }

        // If it's the head node
        if (delptr == head)
        {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr; // Update prev of new head
            delete delptr;
        }
        // If it's the last node
        else if (delptr->next == nullptr)
        {
            delptr->prev->next = nullptr;
            delete delptr;
        }
        // If it's a middle node
        else
        {
            delptr->prev->next = delptr->next;
            delptr->next->prev = delptr->prev;
            delete delptr;
        }
    }

    void reverse()
    {
        Node<T> *current = head;
        Node<T> *temp = nullptr;

        // Swap next and prev pointers for all nodes
        while (current != nullptr)
        {
            // Store the prev pointer
            temp = current->prev;
            
            // Swap next and prev
            current->prev = current->next;
            current->next = temp;
            
            // Move to the next node (which is now pointed by prev)
            current = current->prev;
        }
        
        // Update the head pointer if list is not empty
        if (temp != nullptr)
            head = temp->prev;
    }
};

int main()
{
    Linkedlist<int> ls;
    return 0;
}