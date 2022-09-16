#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

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
    // TIme - O(log N) Space - O(1)
    void insert(int value)
    {
        // increase size of array and that will be the index to insert value
        size += 1;
        int index = size;

        // add the value to inser to array [ index ]
        arr[index] = value;

        // now check if the inserted element node is in correct place
        // by comparing root and child
        while (index > 1)
        {
            // parent node of a node is always at index/2 position
            int parent = index / 2;

            // check for each node validity
            if (arr[parent] < arr[index])
            {
                // swap the nodes it condn is not satisfied.
                // and update he index with new index
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

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.insert(51);

    h.print();
    return 0;
}