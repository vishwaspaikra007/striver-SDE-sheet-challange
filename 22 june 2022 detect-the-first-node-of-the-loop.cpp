// striver SDE sheet challange detect-the-first-node-of-the-loop
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

Node *firstNode(Node *head)
{
	Node *j1 = head, *j2 = head;
    while(j2 && j2->next) {
        j1 = j1->next;
        j2 = j2->next->next;
        if(j1 == j2) break;
    }
    if(j2 && j2->next) {
        j2 = head;
        int i = 0;
        while(j1 != j2) {
            j1 = j1->next;
            j2 = j2->next;
        }
        return j1;
    }
    return NULL;
}
