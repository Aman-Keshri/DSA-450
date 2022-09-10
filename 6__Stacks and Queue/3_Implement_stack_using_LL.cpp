#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Stack
{
public:
    int data;
    Stack *next;

    // Constructor
    Stack(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Stack *head = NULL;
Stack *tail = head;
int SIZE = 5, top = 0;

// member function for performing operation
void push(int element)
{
    Stack *temp = new Stack(element);
    if (top < SIZE)
    {
        cout << "pushing\n";
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            top++;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
            top++;
        }
    }
    else
    {
        cout << "Stack OverFlow !!\n";
    }
}

void pop()
{
    if (tail == NULL)
        cout << " Stack UnderFlow !!\n";
    else
    {
        cout << "popping\n";
        Stack *prev = head;
        if (head == tail)
        {
            Stack *temp = head;
            head = NULL;
            tail = head;
            delete (temp);
        }
        else
        {
            while (prev->next != tail)
                prev = prev->next;
            tail = prev;
            prev = prev->next;
            tail->next = NULL;
            delete (prev);
        }
    }
}

void peek()
{
    if (tail != NULL)
        cout << "Top of stack is " << tail->data << endl;
    else
        cout << "Stack is Empty\n";
}

bool isEmpty()
{
    if (tail == NULL)
        return true;
    else
        return false;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    peek();
    cout << isEmpty() << endl;

    pop();
    pop();
    cout << isEmpty() << endl;
    peek();
    return 0;
}