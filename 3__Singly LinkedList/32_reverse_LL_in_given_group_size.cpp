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

Node *ReverseGroup(Node *head, int k)
{
    // base case
    if (head == NULL)
        return NULL;

    // step 1 reverse first k nodes
    Node *cur = head;
    Node *prev = NULL;
    Node *temp = NULL;
    int count = 0;
    while (cur != NULL && count < k)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        count++;
    }

    // step 2 call recursive function for remaining
    head->next = ReverseGroup(temp, k);

    // step 3 return the reversed new Head stored in prev pointer
    return prev;
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

    cout << "Reversed List in k groups is \n";
    head = ReverseGroup(head, 4);
    printlist(head);

    return 0;
}