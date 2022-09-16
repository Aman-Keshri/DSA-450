/*
    Approach 1
    step 1 store all elements in vector  T- O(N*K) Space - O(N*K)
    step 2 sort the vector  T- O(N*K Log(N*K))
    step 3 merge all LL from tail and head  T- O(N*K)
    step 4 traverse the list and replace value from vector one by one  T- O(N*K)
*/
/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

/*
    Time - O(KLogK + N*K Log K) = N*K Log K
    Space - O(K)
    Approach 2
    step 1 create a min heap for first node of all LL
    step 2 store the top of MIN heap to result LL's tail
           and insert next element of same LL into min HEap
    repeat it until min heap > 0
*/
#include <queue>

class compare
{
public:
    bool operator()(Node<int> *a, Node<int> *b)
    {
        return a->data > b->data;
    }
};

Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{
    // Write your code here.
    priority_queue<Node<int> *, vector<Node<int> *>, compare> pq;

    // step 1
    int k = listArray.size();
    if (k == 0)
        return NULL;

    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
            pq.push(listArray[i]);
    }

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    // step 2
    while (pq.size() > 0)
    {
        Node<int> *topNode = pq.top();
        pq.pop();

        if (topNode->next != NULL)
            pq.push(topNode->next);

        if (head == NULL)
        {
            head = topNode;
            tail = topNode;
        }
        else
        {
            tail->next = topNode;
            tail = topNode;
        }
    }
    return head;
}