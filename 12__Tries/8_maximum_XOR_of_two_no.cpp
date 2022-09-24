class TrieNode
{
private:
    TrieNode *children[2];

public:
    bool containsKey(int bit)
    {
        return (children[bit] != NULL);
    }

    TrieNode *get(int bit)
    {
        return children[bit];
    }

    void put(int bit, TrieNode *node)
    {
        children[bit] = node;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(int num)
    {
        TrieNode *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = num >> i & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        TrieNode *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = num >> i & 1;
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    // Write your code here.
    Trie *tri = new Trie();
    for (auto it : arr1)
        tri->insert(it);

    int maxi = 0;
    for (auto it : arr2)
        maxi = max(maxi, tri->getMax(it));

    return maxi;
}