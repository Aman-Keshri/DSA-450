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

    // delete function - always delete the root node of heap
    // TIme - O(log N) Space - O(1)
    void deleteNode()
    {
        // base case
        if (size == 0)
        {
            cout << "No elements to delete\n";
            return;
        }

        // swap the top of tree with last node and remove the last node after swap
        arr[1] = arr[size];
        size--;

        // take new root to new correct position
        int i = 1;
        while (i < size)
        {
            // get the left and right of the new root
            int left = 2 * i;
            int right = 2 * i + 1;

            // check if left child exits and root is less than left child
            //  then swap then and assign index to left child
            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            // check if right child exits and root is less than right child
            //  then swap then and assign index to right child
            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            // else the root is already in correct place so return
            else
                return;
        }
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
    h.deleteNode();
    h.print();
    return 0;
}