// striver SDE sheet challange stack-implementation-using-array
// author Vishwas Paikra
// Stack class.
class Stack {
    int *list;
    int idx;
    int n;
public:
    
    Stack(int capacity) {
        list = new int[capacity];
        idx = -1;
        n = capacity;
    }

    void push(int num) {
       list[++idx] = num;
    }

    int pop() {
        return idx > -1 ? list[idx--] : -1;
    }
    
    int top() {
        return idx > -1 ? list[idx] : -1;
    }
    
    int isEmpty() {
        return idx == -1;
    }
    
    int isFull() {
        return idx == n-1;
    }
    
};
