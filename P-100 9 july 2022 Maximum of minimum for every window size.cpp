// striver SDE sheet challange Maximum of minimum for every window size
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int> temp1, temp2;
    vector<int> left(n), right(n), ans(n+1, INT_MIN);
    for(int i = n-1, j = 0; i >= 0; --i, ++j) {
        while(!temp1.empty() && a[temp1.top()] >= a[i])
            temp1.pop();
        right[i] = temp1.empty() ? n : temp1.top();
        temp1.push(i);
        
        while(!temp2.empty() && a[temp2.top()] >= a[j])
            temp2.pop();
        left[j] = temp2.empty() ? -1 : temp2.top();
        temp2.push(j);
    }
    for(int i = 0; i < n; ++i) {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }
    for(int i = n-1; i >= 0; --i) {
        ans[i] = max(ans[i], ans[i+1]);
    }
    for(int i = 1; i <= n; ++i) {
        ans[i-1] = ans[i];
    }
    ans.pop_back();
    return ans;
}
