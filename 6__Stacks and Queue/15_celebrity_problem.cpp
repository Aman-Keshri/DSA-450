// C++ program to find celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;

#define N 8

// Returns -1 if celebrity
// is not present. If present,
// returns id (value from 0 to n-1).
int findCelebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;
    // push all candidates in stack
    for (int i = 0; i < M.size(); i++)
        st.push(i);

    int a, b;

    // pop top two elements and check
    while (st.size() != 1)
    {
        a = st.top();
        st.pop();

        b = st.top();
        st.pop();

        // if M[a][b]=0 then it means 'a' does not know 'b' and 'a' can be celebrity then push a
        if (M[a][b] == 0)
            st.push(a);

        // if 'a' knows 'b' so 'b' can be celebrity so push 'b'
        else
            st.push(b);
    }

    // check that the single element is celebrity or not
    int celebrity = st.top();
    bool flag = true;
    // row check for all 0
    for (int i = 0; i < M[0].size(); i++)
    {
        if (M[celebrity][i] != 0 && celebrity != i)
            flag = false;
    }
    // column check for all 1
    for (int i = 0; i < M.size(); i++)
    {
        if (M[i][celebrity] != 1 && celebrity != i)
            flag = false;
    }

    if (flag == true)
        return celebrity;
    else
        return -1;
}

// Driver code
int main()
{
    int n = 4;
    vector<vector<int>> matrix = {{0, 0, 1, 0},
                                  {0, 0, 1, 0},
                                  {0, 0, 0, 0},
                                  {0, 0, 1, 0}};
    int id = findCelebrity(matrix, n);
    id == -1 ? cout << "No celebrity" : cout << "Celebrity ID " << id;
    return 0;
}
