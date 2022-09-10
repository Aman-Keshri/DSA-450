#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *head, *tail;
    int SIZE, count;

    Queue()
    {
        head = tail = NULL;
        SIZE = 5;
        count = 0;
    }

    // member function for performing operation
    // Enqueue
    void Enqueue(int element)
    {
        Node *temp = new Node(element);
        if (count < SIZE)
        {
            if (head == NULL)
            {
                head = temp;
                tail = temp;
                count++;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
                count++;
            }
        }
        else
        {
            cout << "Queue OverFlow !!\n";
        }
    }

    // Dequeue
    void Dequeue()
    {
        if (head == NULL)
            cout << " Stack UnderFlow !!\n";
        else
        {
            cout << head->data << endl;
            Node *temp = head;
            head = head->next;
            delete (temp);
            count--;
        }
    }

    // Front
    void frontQ()
    {
        if (head != NULL)
            cout << "Front of Queue is " << head->data << endl;
        else
            cout << "Queue is Empty\n";
    }

    // Empty
    void isEmpty()
    {
        if (head == NULL)
            cout << "True\n";
        else
            cout << "False\n";
    }
};

int main()
{
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    // q.Enqueue(3);
    // q.Enqueue(4);
    // q.Enqueue(5);
    // q.Enqueue(6);
    q.frontQ();
    q.isEmpty();

    q.Dequeue();
    q.Dequeue();
    q.isEmpty();
    q.frontQ();
    return 0;
}