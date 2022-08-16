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

Node *addtwoLL(Node *head1, Node *head2)
{
    // if first LL is 0 or NULL
    if (head1 == NULL)
        return head2;

    // if second LL is 0 or NULL
    if (head2 == NULL)
        return head1;

    // reverse kro dono LL ko
    Node *first = ReverseLL(head1);
    Node *second = ReverseLL(head2);

    // ek dummy node banao ans store krne ke liye
    Node *ans = new Node(-1);
    Node *ansTail = ans;

    // add kro dono ko from left to right

    // intially carry 0 h or sum bhi 0 h
    int carry = 0, sum = 0;

    // loop chlega jb tk dono me element h
    while (first != NULL && second != NULL)
    {
        // phle dono number ka sum + carry  kro taki resultant no mile
        sum = carry + first->data + second->data;

        // is number ke liye carry nikalo 0 h ya fir kch or h
        carry = sum / 10;

        // naya node banao yaki usme answer store kr ske
        // answer hoga one place wala number to mod krna pdega
        Node *temp = new Node(sum % 10);

        // ab ans ke tail wale pointer me answer ka node attach kro
        ansTail->next = temp;
        ansTail = ansTail->next;

        // increment kro dono first and second pointer ko
        first = first->next;
        second = second->next;
        printlist(ans);
    }

    // agar second wala LL chota h 1st wale se
    while (first != NULL)
    {
        // to fir add kro carry and 1st ke number ko
        sum = first->data + carry;

        // carry find kro
        carry = sum / 10;

        // naya node banao
        Node *temp = new Node(sum % 10);

        // ans ke tail ko aage kro
        ansTail->next = temp;
        ansTail = ansTail->next;

        // 1st ko increment kro
        first = first->next;
        printlist(ans);
    }

    // agar 1st wala LL chota h 2nd wale se to same as above
    while (second != NULL)
    {
        sum = second->data + carry;
        carry = sum / 10;
        Node *temp = new Node(sum % 10);
        ansTail->next = temp;
        ansTail = ansTail->next;
        second = second->next;
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
    InsertatFront(head1, 1);
    InsertatFront(head1, 2);
    InsertatFront(head1, 6);
    InsertatFront(head1, 9);
    printlist(head1);

    cout << "Insert at Front head 2\n";
    InsertatFront(head2, 2);
    InsertatFront(head2, 1);
    InsertatFront(head2, 4);
    printlist(head2);

    cout << "Answer is \n";
    Node *head = addtwoLL(head1, head2);
    printlist(head);

    return 0;
}