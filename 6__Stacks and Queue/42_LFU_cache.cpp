#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key, data, count;
    Node *next, *prev;

    Node(int _key, int _data)
    {
        key = _key;
        data = _data;
        count = 1;
    }
};

struct List
{
    int size;
    Node *head, *tail;

    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;

        size = 0;
    }

    void addFront(Node *node)
    {
        Node *temp = head->next;

        node->prev = head;
        node->next = temp;

        head->next = node;
        temp->prev = node;

        size++;
    }

    void removeBack(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;

        delprev->next = delnext;
        delnext->prev = delprev;

        size--;
    }
};

class LFUcache
{
public:
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int maxCachesize;
    int cursize;
    int minFreq;

    LFUcache(int capacity)
    {
        maxCachesize = capacity;
        cursize = 0;
        minFreq = 0;
    }

    void updateFreqListMap(Node *upnode)
    {
        // when a node is passed to update it frequency then it's location will for sure change based on frequency
        // so delete node from current DLL of freqlist and keymode map
        keyNode.erase(upnode->key);
        freqListMap[upnode->count]->removeBack(upnode);

        // if node has min frequency and it was the only element in that particular freq list hen increase the min frequency as the next frequency will not become min
        if (upnode->count == minFreq && (freqListMap[upnode->count]->size == 0))
        {
            minFreq++;
        }

        // now create a new List for the new frequency
        List *nexthighfreqList = new List();

        // check if that particular frequency is present in freqlist map
        // if yes then need to assign that DLL to the newly created List
        // if no then the newly created List will be used to push element in it
        if (freqListMap.find(upnode->count + 1) != freqListMap.end())
        {
            nexthighfreqList = freqListMap[upnode->count + 1];
        }

        // now update the frequency in the node
        upnode->count += 1;

        // then add the node to the DLL
        nexthighfreqList->addFront(upnode);

        // and then assign the DLL to map of the new frequency
        freqListMap[upnode->count] = nexthighfreqList;

        // add the key and node to keynode map
        keyNode[upnode->key] = upnode;
    }

    int get(int key)
    {
        // if key is present in keynode map then store the node
        // and update the node according to frequencyanddsiplay the value of the key
        if (keyNode.find(key) != keyNode.end())
        {
            Node *resNode = keyNode[key];
            int res = resNode->data;

            updateFreqListMap(resNode);
            return res;
        }
        // else return -1
        else
            return -1;
    }

    void put(int key, int value)
    {
        // just in case maxsize of cache is 0 return
        if (maxCachesize == 0)
            return;

        // if a key is present it will be keynode map
        // store the node with key and add value to it and update the node's position based on frequency
        if (keyNode.find(key) != keyNode.end())
        {
            Node *resnode = keyNode[key];
            resnode->data = value;
            updateFreqListMap(resnode);
        }

        // if not present need to add new node
        else
        {
            // if cache is full need to delete the LFU and if same frequency has multiplenodes then delete LRU
            if (cursize == maxCachesize)
            {
                // store the min frequency list in a temp list
                List *list = freqListMap[minFreq];

                // delete the prev node to tail node from keynode map and freqlist
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeBack(list->tail->prev);

                // decrease the current size of cache
                cursize--;
            }

            // now after node and position update need to add the key value pair
            // increase current size of cache
            cursize++;

            // again set min freq to 1
            minFreq = 1;

            // create a temp list
            List *listfreq = new List();

            // check if min frequency has a list already then assign that list to temp list
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listfreq = freqListMap[minFreq];
            }

            // create a new node to sotre the key and value pair
            Node *newnode = new Node(key, value);

            // add the new node to the temp list created
            listfreq->addFront(newnode);

            // update the keynode and freq list
            keyNode[key] = newnode;
            freqListMap[minFreq] = listfreq;
        }
    }
};

int main()
{
    //["LFUCache","put","put","get","put","get","get","put","get","get","get"]
    //[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]

    LFUcache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << endl;
    lfu.put(3, 3);
    cout << lfu.get(2) << endl;
    cout << lfu.get(3) << endl;
    lfu.put(4, 4);
    cout << lfu.get(1) << endl;
    cout << lfu.get(3) << endl;
    cout << lfu.get(4) << endl;
    return 0;
}