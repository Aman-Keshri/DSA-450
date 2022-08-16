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

Node *findMid(Node *head)
{
    Node *fast = head->next, *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node *ReverseLL(Node *middle)
{
    Node *prev = NULL, *cur = middle, *temp = NULL;

    while (cur != NULL)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    return prev;
}

bool CheckPallindromeI(Node *head)
{
    // find middle
    Node *middle = findMid(head);
    // reverse middle + 1 to last
    middle->next = ReverseLL(middle->next);
    //  compare 1-middle with middle + 1 - last
    //  if same true else false
    Node *p = head;
    Node *mid = middle->next;

    bool ans = true;

    while (mid != NULL)
    {
        if (p->data != mid->data)
            ans = false;
        p = p->next;
        mid = mid->next;
    }

    // if required reverse the middle + 1 to last of LL
    middle->next = ReverseLL(middle->next);

    // return
    return ans;
}

// always need to pass the reference of 1st pointer as double pointer as passing single pointer will act
// like passing by value in recursion.
bool CheckPallindrome(Node **first, Node *last)
{
    if (last == NULL)
        return true;

    bool check1 = CheckPallindrome(first, last->next);

    if (check1 == false)
        return false;

    bool check2 = (last->data == (*first)->data);

    (*first) = (*first)->next;

    return check2;
}

bool isPalindrome(Node *head)
{
    // return CheckPallindrome(&head, head);
    return CheckPallindromeI(head);
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
    InsertatFront(head, 2);
    InsertatFront(head, 4);
    InsertatFront(head, 3);
    printlist(head);

    cout << "Linked List is pallindrome " << (isPalindrome(head) == 0 ? "False" : "True") << endl;

    return 0;
}