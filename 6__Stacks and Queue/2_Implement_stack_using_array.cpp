#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    // constructor
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }

    // member function for performing operation
    void push(int element)
    {
        if (top < size - 1)
        {
            ++top;
            arr[top] = element;
        }
        else
            cout << "Stack OverFlow !!\n";
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "Under OverFlow !!\n";
    }

    void peek()
    {
        if (top >= 0 && top < size)
            cout << "Top of stack is " << arr[top] << endl;
        else
            cout << "Stack is Empty\n";
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack st(5);
    st.push(1);
    // st.push(2);
    // st.push(3);
    // st.push(4);
    // st.push(5);
    // st.push(6);
    st.peek();
    cout << st.isEmpty() << endl;

    st.pop();
    st.pop();
    cout << st.isEmpty() << endl;
    st.peek();
    return 0;
}