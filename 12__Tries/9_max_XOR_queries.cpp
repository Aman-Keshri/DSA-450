#include <algorithm>
#include <bits/stdc++.h>

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

// TC - O()
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    // NLogN
    sort(arr.begin(), arr.end());

    vector<pair<int, pair<int, int>>> ofQ;

    int q = queries.size();

    // Q
    for (int i = 0; i < q; i++)
    {
        ofQ.push_back({queries[i][1], {queries[i][0], i}});
    }

    // QLogQ
    sort(ofQ.begin(), ofQ.end());

    vector<int> ans(q, 0);
    int ind = 0;
    int n = arr.size();
    Trie *tr = new Trie();

    // (Q * 32 + N * 32)
    for (int i = 0; i < q; i++)
    {
        int ai = ofQ[i].first;
        int xi = ofQ[i].second.first;
        int qInd = ofQ[i].second.second;

        while (ind < n && arr[ind] <= ai)
        {
            tr->insert(arr[ind]);
            ind++;
        }

        if (ind == 0)
            ans[qInd] = -1;
        else
            ans[qInd] = tr->getMax(xi);
    }

    return ans;
}