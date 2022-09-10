#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    // Node for doubly Linked  List
    // has data key as variable and next and previous as pointers
    class Node
    {
    public:
        int key, data;
        Node *next, *prev;

        // constructor
        Node(int _key, int _data)
        {
            key = _key;
            data = _data;
        }
    };

    // declare two dummy pointer head and tail to keep track of start and end of Doubly LL
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    // capacity to store max capacity of cache
    int cap;

    // map to store the elements present in cache in key and address pair
    unordered_map<int, Node *> mp;

    // constructor
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // add Node to doubly LL
    //  will always insert to next of head
    void addNode(Node *newNode)
    {
        // store current head next in temp
        Node *temp = head->next;

        // assign the newNode next to the current head's next and previous to head
        newNode->next = temp;
        newNode->prev = head;

        // assign the head's next as new Node and currrent head's next's previous to new Node
        temp->prev = newNode;
        head->next = newNode;
    }

    // delete Node from doubly LL
    //  will always delete from end node before tail
    void deleteNode(Node *delNode)
    {
        // store the previous and previous next node in temp nodes
        Node *delprev = delNode->prev;
        Node *delnext = delNode->next;

        // the next of previous node of delete is assigned to next node of delete Node and vice versa
        delprev->next = delnext;
        delnext->prev = delprev;

        // delete node pointer are set as NULL
        delNode->next = NULL;
        delNode->prev = NULL;

        // delete the delNode from memory
        delete (delNode);
    }

    // returns the value corresponding to key if present in cache
    int get(int key_)
    {
        // if key is present in map then it is present in cache
        if (mp.find(key_) != mp.end())
        {
            // store the node corresponding to key in a temp node and also the value
            Node *resNode = mp[key_];
            int res = resNode->data;

            // delete the key and value from map and Dobuly LL
            mp.erase(key_);
            deleteNode(resNode);

            // it will get re inserted as it will be the recently used node
            // add the node again and store the key and address
            addNode(resNode);
            mp[key_] = head->next;

            // return the data corresponding to key
            return res;
        }
        // if key not in map that means it is not in cache so -1
        else
            return -1;
    }

    // will insert the key and data in cache
    void put(int key_, int value)
    {
        // if the key is already present then we need to update it
        if (mp.find(key_) != mp.end())
        {
            // store the node found
            Node *resNode = mp[key_];

            // delete the node from LL and map as it will be recently used and will appear in front
            mp.erase(key_);
            deleteNode(resNode);
        }

        // if capacity is full then delete the least recently used
        // from the end of LL element before tail
        else if (mp.size() == cap)
        {
            Node *last = tail->prev;
            mp.erase(last->key);
            deleteNode(last);
        }

        // now add the new Node which will be next to head in LL and map
        addNode(new Node(key_, value));
        mp[key_] = head->next;
    }
};

int main()
{
    LRUCache Lru(2);
    cout << Lru.get(1) << endl;
    cout << Lru.get(3) << endl;

    Lru.put(2, 10);
    Lru.put(4, 200);
    cout << Lru.get(4) << endl;
    Lru.put(5, 100);
    cout << Lru.get(2) << endl;

    return 0;
}