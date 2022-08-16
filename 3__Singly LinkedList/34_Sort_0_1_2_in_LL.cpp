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

void Sort012_Naive(Node *head)
{
    int C0 = 0, C1 = 0, C2 = 0;
    Node *p = head;

    while (p != NULL)
    {
        if (p->data == 0)
            C0++;
        else if (p->data == 1)
            C1++;
        else
            C2++;

        p = p->next;
    }

    p = head;
    while (p != NULL)
    {
        if (C0 != 0)
        {
            p->data = 0;
            C0--;
        }
        else if (C1 != 0)
        {
            p->data = 1;
            C1--;
        }
        else
        {
            p->data = 2;
            C2--;
        }
        p = p->next;
    }
}

Node *Sort012_DummyLL(Node *head)
{
    // declare 6 pointer 2 each for 0 1 & 2 bcoz - need to create 3 diffrent list for each no.
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *p = head;

    // check each element and assign to respective list of 0 1 or 2
    while (p != NULL)
    {
        int value = p->data;
        if (value == 0)
        {
            zeroTail->next = p;
            zeroTail = zeroTail->next;
        }
        else if (value == 1)
        {
            oneTail->next = p;
            oneTail = oneTail->next;
        }
        else
        {
            twoTail->next = p;
            twoTail = twoTail->next;
        }
        p = p->next;
    }

    // merge 3 list together
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // reassign head to zero's head
    head = zeroHead->next;

    // delete the dummy pointers
    delete (zeroHead);
    delete (oneHead);
    delete (twoHead);

    // return
    return head;
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
    InsertatFront(head, 0);
    InsertatFront(head, 1);
    InsertatFront(head, 2);
    InsertatFront(head, 1);
    InsertatFront(head, 0);
    InsertatFront(head, 2);
    InsertatFront(head, 0);
    printlist(head);

    cout << "Answer is \n";
    // Sort012_Naive(head);
    head = Sort012_DummyLL(head);
    printlist(head);

    return 0;
}