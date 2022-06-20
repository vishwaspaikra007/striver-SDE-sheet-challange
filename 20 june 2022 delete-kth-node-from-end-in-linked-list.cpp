// striver SDE sheet challange delete-kth-node-from-end-in-linked-list
// author Vishwas Paikra
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    // Write your code here.
    LinkedListNode<int> *newHead 
        = new LinkedListNode<int>(1), *first = newHead, *second = newHead;
    newHead->next = head;
    if(!head || !K) return head;
    for(int i=1;i<=K;++i) first = first->next;
    while(first->next) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return newHead->next;
}
