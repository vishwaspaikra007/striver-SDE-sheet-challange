// striver SDE sheet challange Online Stock Span
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    vector<int> ans(n);
    stack<int> stk;
    stk.push(-1);
    for(int i = 0; i < n; ++i) {
        while(stk.top() != -1 && price[stk.top()] <= price[i])
            stk.pop();
        ans[i] = i - stk.top();
        stk.push(i);
    }
    return ans;
}
