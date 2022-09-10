#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class DQueue
{
    int *arr;
    int size;
    int front, rear;

public:
    // costructor
    DQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // push front of Queue
    void push_frontQ(int data)
    {
        if ((front == 0 && rear == size - 1) || rear == (front - 1))
        {
            cout << "Queue is Full\n";
            return;
        }

        else if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = size - 1;
        else
            front--;

        arr[front] = data;
    }

    // push back of Queue
    void push_backQ(int data)
    {
        if ((front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1))
        {
            cout << "Queue is Full\n";
            return;
        }

        else if (front == -1)
            front = rear = 0;
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;
        arr[rear] = data;
    }

    // Pop from front of queue
    void pop_frontQ()
    {
        if (front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        int pp = arr[front];

        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;

        cout << "pop front  " << pp << endl;
    }

    // pop from back of queue
    void pop_backQ()
    {
        if (rear == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        int pp = arr[rear];
        if (front == rear)
            rear = front = -1;
        else if (rear == 0)
            rear = size - 1;
        else
            rear--;

        cout << "pop back  " << pp << endl;
    }

    // Front
    void frontQ()
    {
        if (front == -1)
            cout << "Queue is Empty\n";
        else
            cout << "front  " << arr[front] << endl;
    }

    // Rear
    void rearQ()
    {
        if (rear == -1)
            cout << "Queue is Empty\n";
        else
            cout << "rear  " << arr[rear] << endl;
    }

    // Empty
    void isEmpty()
    {
        if (front == -1)
            cout << "Queue is Empty\n";
        else
            cout << "Queue is not Empty\n";
    }
};

int main()
{
    DQueue st(5);
    st.push_frontQ(1);
    st.push_backQ(2);
    st.push_frontQ(3);
    st.push_frontQ(4);
    st.push_backQ(5);
    st.frontQ();
    st.rearQ();
    st.pop_frontQ();
    st.push_frontQ(6);
    st.pop_backQ();
    st.rearQ();
    st.isEmpty();

    st.pop_frontQ();
    st.pop_backQ();
    st.isEmpty();

    st.frontQ();
    st.rearQ();
    return 0;
}