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

void InsertatBack(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void InsertatIndex(Node *&head, int index, int data)
{
    Node *temp = new Node(data);
    Node *cur = head;
    Node *pr = NULL;
    int count = 1;

    while (count < index)
    {
        count++;
        pr = cur;
        cur = cur->next;
    }
    temp->prev = cur->prev;
    temp->next = cur;
    cur->prev = temp;
    pr->next = temp;
}

void DeletefromIndex(Node *&head, int index)
{
    Node *cur = head;
    Node *pr = NULL;
    int count = 1;

    while (count < index)
    {
        count++;
        pr = cur;
        cur = cur->next;
    }
    // if first element
    if (pr == NULL)
    {
        head = head->next;
        head->prev = NULL;
    }

    // if last element
    else if (cur->next == NULL)
    {
        pr->next = NULL;
    }

    // if mid element
    else
    {
        cur->next->prev = pr;
        pr->next = cur->next;
    }

    cur->prev = cur->next = NULL;
    delete (cur);
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
    cout << "Insert at Back\n";
    InsertatBack(head, 10);
    InsertatBack(head, 15);
    printlist(head);
    cout << "Insert at Front\n";
    InsertatFront(head, 20);
    InsertatFront(head, 25);
    printlist(head);
    cout << "Insert at index\n";
    InsertatIndex(head, 3, 30);
    printlist(head);
    InsertatIndex(head, 5, 35);
    printlist(head);
    InsertatIndex(head, 2, 40);
    printlist(head);
    cout << "Delete using position\n";
    DeletefromIndex(head, 4);
    printlist(head);
    // cout << "Delete using Value\n";
    // DeleteusingValue(head, 25);
    // printlist(head);
    return 0;
}