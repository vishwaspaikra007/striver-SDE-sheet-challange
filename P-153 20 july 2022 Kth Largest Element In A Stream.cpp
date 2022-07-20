// striver SDE sheet challange Kth Largest Element In A Stream
// author Vishwas Paikra
#include<bits/stdc++.h>
class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> p;
    int k;
public:
    Kthlargest(int k, vector<int> &arr) {
       this->k = k;
       for(int x : arr)
           p.push(x);
    }

    void add(int num) {
        p.push(num);
        p.pop();
    }

    int getKthLargest() {
       return p.top();
    }

};
