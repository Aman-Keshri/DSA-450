#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertNode(Node *&tail, int value, int data)
{
    Node *temp = new Node(data);

    if (tail == NULL)
    {
        tail = temp;
        temp->next = temp;
    }

    else
    {
        Node *cur = tail;

        while (cur->data != value)
        {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
    }
}

void DeleteNode(Node *&tail, int value)
{
    if (tail == NULL)
        cout << "list empty\n";

    else
    {
        Node *prev = tail;
        Node *cur = prev->next;

        while (cur->data != value)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;

        if (cur == prev)
            tail = NULL;

        else if (tail == cur)
            tail = prev;

        cur->next = NULL;
        delete (cur);
    }
}

void printlist(Node *tail)
{
    if (tail == NULL)
        cout << "List is empty\n";
    else
    {
        Node *p = tail;
        do
        {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != p);
        cout << endl;
    }
}

int main()
{
    Node *tail = NULL;
    InsertNode(tail, 3, 5);
    printlist(tail);

    InsertNode(tail, 5, 10);
    printlist(tail);

    InsertNode(tail, 10, 15);
    printlist(tail);

    InsertNode(tail, 5, 20);
    printlist(tail);

    InsertNode(tail, 10, 25);
    printlist(tail);

    DeleteNode(tail, 5);
    printlist(tail);
    return 0;
}