// striver SDE sheet challange merge-two-sorted-linked-lists
// author Vishwas Paikra
#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int> *root = new Node<int>(0), *head = root;
    while(first && second) {
        if(first->data < second->data) {
            root->next = new Node<int>(first->data);
            first = first->next;
        } else {
            root->next = new Node<int>(second->data);
            second = second->next;
        }
        root = root->next;
    }
    while(first) {
        root->next = new Node<int>(first->data);
        root = root->next;
        first = first->next;
    }
     while(second) {
        root->next = new Node<int>(second->data);
        root = root->next;
        second = second->next;
    }
    return head->next;
}
