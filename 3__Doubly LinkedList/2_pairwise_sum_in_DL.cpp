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

void pairSumDL(Node *head, int k)
{
    Node *start = head, *end = head;
    bool status = false;

    while (end->next != NULL)
        end = end->next;

    while (start != end && end->next != start)
    {
        if ((start->data + end->data) == k)
        {
            status = true;
            cout << "Pair is ( " << start->data << " , " << end->data << " )" << endl;
            start = start->next;
            end = end->prev;
        }
        else if ((start->data + end->data) < k)
            start = start->next;

        else
            end = end->prev;
    }
    if (status == false)
        cout << "No pairs present with sum as k\n";
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

    cout << "\nPairs with sum is \n";
    pairSumDL(head, 3);

    return 0;
}