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

int findLength(Node *head)
{
    Node *p = head;
    int count = 1;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL)
        return head;
    else
    {
        Node *cur = head, *prev = head;
        int count = 1;
        int len = findLength(head);
        while (cur->next != NULL)
        {
            if (count < len - n - 1)
            {
                count++;
                prev = prev->next;
            }
            cur = cur->next;
        }
        cout << prev->data << "  " << cur->data << endl;
        cur->next = head;
        head = prev->next;
        prev->next = NULL;
    }
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
    InsertatFront(head, 35);
    InsertatFront(head, 45);
    InsertatFront(head, 25);
    InsertatFront(head, 15);
    InsertatFront(head, 55);
    InsertatFront(head, 75);
    InsertatFront(head, 65);
    printlist(head);

    cout << "After append of Last n elements to first\n";
    head = appendLastNToFirst(head, 3);
    printlist(head);

    return 0;
}