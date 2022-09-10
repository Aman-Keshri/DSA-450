#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void revers(queue<int> &q)
{
    if (q.empty())
        return;
    int data = q.front();
    q.pop();
    revers(q);
    q.push(data);
}

queue<int> rev(queue<int> q)
{
    revers(q);
    return q;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << endl;

    queue<int> ans = rev(q);
    cout << ans.front() << endl;
    return 0;
}