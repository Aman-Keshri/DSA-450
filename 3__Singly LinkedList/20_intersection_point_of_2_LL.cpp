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

Node *IntersectionI(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node *p1 = head1, *p2 = head2;

    while (p1 != p2)
    {
        p1 = p1 == NULL ? head2 : p1->next;
        p2 = p2 == NULL ? head1 : p2->next;
    }
    return p1;
}

// naive approach
/*
1. iterate to find the commom node of both array  time - O(N^2)  space - O(1)

2. hash the values of one LL and check it for the other if the node of second is in hash then return the node
    time - O(N)  space - O(N)

3. find length of both LL and the find diffrence of both and move longer list by diffrence
    then traverse both list together when the meet then it will be intersection node

4. the above approach keep traversing the two pointers until they meet
    if 1st reach end then change to 2nd
    if 2nd reach end then change it to 1st
    when they meet then then aswer will be either the 1st or the 2nd pointer.
*/

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
    InsertatFront(head2, 1);
    InsertatFront(head2, 3);
    head2->next->next = head1->next;
    printlist(head2);

    cout << "Answer is \n";
    Node *head = IntersectionI(head1, head2);
    printlist(head);

    return 0;
}