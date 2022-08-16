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

Node *detectCycle(Node *head)
{
    Node *slow = head, *fast = head, *start = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            while (slow != start)
            {
                slow = slow->next;
                start = start->next;
            }
            return start;
        }
    }
    return NULL;
}

Node *deleteLoopI(Node *head)
{
    if (head == NULL)
        return head;

    Node *startLoop = detectCycle(head);
    Node *temp = startLoop;

    while (temp->next != startLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}

Node *deleteLoop(Node *head)
{
    if (head == NULL)
        return head;

    else if (head->next == head)
    {
        head->next = NULL;
        return head;
    }

    Node *slow = head, *fast = head;

    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;
            Node *prev = NULL;
            while (slow != fast)
            {
                slow = slow->next;
                prev = fast;
                fast = fast->next;
            }
            prev->next = NULL;
        }
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

    // made the list circular
    head->next->next->next->next->next->next->next = head->next->next;

    cout << "Answer is \n";
    Node *temp = deleteLoopI(head);
    printlist(temp);

    return 0;
}