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
// striver SDE sheet challange reverse-the-singly-linked-list
// author Vishwas Paikra
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prev = NULL;
    while(head) {
        LinkedListNode<int> *node = new LinkedListNode<int>(head->data);
        node->next = prev;
        prev = node;
        head = head->next;
    }
    return prev;
}
