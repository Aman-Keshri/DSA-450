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

Node *deleteNafterM(Node *head, int m, int n)
{
    if (m == 0)
        return NULL;
    if (n == 0)
        return head;
    // m = skip nodes  n = delete nodes
    Node *temp = head;
    int skip = m, del = n;

    Node *prev = NULL, *cur = head;

    while (temp != NULL)
    {
        if (skip > 0 && cur != NULL)
        {
            temp = temp->next;
            prev = cur;
            cur = cur->next;
            skip--;
            if (skip == 0)
                del = n;
        }
        else
        {
            while (del > 0 && cur != NULL)
            {
                cur = cur->next;
                del--;
                if (del == 0)
                    skip = m;
            }
            if (cur != NULL)
            {
                prev->next = cur;
                temp = cur;
            }
            else
            {
                prev->next = NULL;
                temp = NULL;
            }
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
    InsertatFront(head, 8);
    InsertatFront(head, 7);
    InsertatFront(head, 6);
    InsertatFront(head, 5);
    InsertatFront(head, 4);
    InsertatFront(head, 3);
    InsertatFront(head, 2);
    InsertatFront(head, 1);
    printlist(head);

    cout << "Answer is \n";
    head = deleteNafterM(head, 1, 3);
    printlist(head);

    return 0;
}