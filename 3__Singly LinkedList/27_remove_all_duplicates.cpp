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

Node *removeDuplicateSorted(Node *head)
{
    Node *cur = head;

    if (head == NULL)
        return NULL;

    while (cur != NULL)
    {
        if (cur->next != NULL && (cur->data == cur->next->data))
        {
            Node *temp = cur->next;
            cur->next = cur->next->next;
            delete (temp);
        }
        else
        {
            cur = cur->next;
        }
    }
    return head;
}

Node *removeDuplicateUnsorted(Node *head)
{
    unordered_map<int, int> mp;
    Node *prev = NULL, *cur = head, *temp = NULL;

    while (cur != NULL)
    {
        if (mp.find(cur->data) != mp.end())
        {
            temp = cur;
            cur = cur->next;
            prev->next = cur;
            temp->next = NULL;
            delete (temp);
        }
        else
        {
            mp[cur->data]++;
            prev = cur;
            cur = cur->next;
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
    InsertatFront(head, 5);
    InsertatFront(head, 5);
    InsertatFront(head, 5);
    InsertatFront(head, 5);
    InsertatFront(head, 5);
    InsertatFront(head, 5);
    InsertatFront(head, 5);
    printlist(head);

    cout << "Answer is \n";
    head = removeDuplicateUnsorted(head);
    printlist(head);

    head = removeDuplicateSorted(head);
    printlist(head);

    return 0;
}