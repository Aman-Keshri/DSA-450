#include <iostream>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    int freq;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        freq = 0;
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

    void insertFunc(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
            return;

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
            root->freq++;
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertFunc(child, word.substr(1));
    }

    void insert(string word)
    {
        insertFunc(root, word);
    }

    void InsertTrie(TrieNode *root, string word)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (root->children[word[i] - 'a'] == NULL)
                root->children[word[i] - 'a'] = new TrieNode(word[i]);

            root = root->children[word[i] - 'a'];
            root->freq++;
        }
    }

    void findPrefixUtil(string arr[], vector<string> &ans, int n)
    {
        for (int i = 0; i < n; i++)
        {
            string s = arr[i];
            TrieNode *temp = root;

            for (int j = 0; j < s.length(); j++)
            {
                temp = temp->children[s[j] - 'a'];
                if (temp->freq == 1)
                {
                    ans.push_back(s.substr(0, j + 1));
                    break;
                }
            }
        }
    }
};

// Time - O(N*length of each word) space - same
void findPrefix(string arr[], int n)
{
    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
    {
        t->InsertTrie(arr[i]);
    }

    vector<string> ans;

    t->findPrefixUtil(arr, ans, n);
}

int main()
{

    return 0;
}