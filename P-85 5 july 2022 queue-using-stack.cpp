// striver SDE sheet challange queue-using-stack
// author Vishwas Paikra
#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> st1, st2;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        st1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(st1.size() == 0) return -1;
        while(st1.size() != 1) {
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st1.top();
        st1.pop();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }

    int peek() {
        // Implement the peek() function here.
        if(st1.size() == 0) return -1;
        while(st1.size() != 1) {
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st1.top();
        st2.push(temp);
        st1.pop();
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st1.empty();
    }
};
