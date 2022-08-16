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

int len(Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }

    return i;
}

Node *bubbleSort(Node *head)
{
    // Write your code here
    if (head == NULL)
        return NULL;
    int n = len(head) - 1;

    while (n--)
    {
        Node *prev = NULL;
        Node *cur = head;
        while (cur->next != NULL)
        {
            if (cur->data >= cur->next->data)
            {
                if (prev == NULL)
                {
                    // head node
                    Node *nxt = cur->next;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                    head = prev;
                }
                else
                {
                    Node *nxt = cur->next;
                    prev->next = nxt;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    prev = nxt;
                }
            }
            else
            {
                prev = cur;
                cur = cur->next;
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
    head = bubbleSort(head);
    printlist(head);
    return 0;
}