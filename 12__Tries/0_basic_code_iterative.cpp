#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isTerminal;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    // TC - O(len)
    void insert(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->children[word[i] - 'a'] == NULL)
            {
                node->children[word[i] - 'a'] = new TrieNode();
            }
            node = node->children[word[i] - 'a'];
        }

        node->isTerminal = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->children[word[i] - 'a'] == NULL)
                return false;

            node = node->children[word[i] - 'a'];
        }
        return node->isTerminal;
    }

    void remove(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->children[word[i] - 'a'] == NULL)
                return;

            node = node->children[word[i] - 'a'];
        }
        node->isTerminal = false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (node->children[prefix[i] - 'a'] == NULL)
                return false;

            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
};

int main()
{
    Trie *T = new Trie();

    T->insert("abcd");
    T->insert("aber");
    T->insert("abcfg");
    T->insert("abcdrgt");
    T->insert("aghytu");
    cout << "present or not  " << T->search("abcd") << endl;
    T->remove("abcd");
    cout << "present or not  " << T->search("abcd") << endl;
    cout << "starts with " << T->startsWith("ar") << endl;
    return 0;
}