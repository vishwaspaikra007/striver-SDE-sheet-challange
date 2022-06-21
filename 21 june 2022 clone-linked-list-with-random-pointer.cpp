// striver SDE sheet challange clone-linked-list-with-random-pointer
// author Vishwas Paikra
#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *itr=head, *dummy, *root;
    while(itr!=NULL)
    {  
        dummy = new LinkedListNode<int> (itr->data);
        dummy->next = itr->next;
        itr->next = dummy;
        itr = dummy->next;
    }
   itr=head;
   while(itr!=NULL)
   {
       itr->next->random = itr->random;
       itr=itr->next->next;
   }
   itr=head;
   root = new LinkedListNode<int> (0), dummy = root;
   while(itr!=NULL)
   {
       dummy->next = itr->next;
       itr->next = itr->next->next;
       itr = dummy->next->next;
       dummy = dummy->next;
   }
   return root->next  ;
}
