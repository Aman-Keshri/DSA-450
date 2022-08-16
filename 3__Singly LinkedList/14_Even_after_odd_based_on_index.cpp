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

Node *evenafterOdd(Node *head)
{
    Node *temp = head;
    Node *even = new Node(-1);
    Node *evenTail = even;
    Node *odd = new Node(-1);
    Node *oddTail = odd;
    int count = 1;

    while (temp != NULL)
    {
        if (count % 2)
        {
            oddTail->next = temp;
            oddTail = oddTail->next;
            temp = temp->next;
            oddTail->next = NULL;
        }
        else
        {
            evenTail->next = temp;
            evenTail = evenTail->next;
            temp = temp->next;
            evenTail->next = NULL;
        }
        count++;
    }

    oddTail->next = even->next;

    return odd->next;
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
    InsertatFront(head, 3);
    InsertatFront(head, 4);
    InsertatFront(head, 2);
    InsertatFront(head, 1);
    InsertatFront(head, 5);
    InsertatFront(head, 7);
    InsertatFront(head, 6);
    printlist(head);

    cout << "Answer is \n";
    head = evenafterOdd(head);
    printlist(head);

    return 0;
}