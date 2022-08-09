// striver SDE sheet challange Median in a stream
// author Vishwas Paikra
#include<bits/stdc++.h>
void insert(int x, priority_queue<int>  &small, priority_queue<int>  &large) {
    small.push(x);
    large.push(-small.top());
    small.pop();
    if(small.size() < large.size()) {
        small.push(-large.top());
        large.pop();
    }
}

int get_median(priority_queue<int>  &small, priority_queue<int>  &large) {
    return small.size() > large.size() ?
        small.top() : (small.top() - large.top())/2;
}

vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int> small, large;
    vector<int> ans;
    for(int x : arr) {
        insert(x, small, large);
        ans.push_back(get_median(small, large));
    }
    return ans;
}
