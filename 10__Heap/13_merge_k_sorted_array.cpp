/*
    Time  - O(N*K*log(N*K))     Space - O(N*K)
    Approach 1
    step 1 create a new array
    step 2 put all elements into the array
    step 3 sort the new array
*/

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
}

/*
    Time - O(N*KLogK)  Space - O(K) / O(N*K)
    Approach 2
    Min Heap is reuqired
    step 1 which initially has 1st element of all k array
    step 2 store the top of MIN heap to result array
           and insert next element of same array into min HEap
    repeat it until min heap > 0
*/
#include <queue>

class node
{
public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<int>, compare> pq;

    // step 1
    // Time - O(KlogK)
    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        pq.push(temp);
    }

    vector<int> ans;

    // step 2
    // Time - O(N*K)
    while (pq.size() > 0)
    {
        node *temp = pq.top();
        ans.push_back(temp->data);
        pq.pop();

        int rowInd = temp->row;
        int colInd = temp->col;

        if (colInd + 1 < kArrays[i].size())
        {
            node *next = new node(kArrays[rowInd][colInd + 1], rowInd, colInd + 1);
            pq.push(next);
        }
    }

    return ans;
}
