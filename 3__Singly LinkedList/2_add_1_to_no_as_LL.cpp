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

Node *add1toLL(Node *head1)
{
    // if first LL is 0 or NULL
    if (head1 == NULL)
        return NULL;

    // reverse kro LL ko
    Node *first = ReverseLL(head1);

    // ek dummy node banao ans store krne ke liye
    Node *ans = new Node(-1);
    Node *ansTail = ans;

    // add kro from left to right

    // intially carry 0 h or sum bhi 0 h
    int carry = 0, sum = 0;
    bool flag1 = true;
    // loop chlega jb tk dono me element h
    while (first != NULL)
    {
        // phle dono number ka sum + carry  kro taki resultant no mile
        if (flag1)
        {
            sum = carry + first->data + 1;
            flag1 = false;
        }
        else
            sum = carry + first->data;

        // is number ke liye carry nikalo 0 h ya fir kch or h
        carry = sum / 10;

        // naya node banao yaki usme answer store kr ske
        // answer hoga one place wala number to mod krna pdega
        Node *temp = new Node(sum % 10);

        // ab ans ke tail wale pointer me answer ka node attach kro
        ansTail->next = temp;
        ansTail = ansTail->next;

        // increment kro dono first pointer ko
        first = first->next;
        printlist(ans);
    }

    // last me agar last sum jo find kiye usme agar double digit aya to
    if (sum / 10)
    {
        // new node banao
        Node *temp = new Node(sum / 10);

        // ans ke tail me attach kro
        ansTail->next = temp;
        ansTail = ansTail->next;
    }

    // ans list ko bhi reverse kr do
    ans->next = ReverseLL(ans->next);

    // return
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

    // cout << "Insert at Front head 2\n";
    // InsertatFront(head2, 2);
    // InsertatFront(head2, 1);
    // InsertatFront(head2, 4);
    // printlist(head2);

    cout << "Answer is \n";
    Node *head = add1toLL(head1);
    printlist(head);

    return 0;
}