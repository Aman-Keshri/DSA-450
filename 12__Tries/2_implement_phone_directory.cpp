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
        int index = word[0] - 'a';
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

    void printSuggesstion(TrieNode *curr, vector<string> &temp, string prefix)
    {
        // if current is terminal node then store the prefix to temp
        if (curr->isTerminal)
            temp.push_back(prefix);
        // loop from a to z as this are all possible children of the node
        for (char c = 'a'; c <= 'z'; c++)
        {
            // store the node for each char of the curr node
            TrieNode *next = curr->children[c - 'a'];

            // if the next node has some value then
            // add that char to prefix for print
            // and recurse on that updated prefix
            // after returning bck remove the element so next word can be processed
            if (next != NULL)
            {
                prefix.push_back(c);
                printSuggesstion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str)
    {
        // declare variables
        TrieNode *prev = root;
        vector<vector<string>> ans;
        string prefix = "";

        // loop on all characters of string
        for (int i = 0; i < str.length(); i++)
        {
            // take the first char
            char ch = str[i];
            // push that char to prefix
            prefix.push_back(ch);
            // now store the node corresponding to the first char in prev node in current
            TrieNode *curr = prev->children[ch - 'a'];

            // if the current node is NULL then cannot display anything  so break;
            if (curr == NULL)
                break;
            // if the node contains some value then print all the suggsted words
            else
            {
                // create a vector to store current suggestion
                vector<string> temp;
                // call print function
                printSuggesstion(curr, temp, prefix);

                // after return from function store all suggestion from temp to ans
                // clear temp for next iteration
                // increment prev = curr
                ans.push_back(temp);
                temp.clear();
                prev = curr;
            }
        }

        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t = new Trie();

    // insert all contact to Trie
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insert(str);
    }

    // return ans
    return t->getSuggestions(queryStr);
}
