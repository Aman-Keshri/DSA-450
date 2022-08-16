#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

Node *ReverseDL(Node *head)
{
    Node *pr = NULL, *temp = NULL, *cur = head;

    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = pr;
        cur->prev = temp;
        pr = cur;
        cur = temp;
    }
    return pr;
}

void InsertatFront(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void printlist(Node *&head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    cout << "Insert at Front\n";
    InsertatFront(head, 1);
    InsertatFront(head, 2);
    InsertatFront(head, 3);
    InsertatFront(head, 4);
    InsertatFront(head, 5);
    InsertatFront(head, 6);
    printlist(head);

    cout << "\nReversed List is \n";
    head = ReverseDL(head);
    printlist(head);

    return 0;
}