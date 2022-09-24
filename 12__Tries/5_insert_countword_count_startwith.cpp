#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Time C - O(len)
class TrieNode
{
public:
    TrieNode *children[26];
    int endNode;
    int freq;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        endNode = 0;
        freq = 0;
    }

    bool containsKey(char ch)
    {
        return (children[ch - 'a'] != NULL);
    }

    TriNode *get(char ch)
    {
        return children[ch - 'a'];
    }

    void put(char ch, TrieNode *node)
    {
        children[ch - 'a'] = node;
    }

    void increaseEnd()
    {
        endNode++;
    }

    void increaseFreq()
    {
        freq++;
    }

    void decreaseEnd()
    {
        endNode--;
    }

    void decreaseFreq()
    {
        freq--;
    }

    int getEnd()
    {
        return endNode;
    }

    int getFreq()
    {
        return freq;
    }
};

class Tire
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new TrieNode());

            node = node->get(word[i]);
            node->increaseFreq();
        }

        node->increaseEnd();
    }

    int countWordsEqualTo(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->get();
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
                node = node->get(word[i]);

            else
                return 0;
        }

        return node->getFreq();
    }

    void erase(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->decreaseFreq();
            }
            else
                return;
        }
        node->decreaseEnd();
    }
};