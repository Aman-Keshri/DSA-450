#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mergearray(vector<int> &a1, vector<int> &a2)
{
    int n1 = a1.size(), n2 = a2.size();

    int gap = ceil((float)(n1 + n2) / 2);

    while (gap > 0)
    {
        int i = 0, j = gap;
        while (j < (n1 + n2))
        {
            if (j < n1 && a1[i] > a1[j])
                swap(a1[i], a1[j]);
            else if (j >= n1 && i < n1 && a1[i] > a2[j - n1])
                swap(a1[i], a2[j - n1]);
            else if (j >= n1 && i >= n1 && a2[i - n1] > a2[j - n1])
                swap(a2[i - n1], a2[j - n1]);

            i++;
            j++;
        }
        if (gap == 1)
            gap = 0;
        else
            gap = ceil((float)gap / 2);
    }
}

int main()
{
    vector<int> a1 = {1, 3, 6, 9, 13};
    vector<int> a2 = {2, 4, 5, 8};

    cout << "Before merge:" << endl;
    for (int i = 0; i < a1.size(); i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < a2.size(); i++)
    {
        cout << a2[i] << " ";
    }
    cout << endl;

    mergearray(a1, a2);

    cout << "After merge:" << endl;
    for (int i = 0; i < a1.size(); i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < a2.size(); i++)
    {
        cout << a2[i] << " ";
    }
    cout << endl;
    return 0;
}