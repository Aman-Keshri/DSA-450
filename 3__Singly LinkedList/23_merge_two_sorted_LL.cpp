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

Node *mergetwoSorted(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node *merged = new Node(-1);
    Node *mergedtail = merged;

    Node *p1 = head1;
    Node *p2 = head2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data <= p2->data)
        {
            mergedtail->next = p1;
            mergedtail = mergedtail->next;
            p1 = p1->next;
        }
        else
        {
            mergedtail->next = p2;
            mergedtail = mergedtail->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL)
    {
        mergedtail->next = p1;
        mergedtail = mergedtail->next;
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        mergedtail->next = p2;
        mergedtail = mergedtail->next;
        p2 = p2->next;
    }

    return merged->next;
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
    Node *head1 = NULL, *head2 = NULL;

    cout << "Insert at Front head 1 \n";
    InsertatFront(head1, 26);
    InsertatFront(head1, 17);
    InsertatFront(head1, 12);
    InsertatFront(head1, 8);
    InsertatFront(head1, 6);
    InsertatFront(head1, 3);
    InsertatFront(head1, 1);
    printlist(head1);

    cout << "Insert at Front head 2\n";
    InsertatFront(head2, 25);
    InsertatFront(head2, 15);
    InsertatFront(head2, 10);
    InsertatFront(head2, 9);
    InsertatFront(head2, 5);
    InsertatFront(head2, 4);
    printlist(head2);

    cout << "Answer is \n";
    Node *head = mergetwoSorted(head1, head2);
    printlist(head);

    return 0;
}