// striver SDE sheet challange lru-cache-implementation
// author Vishwas Paikra
#include<bits/stdc++.h>
struct Node {
    int key = -1;
    int val = -1;
    Node *next = NULL;
    Node *prev = NULL;
};
class LRUCache
{
    Node *head, *tail;
    unordered_map<int, Node*> hash;
    int capacity;
public:
    LRUCache(int capacity)
    {
        // Write your code here
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        // Write your code here
        if(hash.find(key) != hash.end()) {
            Node *t1 = hash[key];
            t1->prev->next = t1->next;
            t1->next->prev = t1->prev;
            
            Node *temp = new Node();
            temp->key = t1->key;
            temp->val = t1->val;
            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;
            hash[key] = temp;
            return hash[key]->val;
        }
        return -1;
    }

    void put(int key, int val)
    {
        // Write your code here
        if(hash.size() == capacity && hash.find(key) == hash.end()) {
            Node *temp = tail->prev;
            temp->prev->next = tail;
            tail->prev = temp->prev;
            hash.erase(temp->key);
        } else if(hash.find(key) != hash.end()) {
            Node *temp = hash[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        Node *temp = new Node();
        temp->key = key;
        temp->val = val;
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;
        hash[key] = temp;
    }
};
