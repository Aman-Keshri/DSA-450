#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
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
        }

        // recurssion will do rest
        solveInsert(child, word.substr(1));
    }

    void insert(string word)
    {
        solveInsert(root, word);
    }

    bool solveSearch(TrieNode *root, string word)
    {
        // base case
        // if length = 0 and the node is a terminal then return true else false
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
            child = root->children[index];

        // not present
        else
            return false;

        // recurssion
        return solveSearch(child, word.substr(1));
    }

    bool search(string word)
    {
        return solveSearch(root, word);
    }

    TrieNode *searchToRemove(TrieNode *root, string word)
    {
        // base case
        // if length = 0 and the node is a terminal then return true else false
        if (word.length() == 0)
        {
            if (root->isTerminal)
                return root;
        }

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
            child = root->children[index];

        // not present
        else
            return NULL;

        // recurssion
        return searchToRemove(child, word.substr(1));
    }

    void remove(string word)
    {
        TrieNode *temp = searchToRemove(root, word);
        temp->isTerminal = false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool solveprefix(TrieNode *root, string word)
    {
        // base case
        // if length = 0 and the node is a terminal then return true else false
        if (word.length() == 0)
            return true;

        int index = word[0] - 'A';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
            child = root->children[index];

        // not present
        else
            return false;

        // recurssion
        return solveprefix(child, word.substr(1));
    }

    bool startsWith(string prefix)
    {
        return solveprefix(root, prefix);
    }
};

int main()
{
    Trie *T = new Trie();

    T->insert("ABCD");
    T->insert("ABER");
    T->insert("ABCFG");
    T->insert("ABCDRR");
    T->insert("ABCDL");
    cout << "present or not  " << T->search("ABCD") << endl;
    T->remove("ABCD");
    cout << "present or not  " << T->search("ABCD") << endl;
    cout << "starts with " << T->startsWith("AB") << endl;
    return 0;
}