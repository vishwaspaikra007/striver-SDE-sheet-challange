// striver SDE sheet challange next-greater-element
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    stack<int> stk;
    vector<int> ans(n);
    for(int i = n-1; i >= 0; --i) {
        while(!stk.empty() && arr[i] >= stk.top()) stk.pop();
        ans[i] = !stk.empty() ? stk.top() : -1;
        stk.push(arr[i]);
    }
    return ans;
}
