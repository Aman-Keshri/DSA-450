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

int getlen(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *rightRotate(Node *head, int k)
{
    if (k == 0 || head == NULL)
        return head;

    Node *slow = head, *fast = head;

    int len = getlen(head);
    int place = k % len;

    while (place--)
        fast = fast->next;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = head;
    head = slow->next;
    slow->next = NULL;

    return head;
}

Node *leftRotate(Node *head, int k)
{
    if (k == 0 || head == NULL)
        return head;

    Node *slow = head, *fast = head;

    int len = getlen(head);
    int place = k % len;

    while (fast->next != NULL)
        fast = fast->next;

    while (place--)
    {
        fast->next = slow;
        slow = slow->next;
        fast = fast->next;
        fast->next = NULL;
    }

    head = slow;

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
    InsertatFront(head, 3);
    InsertatFront(head, 4);
    InsertatFront(head, 2);
    InsertatFront(head, 1);
    InsertatFront(head, 5);
    InsertatFront(head, 7);
    InsertatFront(head, 6);
    printlist(head);

    cout << "Right rotate Answer is \n";
    head = rightRotate(head, 2);
    printlist(head);

    cout << "Left rotate Answer is \n";
    head = leftRotate(head, 2);
    printlist(head);
    return 0;
}