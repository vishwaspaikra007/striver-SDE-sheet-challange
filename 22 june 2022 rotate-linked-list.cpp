// striver SDE sheet challange rotate-linked-list
// author Vishwas Paikra
#include <bits/stdc++.h> 
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
    	public:
    	    int data;
    	    Node *next;
    	    Node(int data)
    	    {
    	        this->data = data;
    	        this->next = NULL;
    	    }
    };

********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    Node *root = head, *newHead, *prev = head;
    int n = 0;
    while(root) {
        ++n;
        root = root->next;
    }
    k %= n;
    root = head;
    while(root->next) {
        if(--k < 0) prev = prev->next;
        root = root->next;
    }
    if(!prev->next) return head;
    newHead = prev->next;
    root->next = head;
    prev->next = NULL;
    return newHead;
}
