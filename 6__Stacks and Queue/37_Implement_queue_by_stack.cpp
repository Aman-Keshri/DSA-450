// CPP program to implement Queue using
// two stacks with costly enQueue()
#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty())
            return -1;
        else
        {
            int tp = s1.top();
            s1.pop();
            return tp;
        }
    }
};

struct Queue1
{
    stack<int> input, output;

    void enQueue(int data)
    {
        input.push(data);
    }

    int deQueue()
    {
        int data;
        if (!output.empty())
        {
            data = output.top();
            output.pop();
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            data = output.top();
            output.pop();
        }

        return data;
    }

    int top()
    {
        if (!output.empty())
        {
            return output.top();
        }
        else
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }

            return output.top();
        }
    }
};

// Driver code
int main()
{
    // Queue q;
    // q.enQueue(1);
    // q.enQueue(2);
    // q.enQueue(3);

    // cout << q.deQueue() << '\n';
    // cout << q.deQueue() << '\n';
    // cout << q.deQueue() << '\n';

    // Queue 1
    Queue1 q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.top() << '\n';

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.top() << '\n';
    cout << q.deQueue() << '\n';
    return 0;
}
