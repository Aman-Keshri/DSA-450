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

void printReverseIter(Node *head)
{
    stack<int> st;
    Node *p = head;
    while (p != NULL)
    {
        st.push(p->data);
        p = p->next;
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void printReverse(Node *head)
{
    if (head == NULL)
        return;

    printReverse(head->next);
    cout << head->data << " ";
}

void InsertatFront(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printlist(Node *&head)
{
    if (head == NULL)
        cout << "List is empty";
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    cout << "Insert at Front\n";
    InsertatFront(head, 35);
    InsertatFront(head, 45);
    InsertatFront(head, 25);
    InsertatFront(head, 15);
    InsertatFront(head, 55);
    InsertatFront(head, 75);
    InsertatFront(head, 65);
    printlist(head);

    cout << "Reversed List is \n";
    printReverse(head);

    cout << "\nReversed List iterative is \n";
    printReverseIter(head);

    return 0;
}