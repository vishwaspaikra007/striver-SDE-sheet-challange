// striver SDE sheet challange copy-list-with-random-pointer
// author Vishwas Paikra
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *itr = head, *newHead, *itr2;
        if(head == NULL) return NULL;
        while(itr != NULL){
            itr2 = new Node(itr->val);
            itr2->next = itr->next;
            itr->next = itr2;
            itr = itr2->next;
        }
        newHead = head->next;
        itr = head;
        while(itr != NULL){
            if(itr->random != NULL) itr->next->random = itr->random->next;
            itr = itr->next->next;
        }
        itr = head;
        while(itr != NULL){
            itr2 = itr->next;
            itr->next = itr2->next;
            if(itr2->next != NULL) itr2->next = itr2->next->next;
            itr = itr->next;
        }
        return newHead;
    }
};
