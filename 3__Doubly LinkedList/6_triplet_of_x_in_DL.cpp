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

int pairSum(Node *start, Node *end, int x)
{
    int count = 0;
    while (start != NULL && end != NULL && start != end && start->next != end)
    {
        if ((start->data + end->data) == x)
        {
            count++;
            start = start->next;
            end = end->prev;
        }
        else if ((start->data + end->data) < x)
            start = start->next;
        else
            end = end->prev;
    }
    return count;
}

int tripletSumDL(Node *head, int k)
{
    if (head == NULL)
        return 0;

    Node *start = head, *end = head;
    int count = 0;

    while (end->next != NULL)
        end = end->next;

    for (; start != NULL; start = start->next)
    {
        Node *temp = start->next;
        count += pairSum(temp, end, k - start->data);
    }

    return count;
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
    InsertatFront(head, 6);
    InsertatFront(head, 5);
    InsertatFront(head, 4);
    InsertatFront(head, 3);
    InsertatFront(head, 2);
    InsertatFront(head, 1);
    printlist(head);

    cout << "Triplet count is \n";
    int count = tripletSumDL(head, 9);

    if (count != 0)
        cout << "Count of triplet pair is  " << count << endl;
    else
        cout << "No triplet present with sum as k\n";

    return 0;
}