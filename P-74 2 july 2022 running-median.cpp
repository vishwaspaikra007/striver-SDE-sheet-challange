// striver SDE sheet challange running-median
// author Vishwas Paikra
#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> first;
    priority_queue<int, vector<int>, greater<int>> sec;
    vector<int> ans;
    for(int i = 0; i < n; ++i) {
        if(first.empty() || first.top() > arr[i]) first.push(arr[i]);
        else sec.push(arr[i]);
        
        if(first.size() > sec.size() + 1) {
            sec.push(first.top());
            first.pop();
        } else if(sec.size() > first.size() + 1) {
            first.push(sec.top());
            sec.pop();
        }
        
        if(first.size() == sec.size()) {
            ans.push_back((first.top() + sec.top()) / 2);
        } else if(first.size() > sec.size()) {
            ans.push_back(first.top());
        } else {
            ans.push_back(sec.top());
        }
    }
    for(int i: ans)
        cout<<i<<" ";
    cout<<'\n';
}
