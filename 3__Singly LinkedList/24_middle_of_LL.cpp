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

void MiddleElementI(Node *head)
{
    int len = 1;
    Node *p = head;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    int mid = (len / 2);
    p = head;
    while (--mid)
    {
        p = p->next;
    }
    cout << p->data << endl;
}

void MiddleElementII(Node *head)
{
    Node *fast = head->next, *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
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

    cout << "Middle Element List is  ";
    MiddleElementI(head);

    cout << "Middle Element List is  ";
    MiddleElementII(head);

    return 0;
}