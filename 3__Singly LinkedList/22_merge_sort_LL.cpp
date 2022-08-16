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

Node *findMid(Node *head)
{
    Node *slow = head, *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node *merged = new Node(-1);
    Node *mergedtail = merged;

    Node *p1 = head1;
    Node *p2 = head2;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data <= p2->data)
        {
            mergedtail->next = p1;
            mergedtail = mergedtail->next;
            p1 = p1->next;
        }
        else
        {
            mergedtail->next = p2;
            mergedtail = mergedtail->next;
            p2 = p2->next;
        }
    }

    if (p1 != NULL)
        mergedtail->next = p1;
    else
        mergedtail->next = p2;

    // while (p1 != NULL)
    // {
    //     mergedtail->next = p1;
    //     mergedtail = mergedtail->next;
    //     p1 = p1->next;
    // }

    // while (p2 != NULL)
    // {
    //     mergedtail->next = p2;
    //     mergedtail = mergedtail->next;
    //     p2 = p2->next;
    // }

    return merged->next;
}

Node *mergeSortLL(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    // find mid element
    Node *mid = findMid(head);
    // call recursion on left and right part
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSortLL(left);
    right = mergeSortLL(right);

    // merge both right and left part
    Node *ans = mergeLL(left, right);

    // return the new node where result is stored
    return ans;
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
    head = mergeSortLL(head);
    printlist(head);
    return 0;
}