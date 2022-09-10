#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

void reverseKfront(vector<int> ar, int k)
{
    stack<int> s;
    queue<int> q;
    int n = ar.size();

    for (int i = 0; i < k; i++)
        s.push(ar[i]);

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    for (int i = k; i < n; i++)
        q.push(ar[i]);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    vector<int> ar = {1, 2, 3, 4, 5, 6, 7};
    reverseKfront(ar, 4);
    return 0;
}