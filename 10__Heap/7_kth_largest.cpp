#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }
    // insert function
    void insert(int value)
    {

        size += 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

/*

This could be done in 3  steps
1. create Min Heap for first k elements
2. now the rest k+1 to n nodes are then checked with current heap top
    if (curr element < heap top)  then remove current top of heap(priority queue)
3. and add the element to last node of heap and heapify
4. at last the top will contain the answer of kth smallest element
*/

int kthSmall(int arr[], int l, int r, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // step 1
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);

    // step 2
    for (int i = k; i <= r; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step 3
    int res = pq.top();
    return res;
}

int main()
{
    // Heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.insert(51);

    // h.print();
    int arr[] = {7, 10, 4, 20, 15};
    int n = 5;
    cout << "kth smallest element is  " << kthSmall(arr, 0, n - 1, 4);

    return 0;
}