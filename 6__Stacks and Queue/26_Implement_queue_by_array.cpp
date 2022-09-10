#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Queue
{
    int *arr;
    int size;
    int front, rear;

public:
    // costructor
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // Enqueue
    void enqueue(int data)
    {
        if (rear == size)
            cout << "Queue is Full \n";
        else
            arr[rear] = data;
        rear++;
    }

    // Dequeue
    void dequeue()
    {
        if (front == rear)
        {
            cout << "-1\n";
        }
        else
        {
            cout << arr[front] << endl;
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    // Front
    void frontQ()
    {
        if (front == rear)
            cout << "-1\n";
        else
            cout << arr[front] << endl;
    }

    // Empty
    void isEmpty()
    {
        if (front == rear)
            cout << "True\n";
        else
            cout << "False\n";
    }
};

int main()
{
    Queue st(5);
    st.enqueue(1);
    st.enqueue(2);
    // st.enqueue(3);
    // st.enqueue(4);
    // st.enqueue(5);
    // st.enqueue(6);
    st.frontQ();
    st.isEmpty();

    st.dequeue();
    st.dequeue();
    st.isEmpty();

    st.frontQ();
    return 0;
}