// striver SDE sheet challange longest-subset-zero-sum
// author Vishwas Paikra
#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size(), maxi = 0;
    unordered_map<int, int> hash;
    for(int i=1;i<n;++i) {
        arr[i] += arr[i-1];
        if(!arr[i]) maxi = i + 1;
        else if(!hash[arr[i]]) hash[arr[i]] = i;
        else maxi = max(maxi, i - hash[arr[i]]);
    }
    return maxi;
}
