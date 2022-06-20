// striver SDE sheet challange add-two-numbers-as-linked-lists
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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    int carry = 0, sum;
    Node *head = new Node(0), *root = head;
    while(head1 && head2) {
        sum = head1->data + head2->data + carry;
        carry = sum / 10;
        sum %= 10;
        head->next = new Node(sum);
        head = head->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1) {
        sum = head1->data + carry;
        carry = sum / 10;
        sum %= 10;
        head->next = new Node(sum);
        head = head->next;
        head1 = head1->next;
    }
    while(head2) {
        sum = head2->data + carry;
        carry = sum / 10;
        sum %= 10;
        head->next = new Node(sum);
        head = head->next;
        head2 = head2->next;
    }
    if(carry) {
        head->next = new Node(1);
    }
    return root->next;
}
