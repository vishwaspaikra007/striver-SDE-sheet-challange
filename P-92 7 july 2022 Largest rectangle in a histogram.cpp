// striver SDE sheet challange Largest rectangle in a histogram
// author Vishwas Paikra
#include<bits/stdc++.h> 
int largestRectangle(vector < int > & heights) {
   // Write your code here.
    stack<int> stk;
    int n = heights.size();
    int maxi = 0;
    stk.emplace(-1);
    for(int i = 0; i < n; ++i) {
        while(stk.top() >= 0 && heights[stk.top()] > heights[i]) {
            auto top = stk.top();
            stk.pop();
            maxi = max(maxi, heights[top]*(i - stk.top() - 1));
        }
        stk.emplace(i);
    }
    while(stk.top() != -1) {
        auto top = stk.top();
        stk.pop();
        maxi = max(maxi, heights[top]*(n - stk.top() - 1));
    }
    return maxi;
 }
