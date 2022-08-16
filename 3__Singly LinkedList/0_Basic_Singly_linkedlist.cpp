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

void InsertatBack(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
        head = temp;
    else
    {
        Node *p = head;

        while (p->next)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void InsertatFront(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertatIndex(Node *&head, int index, int data)
{
    Node *temp = new Node(data);
    Node *p = head;
    int count = 1;

    while (p->next && count != index - 1)
    {
        count++;
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void DeletefromIndex(Node *&head, int index)
{

    if (index == 1)
    {
        Node *p = head;
        head = head->next;
        p->next = NULL;
        delete p;
    }
    else
    {
        Node *cur = head;
        Node *prev = NULL;
        int count = 1;
        while (count < index)
        {
            prev = cur;
            cur = cur->next;
            count++;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}

void DeleteusingValue(Node *&head, int data)
{
    if (head->data == data)
    {
        Node *p = head;
        head = head->next;
        p->next = NULL;
        delete p;
    }

    else
    {
        Node *cur = head;
        Node *prev = NULL;

        while (cur->data != data)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}

void printlist(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
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
    DeletefromIndex(head, 7);
    printlist(head);
    cout << "Delete using Value\n";
    DeleteusingValue(head, 25);
    printlist(head);
    return 0;
}