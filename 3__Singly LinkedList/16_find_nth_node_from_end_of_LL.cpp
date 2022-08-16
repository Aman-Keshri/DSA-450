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

void nthnodefromEnd(Node *head, int n)
{
    int count = 0;
    Node *p = head;
    while (p != NULL)
    {
        ++count;
        p = p->next;
    }
    cout << count << "  " << n << endl;

    p = head;
    int cur = 0;
    while (cur < (count - n))
    {
        cur++;
        p = p->next;
    }
    cout << p->data << endl;
}

void nthnodefromEndI(Node *head, int n)
{
    Node *temp = new Node(-1);

    temp->next = head;
    Node *slow = temp;
    Node *fast = temp;

    for (int i = 0; i <= n; i++)
        fast = fast->next;

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    cout << slow->next->data;
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
    nthnodefromEndI(head, 2);
    return 0;
}