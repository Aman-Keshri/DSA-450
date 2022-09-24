#include <bits/stdc++.h>
class TrieNode
{
private:
    TrieNode *children[26];
    bool isTerminal;

public:
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isTerminal = false;
    }

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

    void setEnd()
    {
        isTerminal = true;
    }

    bool isEnd()
    {
        return isTerminal;
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

    void insert(string word)
    {
        TrieNode *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }

            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word)
    {
        TrieNode *node = root;
        bool flag = true;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->containKey(word[i]))
            {
                node = node->get(word[i]);
                flag = flag & node->isEnd();
            }
            else
                return false;
        }
        return flag;
    }
};

string completeString(int n, vector<string> &a)
{
    // Write your code here.
    Trie *t = new Trie();
    for (auto it : a)
        t->insert(it);

    string longest = "";

    for (auto it : a)
    {
        if (t->checkIfPrefixExists(it))
        {
            if (it.size() > longest.size())
                longest = it;

            else if (it.size() == longest.size() && it < longest)
                longest = it;
        }
    }

    if (longest == "")
        return "None";

    return longest;
}