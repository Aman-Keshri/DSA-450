/* Program to implement a stack using
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack
{
    // Two inbuilt queues
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        if (q1.empty())
            cout << "UnderFlow";

        else
            q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        else
            return q1.front();
    }

    int size()
    {
        return q1.size();
    }
};

class Stack1
{
    queue<int> q;

public:
    void push(int data)
    {
        q.push(data);

        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack under flow\n";
            return;
        }
        else
        {
            cout << q.front() << endl;
            q.pop();
        }
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack under flow\n";
            return -1;
        }
        else
        {
            return q.front();
        }
    }

    int size()
    {
        return q.size();
    }
};

// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size()
         << endl;
    return 0;
}
