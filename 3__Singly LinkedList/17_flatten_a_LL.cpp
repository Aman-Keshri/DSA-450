// C++ program for flattening a Linked List
#include <bits/stdc++.h>
using namespace std;

// Link list node
class Node
{
public:
    int data;
    Node *next, *down;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->down = NULL;
    }
};

Node *head = NULL;

// An utility function to merge two sorted
// linked lists
Node *merge(Node *head1, Node *head2)
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
            mergedtail->down = p1;
            mergedtail = mergedtail->down;
            p1 = p1->down;
        }
        else
        {
            mergedtail->down = p2;
            mergedtail = mergedtail->down;
            p2 = p2->down;
        }
    }

    if (p1 != NULL)
        mergedtail->down = p1;
    else
        mergedtail->down = p2;

    return merged->down;
}

Node *flatten(Node *head)
{

    // Base Cases
    if (head == NULL || head->next == NULL)
        return head;

    // Recur for list on next
    head->next = flatten(head->next);

    // Now merge
    head = merge(head, head->next);

    // Return the root
    // it will be in turn merged with its left
    return head;
}

// Utility function to insert a node at
// beginning of the linked list
Node *push(Node *head_ref, int data)
{

    // Allocate the Node & Put in the data
    Node *new_node = new Node(data);

    new_node->next = NULL;

    // Make next of new Node as head
    new_node->down = head_ref;

    // Move the head to point to new Node
    head_ref = new_node;

    return head_ref;
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->down;
    }
    cout << endl;
}

// Driver's code
int main()
{

    /* Let us create the following linked list
        5 -> 10 -> 19 -> 28
        | |	 |	 |
        V V	 V	 V
        7 20 22 35
        |		 |	 |
        V		 V	 V
        8		 50 40
        |			 |
        V			 V
        30			 45
    */
    head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);

    head->next = push(head->next, 20);
    head->next = push(head->next, 10);

    head->next->next = push(head->next->next, 50);
    head->next->next = push(head->next->next, 22);
    head->next->next = push(head->next->next, 19);

    head->next->next->next = push(head->next->next->next, 45);
    head->next->next->next = push(head->next->next->next, 40);
    head->next->next->next = push(head->next->next->next, 35);
    head->next->next->next = push(head->next->next->next, 20);

    // Function call
    head = flatten(head);

    printList();
    return 0;
}

// This code is contributed by rajsanghavi9.
