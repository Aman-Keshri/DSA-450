class TrieNode
{
private:
    TrieNode *children[26];

public:
    bool containKey(char ch)
    {
        return (children[ch - 'a'] != NULL);
    }

    TrieNode *get(char ch)
    {
        return children[ch - 'a'];
    }

    void put(char ch, TrieNode *node)
    {
        children[ch - 'a'] = node;
    }
};

// TC - O(N^2)
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int count = 0;
    TrieNode *root = new TrieNode();

    for (int i = 0; i < word.size(); i++)
    {
        TrieNode *node = root;
        for (int j = i; j < word.size(); i++)
        {
            if (!node->containKey(word[j]))
            {
                count++;
                node->put(word[j], new TrieNode());
            }
            node = node->get(word[j]);
        }
    }

    return count + 1;
}