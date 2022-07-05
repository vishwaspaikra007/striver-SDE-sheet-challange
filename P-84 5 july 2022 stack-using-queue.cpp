// striver SDE sheet challange stack-using-queue
// author Vishwas Paikra
#include<bits/stdc++.h>
class Stack {
	// Define the data members.
   queue<int> list1, list2;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return list1.size() | list2.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return list1.size() == list2.size();
    }

    void push(int element) {
        // Implement the push() function.
        if(list1.size() != 0) {
            list1.push(element);
        } else {
            list2.push(element);
        }
        
    }

    int pop() {
        // Implement the pop() function.
        if(list1.size() == list2.size()) return -1;
        if(list1.size() != 0) {
            while(list1.size()!=1) {
                list2.push(list1.front());
                list1.pop();
            }
            int temp = list1.front();
            list1.pop();
            return temp;
        } else {
            while(list2.size()!=1) {
                list1.push(list2.front());
                list2.pop();
            }
            int temp = list2.front();
            list2.pop();
            return temp;
        }
    }

    int top() {
        // Implement the top() function.
        if(list1.size() == list2.size()) return -1;
        if(list1.size() != 0) {
            while(list1.size()!=1) {
                list2.push(list1.front());
                list1.pop();
            }
            int temp = list1.front();
            list2.push(list1.front());
            list1.pop();
            return temp;
        } else {
            while(list2.size()!=1) {
                list1.push(list2.front());
                list2.pop();
            }
            int temp = list2.front();
            list1.push(list2.front());
            list2.pop();
            return temp;
        }
    }
};
