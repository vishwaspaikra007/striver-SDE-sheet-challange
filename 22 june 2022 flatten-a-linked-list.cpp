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
            head = head->child;
            root = root->child;
        } else {
            head->child = t1;
            head = head->child;
            t1 = t1->child;
        }
    }
    while(root) {
        head->child = root;
        head = head->child;
        root = root->child;
    }
    while(t1) {
        head->child = t1;
        head = head->child;
        t1 = t1->child;
    }
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
    Node *root = head, *t1 = head->next;
    while(t1) {
        root = mergeList(root, t1);
        t1 = t1->next;
    }
    return root;
}
