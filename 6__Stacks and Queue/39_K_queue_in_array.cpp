#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class KQueue
{
public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;
    int size;
    int k;

    // constructor
    KQueue(int s, int kk)
    {
        arr = new int[s];
        next = new int[s];
        front = new int[kk];
        rear = new int[kk];
        freespot = 0;
        size = s;
        k = kk;

        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1;
    }

    void Enqueue(int data, int qn)
    {
        // overflow
        if (freespot == -1)
        {
            cout << "Queue Overflow\n";
            return;
        }

        // find 1st free index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // check whether first element
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        else
        {
            // link new element to the prev element
            next[rear[qn - 1]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    void Dequeue(int qn)
    {
        // underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue Underflow\n";
            return;
        }

        // find the index of front of queue ok given no
        int index = front[qn - 1];

        // increment front to next position
        front[qn - 1] = next[index];

        // add the current freespot to index next
        next[index] = freespot;

        // update the freespot to the index we delete
        freespot = index;

        cout << "popped  " << arr[index] << endl;
    }
};

int main()
{

    KQueue q(10, 3);
    q.Enqueue(10, 1);
    q.Enqueue(15, 1);
    q.Enqueue(20, 2);
    q.Enqueue(25, 1);

    q.Dequeue(1);
    q.Dequeue(2);
    q.Dequeue(1);
    q.Dequeue(2);
    q.Dequeue(1);

    return 0;
}