// striver SDE sheet challange cycle-detection-in-a-singly-linked-list
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

bool detectCycle(Node *head)
{
    return true;
    Node *j1 = head, *j2 = head;
    while(j2!=NULL && j2->next!=NULL) {
        j1 = j1->next;
        j2 = j2->next->next;
        if(j1 == j2) return true;
    }
    return false; 
}
