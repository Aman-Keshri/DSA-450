class Solution
{
public:
    int checkValid(string str)
    {
        stack<char> st;

        int i = 0;
        while (i < str.size())
        {
            if (str[i] == '(')
                st.push('(');
            else if (str[i] == ')')
            {
                if (st.size() > 0 && st.top() == '(')
                    st.pop();
                else
                    st.push(')');
            }
            i++;
        }
        return st.size();
    }

    void solve(string str, int minInvalid, vector<string> &ans, unordered_map<string, int> &mp)
    {
        if (mp[str] != 0)
            return;
        else
            mp[str]++;

        if (minInvalid < 0)
            return;

        else if (minInvalid == 0)
        {
            if (!checkValid(str))
                ans.push_back(str);
            return;
        }

        for (int i = 0; i < str.size(); i++)
        {
            string s = str.substr(0, i);
            s += str.substr(i + 1);

            solve(s, minInvalid - 1, ans, mp);
        }
        return;
    }

    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> ans;
        unordered_map<string, int> mp;
        solve(s, checkValid(s), ans, mp);

        return ans;
    }
};
