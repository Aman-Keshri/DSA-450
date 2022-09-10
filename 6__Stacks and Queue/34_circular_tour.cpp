#include <iostream>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

// C++ program to find circular tour for a truck
using namespace std;

// A petrol pump has petrol and distance to next petrol pump
class petrolPump
{
public:
    int petrol;
    int distance;
};

int circularTour(petrolPump p[], int n)
{
    int kami = 0;
    int balance = 0;
    int start = 0;

    // 0 se n tk traverse kro lo with condtion
    // agar last tk ja ke balance bacehga or agar kahi kami huyi petrol ki
    // to kami bhi rhegi
    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;

        if (balance < 0)
        {
            kami += balance;
            start = i + 1;
            balance = 0;
        }
    }

    // fir agar jo kami h wo agar balance se kam ho to fir 2nd time traverse krna nhi pdega
    if (kami + balance >= 0)
        return start;
    else
        return -1;
}

// Driver code
int main()
{
    petrolPump arr1[] = {{6, 4}, {3, 6}, {7, 3}};
    petrolPump arr[] = {{6, 5}, {7, 6}, {4, 7}, {10, 8}, {6, 6}, {5, 4}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = circularTour(arr, n);

    (start == -1) ? cout << "No solution" : cout << "Start = " << start;

    return 0;
}
