#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Stack
{
public:
    int *arr;
    int top1;
    int top2;
    int size;

    // constructor
    Stack(int size)
    {
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
        arr = new int[size];
    }

    // member function for performing operation

    // push in stack 1
    void push1(int element)
    {
        if (top2 - top1 > 1)
        {
            ++top1;
            arr[top1] = element;
        }
        else
            cout << "Stack OverFlow !!\n";
    }

    // pop in stack 1
    void pop1()
    {
        if (top1 >= 0)
            top1--;
        else
            cout << "Under OverFlow !!\n";
    }

    // top in stack 1
    void peek1()
    {
        if (top1 >= 0)
            cout << "Top of stack is " << arr[top1] << endl;
        else
            cout << "Stack is Empty\n";
    }

    // Is stack 1 empty
    bool isEmpty1()
    {
        if (top1 == -1)
            return true;
        else
            return false;
    }

    // 2nd stack
    // push in stack 2
    void push2(int element)
    {
        if (top2 - top1 > 1)
        {
            --top2;
            arr[top2] = element;
        }
        else
            cout << "Stack OverFlow !!\n";
    }

    // pop in stack 2
    void pop2()
    {
        if (top2 < size)
            top2++;
        else
            cout << "Under OverFlow !!\n";
    }

    // top in stack 2
    void peek2()
    {
        if (top2 < size)
            cout << "Top of stack is " << arr[top2] << endl;
        else
            cout << "Stack is Empty\n";
    }

    // Is stack 2 empty
    bool isEmpty2()
    {
        if (top2 == size)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack st(5);
    st.push1(1);
    st.push1(2);
    st.push1(3);

    st.push2(4);
    st.push2(5);
    st.push2(6);
    st.peek1();
    cout << st.isEmpty1() << endl;
    st.pop1();
    st.peek1();
    st.peek2();
    st.pop2();
    cout << st.isEmpty2() << endl;
    st.peek2();

    return 0;
}