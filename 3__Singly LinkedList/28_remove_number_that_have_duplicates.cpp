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

Node *removeDuplicate(Node *head)
{
    Node *temp = new Node(-1);
    temp->next = head;
    Node *prev = temp;

    while (head != NULL)
    {
        if (head->next != NULL && (head->data == head->next->data))
        {
            while (head->next != NULL && (head->data == head->next->data))
                head = head->next;
            prev->next = head->next;
        }
        else
            prev = prev->next;

        head = head->next;
    }
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
    InsertatFront(head, 5);
    InsertatFront(head, 4);
    InsertatFront(head, 4);
    InsertatFront(head, 2);
    InsertatFront(head, 2);
    InsertatFront(head, 2);
    InsertatFront(head, 1);
    printlist(head);

    cout << "Answer is \n";
    head = removeDuplicate(head);
    printlist(head);

    return 0;
}