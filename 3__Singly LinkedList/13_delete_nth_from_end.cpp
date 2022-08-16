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

Node *deletenthnodefromEndI(Node *head, int n)
{
    Node *temp = new Node(-1);

    temp->next = head;
    Node *slow = temp;
    Node *fast = temp;

    // make the fast node move ahead by n steps
    for (int i = 0; i <= n; i++)
        fast = fast->next;

    // traverse together to find the (n-1)th node from back
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // assign the next of n-1 node to n+1 node
    slow->next = slow->next->next;

    // return the next of dummy node
    return temp->next;
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
    head = deletenthnodefromEndI(head, 7);
    printlist(head);
    return 0;
}