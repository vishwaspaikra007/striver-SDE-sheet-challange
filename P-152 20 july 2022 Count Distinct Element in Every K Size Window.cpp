// striver SDE sheet challange Count Distinct Element in Every K Size Window
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    unordered_map<int, int> hash;
    vector<int> ans;
    int n = arr.size();
    for(int i = 0; i < k; ++i) {
        ++hash[arr[i]];
    }
    ans.push_back(hash.size());
	for(int i = k; i < n; ++i) {
        ++hash[arr[i]];
        if(--hash[arr[i-k]] == 0) {
                hash.erase(arr[i-k]);
        }
        ans.push_back(hash.size());
    }
    return ans;
}
