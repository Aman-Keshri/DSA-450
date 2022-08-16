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

// flyod's cycle detection algorithm
bool hasCycle(Node *head)
{
    if (head == NULL)
        return false;

    else if (head->next == head)
        return true;

    else if (head->next == NULL)
        return false;

    Node *slow = head, *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
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

    // made the list circular
    head->next->next->next->next->next->next = head->next->next;

    cout << "Linked List has Cycle  " << (hasCycle(head) ? "True\n" : "False\n");

    return 0;
}