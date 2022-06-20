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
// striver SDE sheet challange middle-of-linked-list
// author Vishwas Paikra
Node *findMiddle(Node *head) {
    // Write your code here
    Node *r1 = head, *r2 = head;
    while(r2 && r2->next) {
        r1 = r1->next;
        r2 = r2->next->next;
    }
    return r1;
}
