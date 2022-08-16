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

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}

Node *deletenodegrateronRight(Node *head)
{
    if (head == NULL)
        return head;

    head = reverseLL(head);

    Node *anshead = new Node(-1);
    Node *anstail = anshead;

    int maxi = head->data;
    Node *temp = head;

    while (temp != NULL)
    {
        maxi = max(maxi, temp->data);
        if (maxi == temp->data)
        {
            anstail->next = temp;
            anstail = anstail->next;
        }
        temp = temp->next;
    }
    anshead->next = reverseLL(anshead->next);

    return anshead->next;
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
    head = deletenodegrateronRight(head);
    printlist(head);

    return 0;
}