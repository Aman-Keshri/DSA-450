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
        front = -1;
        rear = -1;
    }

    // Enqueue
    void enqueue(int data)
    {
        cout << "Rear " << rear << endl;
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            cout << "Queue is Full\n";

        else if (front == -1)
            front = rear = 0;
        else if (rear == size - 1 && front != 0)
            rear = 0;
        else
            rear++;
        cout << "Rear value insert at " << rear << endl;
        arr[rear] = data;
    }

    // Dequeue
    void dequeue()
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

        cout << pp << endl;
    }

    // Front
    void frontQ()
    {
        if (front == -1)
            cout << "Queue is Empty\n";
        else
            cout << "front " << arr[front] << endl;
        cout << "rear " << arr[rear] << endl;
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

class MyCircularQueue
{

    int *arr;
    int k;
    int front, rear;

public:
    MyCircularQueue(int k)
    {
        this->k = k;
        arr = new int[k];
        front = -1;
        rear = -1;
    }

    bool enQueue(int data)
    {
        if ((front == 0 && rear == k - 1) || (rear < front) && (rear == (front - 1) % (k - 1)))
        {
            return false;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == k - 1 && front != 0)
        {
            rear = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            rear++;
        }
        // push inside the queue

        arr[rear] = data;
        return true;
    }

    bool deQueue()
    {
        if (front == -1)
        { // to check queue is empty
            return false;
        }
        arr[front] = -1;

        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (front == k - 1)
        {
            front = 0; // to maintain cyclic nature
        }
        else
        { // normal flow
            front++;
        }
        return true;
    }

    int Front()
    {
        if (front == -1)
            return -1;
        else
            return arr[front];
    }

    int Rear()
    {
        if (rear == -1)
            return -1;
        else
            return arr[rear];
    }

    bool isEmpty()
    {
        if (rear == -1 || front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if ((front == 0 && rear == k - 1) || (rear == (front - 1) % (k - 1)))
            return true;
        else
            return false;
    }
};

int main()
{
    Queue st(2);
    // st.enqueue(1);
    // st.enqueue(2);
    // st.enqueue(3);
    // // st.enqueue(4);
    // // st.enqueue(5);
    // st.frontQ();
    // st.dequeue();
    // st.enqueue(6);
    // st.frontQ();
    // st.isEmpty();

    // st.dequeue();
    // st.dequeue();
    // st.isEmpty();

    // st.frontQ();
    st.enqueue(1);
    st.enqueue(2);
    st.dequeue();
    st.enqueue(3);
    st.dequeue();
    st.enqueue(3);
    st.dequeue();
    st.enqueue(3);
    st.dequeue();
    st.frontQ();
    return 0;
}