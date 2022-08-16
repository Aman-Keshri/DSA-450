// C++ program to merge k sorted
// arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node *next;
};

// Utility function to create a new node.
Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/* Function to print nodes in
a given linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

/* Takes two lists sorted in increasing order, and merge
their nodes together to make one big sorted list. Below
function takes O(n) extra space for recursive calls,
    */
Node *SortedMerge(Node *a, Node *b)
{
    Node *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}

// The main function that takes an array of lists
// arr[0..last] and generates the sorted output
Node *mergeKLists(Node *arr[], int last)
{
    // repeat until only one list is left
    int start = 0;
    int temp;

    // repeat until the end reaches to 0th index
    while (last != 0)
    {
        // alaways reaasign start and temp to first and last index of array
        start = 0;
        temp = last;

        // loop until start and temp do not cross each other
        while (start < temp)
        {
            // calculate merge start and temp linked list and store it in start list
            arr[start] = SortedMerge(arr[start], arr[temp]);
            start++;
            temp--;

            // if the start passess or equals to end index then set end to the temp index
            // temp will be in mid of the array after every iteration
            if (start >= temp)
                last = temp;
        }
    }
    // return the 1st index Linked List
    return arr[0];
}

// Driver program to test above functions
int main()
{
    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list

    // an array of pointers storing the head nodes
    // of the linked lists
    Node *arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // Merge all lists
    Node *head = mergeKLists(arr, k - 1);

    printList(head);

    return 0;
}
