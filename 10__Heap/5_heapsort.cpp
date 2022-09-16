#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// class Heap
// {
// public:
//     int arr[100];
//     int size = 0;

//     Heap()
//     {
//         arr[0] = -1;
//         size = 0;
//     }
//     // insert function
//     void insert(int value)
//     {

//         size += 1;
//         int index = size;
//         arr[index] = value;

//         while (index > 1)
//         {
//             int parent = index / 2;
//             if (arr[parent] < arr[index])
//             {
//                 swap(arr[parent], arr[index]);
//                 index = parent;
//             }
//             else
//                 return;
//         }
//     }

//     void print()
//     {
//         for (int i = 1; i <= size; i++)
//             cout << arr[i] << " ";

//         cout << endl;
//     }
// };

// Heapify Function
//  Time  - O(logN) Space - O(1)
void heapify(int arr[], int n, int i)
{
    // set the given index as largest
    // find it's left and right index
    int large = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // check  for left and large index
    if (left <= n && arr[large] < arr[left])
        large = left;

    // check for right index
    if (right <= n && arr[large] < arr[right])
        large = right;

    // if the large has changed then swap value of given index and new large index
    //  and call heapify on the new index for further check
    if (large != i)
    {
        swap(arr[large], arr[i]);
        heapify(arr, n, large);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;

    while (size > 1)
    {
        // step 1 swap nodes
        swap(arr[1], arr[size]);
        size--;

        // heapify the root
        heapify(arr, size, 1);
    }
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

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Time - O(N)
    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    cout << "printing heapify \n";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    // heapsort
    cout << "Heapsort list\n";
    heapsort(arr, n);
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}