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

Node *ReverseGroup(Node *head, int k)
{
    // base case
    if (head == NULL)
        return NULL;

    // step 1 reverse first k nodes
    Node *cur = head;
    Node *pr = NULL;
    Node *temp = NULL;
    int count = 0;
    while (cur != NULL && count < k)
    {
        temp = cur->next;
        cur->next = pr;
        cur->prev = temp;
        pr = cur;
        cur = temp;
        count++;
    }

    // step 2 call recursive function for remaining
    head->next = ReverseGroup(temp, k);

    // step 3 return the reversed new Head stored in prev pointer
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
    head = ReverseGroup(head, 4);
    printlist(head);

    return 0;
}
