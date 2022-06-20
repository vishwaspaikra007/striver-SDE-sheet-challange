// striver SDE sheet challange intersection-of-linked-list
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

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *a = firstHead, *b = secondHead;
    while(a != b) {
        if(a == NULL) a = secondHead;
        else a = a->next;
        if(b == NULL) b = firstHead;
        else b = b->next;
    }
    return a ? a->data : -1;
}
