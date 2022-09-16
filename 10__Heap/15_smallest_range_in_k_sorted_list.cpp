#include <bits/stdc++.h>
#include <queue>

class Node
{
public:
    int data;
    int row;
    int col;

    Node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

// Time - O(N*K^2)  Space - O(K)

int kSorted(vector<vector<int>> &a, int k, int n)
{

    int mini = INT_MAX, maxi = INT_MIN;

    priority_queue<Node *, vector<Node *>, compare> pq;

    // push the k elements form each k sorted array and track min and max value
    for (int i = 0; i < k; i++)
    {
        int ele = a[i][0];
        maxi = max(maxi, ele);
        mini = min(mini, ele);

        pq.push(new Node(ele, i, 0));
    }

    int start = mini, end = maxi;

    // loop to find range
    while (!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();

        // update mini with min heaps top element
        mini = temp->data;

        // if maxi - mini is < end - start
        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        // check if next element of array is present
        if (temp->col + 1 < n)
        {
            // update the maxi
            maxi = max(maxi, a[temp->row][temp->col + 1]);
            pq.push(new Node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }

        // else element does no exist in any one array then break
        else
        {
            break;
        }
    }
    // return diffrence of range
    return (end - start + 1);
}