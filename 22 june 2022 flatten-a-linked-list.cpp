// striver SDE sheet challange flatten-a-linked-list
// author Vishwas Paikra
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node *mergeList(Node *root, Node *t1) {
    Node *head = new Node(0), *res = head;
    while(root && t1) {
        if(root->data < t1->data) {
            head->child = root;
            root = root->child;
        } else {
            head->child = t1;
            t1 = t1->child;
        }
        head = head->child; 
        head->next = NULL;
    }
    if(root) head->child = root;
    else head->child = t1;
    head->next = NULL;
    return res->child;
}
Node* flattenLinkedList(Node* root) 
{
    if(!root || !(root->next)) return root;
    root->next = flattenLinkedList(root->next);
    root = mergeList(root, root->next);
}
