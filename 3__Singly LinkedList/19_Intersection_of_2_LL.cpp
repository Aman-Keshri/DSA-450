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

Node *Intersection(Node *head1, Node *head2)
{
    // if first LL is 0 or NULL
    if (head1 == NULL)
        return head2;

    // if second LL is 0 or NULL
    if (head2 == NULL)
        return head1;

    Node *first = head1, *second = head2;

    // ek dummy node banao ans store krne ke liye
    Node *ans = new Node(-1);
    Node *ansTail = ans;

    // loop chlega jb tk dono me element h
    while (first != NULL && second != NULL)
    {
        if (first->data == second->data)
        {
            Node *temp = new Node(first->data);
            ansTail->next = temp;
            ansTail = ansTail->next;
            first = first->next;
            second = second->next;
        }
        else if (first->data < second->data)
            first = first->next;
        else if (first->data > second->data)
            second = second->next;
    }
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
    InsertatFront(head1, 6);
    InsertatFront(head1, 4);
    InsertatFront(head1, 2);
    InsertatFront(head1, 1);
    printlist(head1);

    cout << "Insert at Front head 2\n";
    InsertatFront(head2, 6);
    InsertatFront(head2, 4);
    InsertatFront(head2, 2);
    printlist(head2);

    cout << "Answer is \n";
    Node *head = Intersection(head1, head2);
    printlist(head);

    return 0;
}