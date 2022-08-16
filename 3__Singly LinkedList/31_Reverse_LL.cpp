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

Node *ReverseIter(Node *head)
{
    Node *prev = NULL, *cur = head;
    Node *temp = NULL;

    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

void ReverseRecur(Node *&head, Node *cur, Node *prev)
{
    if (cur == NULL)
    {
        head = prev;
        return;
    }

    Node *temp = cur->next;
    ReverseRecur(head, temp, cur);
    cur->next = prev;
}

Node *Reverse(Node *head)
{
    Node *prev = NULL, *cur = head;
    ReverseRecur(head, cur, prev);
    return head;
}

Node *ReverseRecurI(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = ReverseRecurI(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
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

    cout << "Reversed List Recursive is \n";
    head = Reverse(head);
    printlist(head);

    cout << "\nReversed List iterative is \n";
    head = ReverseIter(head);
    printlist(head);

    cout << "Reversed List Recursive I is \n";
    head = ReverseRecurI(head);
    printlist(head);

    return 0;
}