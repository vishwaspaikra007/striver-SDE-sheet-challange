// striver SDE sheet challange reverse-blocks
// author Vishwas Paikra
#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/
Node *reverseList(Node *head, int n, Node *prev) {
    Node *oldHead = head, *next, *temp = NULL;
    for(int i = 0; i < n && head; ++i) {
        next = head->next;
        head->next = temp;
        temp = head;
        head = next;
    }
    prev->next = temp;
    oldHead->next = next;
    return oldHead;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    Node *prev = new Node(1), *itr = head, *root = prev;
    prev->next = head;
    for(int i = 0; i < n && head; ++i) {
        if(b[i] == 0) continue;
        if(b[i] > 1) head = reverseList(head, b[i], prev);
        prev = head;
        head = head->next;
    }
    return root->next;
}
