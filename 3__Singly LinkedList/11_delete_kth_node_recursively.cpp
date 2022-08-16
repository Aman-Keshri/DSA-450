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

Node *removeElements(Node *&head, int k)
{
    if (head == NULL)
        return NULL;

    if (k == 0)
    {
        Node *temp = head->next;
        delete (head);
        return temp;
    }

    head->next = removeElements(head->next, --k);
    return head;
}

void InsertatBack(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
        head = temp;
    else
    {
        Node *p = head;

        while (p->next)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

void InsertatFront(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertatIndex(Node *&head, int index, int data)
{
    Node *temp = new Node(data);
    Node *p = head;
    int count = 1;

    while (p->next && count != index - 1)
    {
        count++;
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
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

    cout << "Insert at Back\n";
    InsertatBack(head, 15);
    InsertatBack(head, 25);
    printlist(head);
    cout << "Insert at Front\n";
    InsertatFront(head, 35);
    InsertatFront(head, 45);
    printlist(head);
    cout << "Insert at index\n";
    InsertatIndex(head, 3, 65);
    printlist(head);
    InsertatIndex(head, 5, 55);
    printlist(head);
    InsertatIndex(head, 2, 75);
    printlist(head);

    cout << "Remove kth Element  \n";
    head = removeElements(head, 0);
    printlist(head);
    return 0;
}