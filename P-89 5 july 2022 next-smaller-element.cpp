// striver SDE sheet challange next-smaller-element
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> stk;
    vector<int> ans(n);
    for(int i = n-1; i >= 0; --i) {
        while(!stk.empty() && arr[i] <= stk.top()) stk.pop();
        ans[i] = stk.empty() ? -1 : stk.top();
        stk.push(arr[i]);
    }
    return ans;
}
