// striver SDE sheet challange Longest Increasing Subsequence
// author Vishwas Paikra
#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> ans;
    int len = 0;
    for(int i = 0; i < n; ++i) {
        if(ans.empty() || ans[len-1] < arr[i]) {
            ans.push_back(arr[i]);
            ++len;
        } else {
            auto itr = lower_bound(begin(ans), end(ans), arr[i]);
            *itr = arr[i];
        }
    }
    return len;
}
