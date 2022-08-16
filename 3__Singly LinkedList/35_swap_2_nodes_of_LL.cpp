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

Node *swapNodes(Node *head, int i, int j)
{
    // 4 pointer rkhna h ek prev or ek cur for each i and j
    Node *prevI = NULL, *prevJ = NULL;
    Node *curI = head, *curJ = head;
    int ci = 0, cj = 0;

    // current position tk reach kro dono i and j pe or hmesa prev cur se ek piche rhega
    while (ci < i || cj < j)
    {
        if (ci < i)
        {
            prevI = curI;
            curI = curI->next;
            ci++;
        }

        if (cj < j)
        {
            prevJ = curJ;
            curJ = curJ->next;
            cj++;
        }
    }

    cout << ci << " pos " << cj << endl;
    cout << curI->data << " value " << curJ->data << endl;

    // step 1 agar prev Null nhi h to i ke prev ke next node to j wala node hoga as wo swap krke ayega
    if (prevI != NULL)
        prevI->next = curJ;
    // agar prev Null hua to iska mtlb head h tb j wale node ko head bana dnge
    else
        head = curJ;

    // step 2 agar prev Null nhi h to j ke prev ke next node to i wala node hoga as wo swap krke ayega
    if (prevJ != NULL)
        prevJ->next = curI;
    // agar prev Null hua to iska mtlb head h tb i wale node ko head bana dnge
    else
        head = curI;

    // swap kro baki dono current nodes ko
    // ab cur ke next wale node ko swap krnge taki wo sahi jagah point kre
    Node *temp = curJ->next;
    curJ->next = curI->next;
    curI->next = temp;

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

    cout << "Answer is \n";
    head = swapNodes(head, 2, 5);
    printlist(head);
    return 0;
}