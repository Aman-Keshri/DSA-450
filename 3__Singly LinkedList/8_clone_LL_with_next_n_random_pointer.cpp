
// C++ program to clone a linked list with next
// and arbit pointers in O(n) time
#include <bits/stdc++.h>
using namespace std;

// Structure of linked list Node
struct Node
{
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

// Utility function to print the list.
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

// This function clones a given linked list
// in O(n) space

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
}

Node *clone(Node *head)
{
    // step 1 copy the original list to new list using next pointer
    if (head == NULL)
        return NULL;

    Node *cloneHead = NULL;
    Node *clonetail = NULL;
    Node *p = head;
    // insert at tail of new clone pointer
    while (p != NULL)
    {
        insertAtTail(cloneHead, clonetail, p->data);
        p = p->next;
    }
    // step 2 map the original node to new node to keep track
    unordered_map<Node *, Node *> mp;
    Node *original = head;
    Node *new_ = cloneHead;

    while (original != NULL && new_ != NULL)
    {
        mp[original] = new_;
        original = original->next;
        new_ = new_->next;
    }

    // step 3 set the random pointer to the new node
    original = head;
    new_ = cloneHead;

    while (original != NULL)
    {
        new_->random = mp[original->random];
        original = original->next;
        new_ = new_->next;
    }

    // return the head of new pointer
    return cloneHead;
}

// This function clones a given linked list
// in O(1) space
Node *GFGclone(Node *head)
{
    // step 1 create a clone List

    Node *cloneHead = NULL, *cloneTail = NULL;

    Node *p = head;
    // insert at tail of new clone pointer
    while (p != NULL)
    {
        insertAtTail(cloneHead, cloneTail, p->data);
        p = p->next;
    }
    // step 2 clone Nodes add in between original nodes
    Node *original = head;
    Node *clone_ = cloneHead;

    while (original != NULL && clone_ != NULL)
    {
        Node *next = original->next;
        original->next = clone_;
        original = next;

        next = clone_->next;
        clone_->next = original;
        clone_ = next;
    }

    // step 3 random pointer copy
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            if (temp->random != NULL)
                temp->next->random = temp->random->next;

            else
                temp->next->random = temp->random;
        }
        temp = temp->next->next;
    }

    // step 4 revert changes
    original = head;
    clone_ = cloneHead;

    while (original != NULL && clone_ != NULL)
    {
        original->next = clone_->next;
        original = original->next;

        if (original != NULL)
            clone_->next = original->next;
        clone_ = clone_->next;
    }

    // step 5 return ans
    return cloneHead;
}

// Driver code
int main()
{
    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
        start->next->next->next->next;
    start->next->next->next->random =
        start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random =
        start->next;

    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    Node *cloned_list = GFGclone(start);
    print(cloned_list);

    return 0;
}