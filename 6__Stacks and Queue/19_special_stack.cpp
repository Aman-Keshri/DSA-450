#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* A special stack having peek() pop() and
 * push() along with additional getMin() that
 * returns minimum value in a stack without
 * using extra space and all operations in O(1)
 * time.. ???? */
class SpecialStack
{

    // Sentinel value for min
    int mini = -1;

    // DEMO_VALUE
    stack<int> st;

public:
    void getMin()
    {
        if (st.empty())
            cout << -1 << endl;
        else
            cout << "min is: " << mini << endl;
    }

    void push(int val)
    {

        // If stack is empty OR current element
        // is less than min, update min.
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val - mini);
                mini = val;
            }
            else
                st.push(val);
        }
    }

    int pop()
    {
        // if stack is empty return -1;
        if (st.empty())
        {
            cout << "stack underflow" << endl;
            return -1;
        }

        int cur = st.top();
        st.pop();
        if (cur > mini)
            return cur;
        else
        {
            int prvmin = mini;
            int data = 2 * mini - cur;
            mini = data;
            return prvmin;
        }
    }

    int peek()
    {
        if (st.empty())
            return -1;

        int cur = st.top();
        if (cur < mini)
            return mini;

        else
            return cur;
    }
};

class SpecialStack1
{
public:
    long long mini;
    stack<long long> st;

    MinStack()
    {
        mini = -1;
    }

    void push(long long val)
    {
        // stack is empty then push and update mini
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else
        {
            // if cur element is < than mini then need to update mini and push a coded value to stack
            if (val < mini)
            {
                st.push(2 * val - mini);
                mini = val;
            }
            // if stack not empty and cur element is > than mini simply push
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
        {
            return;
        }
        else
        {
            long long cur = st.top();
            st.pop();

            if (cur < mini)
            {
                // store the cur mini as it will be updated
                long long prev = mini;
                // decode the element
                long long element = 2 * mini - cur;
                // update the mini after the cur mini is popped
                mini = element;
                // return prev;  as this will be the item to be popped from stack
            }
            else
            {
                // return the cur as popped
            }
        }
    }

    int top()
    {
        // if empty stack
        if (st.empty())
            return -1;
        else
        {
            long long cur = st.top();
            // if stack top is less than mini then it is a modified form of element,
            // it will be the minimum value so just return mini
            if (cur < mini)
                return mini;
            // if not then return the value
            else
                return cur;
        }
    }

    int getMin()
    {
        if (st.empty())
            return -1;
        else
            return mini;
    }
};

// Driver Code
int main()
{
    SpecialStack s;

    vector<int> arr = {3, 2, 6, 1, 8, 5, 5, 5, 5};

    for (int i = 0; i < arr.size(); i++)
    {
        s.push(arr[i]);
        s.getMin();
    }

    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        s.pop();
        s.getMin();
    }
    return 0;
}
