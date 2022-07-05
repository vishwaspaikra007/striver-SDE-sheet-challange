// striver SDE sheet challange queue-using-array-or-singly-linked-list
// author Vishwas Paikra
struct Node {
    int val = -1;
    Node *next = NULL;
};
class Queue {
    Node *root;
    Node *tail;
public:
    Queue() {
        // Implement the Constructor
        Node *temp = new Node();
        root = tail = temp;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return root->val == -1;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        tail->val = data;
        tail->next = new Node();
        tail = tail->next;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(root->val == -1) return -1;
        int temp = root->val;
        root = root->next;
        return temp;
    }

    int front() {
        // Implement the front() function
        return root->val;
    }
};
