// striver SDE sheet challange palindrom-linked-list
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
LinkedListNode<int> *reverseList(LinkedListNode<int> *head) {
    LinkedListNode<int> *prev = NULL, *temp;
    while(head) {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int> *j1 = head, *j2 = head;
    while(j2 && j2->next) {
        j1 = j1->next;
        j2 = j2->next->next;
    }
    if(j2) j1 = j1->next;
    j2 = head;
    j1 = reverseList(j1);
    while(j1) {
        if(j1->data != j2->data) return false;
        j1 = j1->next;
        j2 = j2->next;
    }
    return true;
}
