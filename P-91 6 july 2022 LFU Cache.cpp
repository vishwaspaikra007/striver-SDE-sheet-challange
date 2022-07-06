// striver SDE sheet challange LFU Cache
// author Vishwas Paikra
#include<bits/stdc++.h>
class Node {
    int key, val, fre;
    public:
        Node *prev, *next;
        Node(int key, int val, int fre) {
            this->key = key;
            this->val = val;
            this->fre = fre;
        }
        Node() {
            key = val = fre = -1;
        }
        int getKey() { return key; }
        int getVal() { return val; }
        int getFre() { return fre; }
};
class LRUCache {
    Node *head, *tail;
    public:
    LRUCache() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    bool empty() {
        return head->next->getKey() == -1;
    }
    Node *insert(int key, int val, int fre) {
        Node *temp = new Node(key, val, fre);
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
        return temp;
    }
    int pop() {
        int key = tail->prev->getKey();
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        return key;
    }
};
class LFUCache
{
    unordered_map<int , Node *> hash;
    unordered_map<int , LRUCache *> fHash;
    int capacity, minFre, currSize;
public:
    Node *newList() {

    }
    LFUCache(int capacity)
    {
        // Write your code here.
       this->capacity = capacity;
       minFre = 1;
       currSize = 0;
       fHash[1] = new LRUCache();
    }
    void remove(Node *temp) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    int get(int key)
    {
        if(hash.find(key) == hash.end()) return -1;
        int fre = hash[key]->getFre();
        int val = hash[key]->getVal();
        remove(hash[key]);
        if(!fHash[fre+1])
            fHash[fre+1] = new LRUCache();
        fHash[fre+1]->insert(key, val, fre+1);
        return val;
    }

    void put(int key, int value)
    {
        if(hash.find(key) == hash.end()) {
            if(currSize == capacity) {
                int key = fHash[minFre]->pop();
                hash.erase(key);
            }
            else ++currSize;
            hash[key] = fHash[1]->insert(key, value, 1);
            minFre = 1;
        } else {
            Node *temp = hash[key];
            if(!fHash[temp->getFre()+1])
                fHash[temp->getFre()+1] = new LRUCache();
            hash[key] = fHash[temp->getFre()+1]->insert(key, value, temp->getFre()+1);
            remove(temp);
            if(temp->getFre() == minFre && fHash[minFre]->empty())
                minFre += 1;
        }
    }
};
