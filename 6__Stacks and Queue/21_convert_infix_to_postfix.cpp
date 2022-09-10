#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

// return true if cur element has more precedecne than the top
bool morePrecedence(char cur, char tp)
{
    // if top is ( or cur element is ( or ^ then it can be said current has high precedence
    // top is ( - can push any operand
    // cur is ( - can push it with checking top
    // cur is ^ - it has the highest precedence
    if (tp == '(' || cur == '(' || cur == '^')
        return true;

    // if current is * or /
    else if (cur == '*' || cur == '/')
    {
        // check if top has ^ - it has greater precedence than * and /
        //  or top has * or / - then * and / ,that have occured before have high precedence than current
        if (tp == '*' || tp == '/' || tp == '^')
            return false;

        // current is * or /  and top is + or - then current has more precedence
        else if (tp == '+' || tp == '-')
            return true;
    }

    // if current is + or -
    else if (cur == '+' || cur == '-')
    {
        // it has the lowest precedence so if any operand is in top of stack it will always have high precedecne than + and -
        // if top has + or - it will also have  high precedence as if has occured before than current.
        if (tp == '*' || tp == '/' || tp == '^' || tp == '+' || tp == '-')
            return false;
    }

    // default case
    return true;
}

void infixToPostfix(string str)
{
    stack<char> st;
    int n = str.size();

    for (int i = 0; i < n; i++)
    {
        // 1. check is current is opreand or opening bracket
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '(')
        {
            // if stack is empty simply push
            if (st.empty())
                st.push(str[i]);

            // else before pushing check the precedecne and push accordingly
            else
            {
                // check precedence
                char tp = st.top();
                // if current has more precedecne than top then push current
                if (morePrecedence(str[i], tp))
                {
                    st.push(str[i]);
                }

                // else top has more precedecne than current
                else
                {
                    // pop until the top has less precedence
                    while (!st.empty() && !morePrecedence(str[i], st.top()))
                    {
                        cout << st.top() << " ";
                        st.pop();
                    }
                    // when top has less precedence then push current in stack
                    st.push(str[i]);
                }
            }
        }

        // 2. if closing bracket is found then keep poping until opening bracket is found
        else if (str[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                cout << st.top() << " ";
                st.pop();
            }
            // at last pop the opening bracket also
            st.pop();
        }

        // 3. if current is digit or alphabet simply print.
        else
            cout << str[i] << " ";
    }

    // 4. until the stack is not empty keep poping
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    string str = "a*b/(c+d)*e";

    cout << "The postfix expression of " << str << " is ";
    infixToPostfix(str);
    cout << endl;
    return 0;
}