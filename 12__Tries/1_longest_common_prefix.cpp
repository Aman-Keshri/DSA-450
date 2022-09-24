// Time - O(M*N)  spce - O(1)

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];
        bool match = true;

        for (int j = 1; j < n; j++)
        {
            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }
        if (match)
            ans.push_back(ch);
        else
            break;
    }
    return ans;
}

// TRIE
//  Time - O(M*N)  spce - O(1)
class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int childcount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childcount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }
    void solveInsert(TrieNode *root, string word)
    {
        // base case , if it is the last char of string then isterminal will be set to true
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // assumption, words will be in CAPital
        int index = word[0] - 'A';
        TrieNode *child;

        // if char is present in the node
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }

        // if char is not present
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childcount++;
        }

        // recurssion will do rest
        solveInsert(child, word.substr(1));
    }

    void insert(string word)
    {
        solveInsert(root, word);
    }

    void LCP(string str, string &ans)
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (root->childcount == 1)
            {
                ans.push_back(ch);

                int index = ch - 'a';
                root = root->children[index];
            }
            else
                break;

            if (root->isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    Trie *t = new Trie();

    for (auto i : arr)
    {
        t->insert(i);
    }

    string first = arr[0];

    t->LCP(first, ans);

    return ans;
}
