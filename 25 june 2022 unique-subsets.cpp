// striver SDE sheet challange unique-subsets
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans = {{}};
    int start;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; ++i) {
        if(i == 0 || arr[i] != arr[i-1]) start = 0;
        for(int end = ans.size(); start < end; ++start) {
            vector<int> copy = ans[start];
            copy.push_back(arr[i]);
            ans.push_back(copy);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
