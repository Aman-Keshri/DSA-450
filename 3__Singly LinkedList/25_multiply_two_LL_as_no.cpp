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

Node *ReverseLL(Node *head)
{
    Node *prev = NULL, *cur = head, *temp = NULL;

    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev;
}

Node *multiplytwoLL(Node *head1, Node *head2)
{
    // if first LL is 0 or NULL
    if (head1 == NULL)
        return head2;

    // if second LL is 0 or NULL
    if (head2 == NULL)
        return head1;

    // reverse kro dono LL ko
    Node *first = head1;
    Node *second = head2;

    // ek dummy node banao ans store krne ke liye
    Node *ans = new Node(-1);
    Node *ansTail = ans;

    int fno = 0, sec = 0;

    while (first != NULL)
    {
        fno = (fno * 10) + first->data;
        first = first->next;
    }

    while (second != NULL)
    {
        sec = (sec * 10) + second->data;
        second = second->next;
    }

    long long int mul = fno * sec;

    while (mul)
    {
        int rem = mul % 10;
        Node *temp = new Node(rem);
        ansTail->next = temp;
        ansTail = ansTail->next;
        mul /= 10;
    }
    ans->next = ReverseLL(ans->next);

    return ans->next;
}

void InsertatFront(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

int main()
{
    Node *head1 = NULL, *head2 = NULL;

    cout << "Insert at Front head 1 \n";
    InsertatFront(head1, 9);
    InsertatFront(head1, 9);
    InsertatFront(head1, 9);
    InsertatFront(head1, 9);
    printlist(head1);

    cout << "Insert at Front head 2\n";
    InsertatFront(head2, 9);
    // InsertatFront(head2, 1);
    // InsertatFront(head2, 4);
    printlist(head2);

    cout << "Answer is \n";
    Node *head = multiplytwoLL(head1, head2);
    printlist(head);

    return 0;
}