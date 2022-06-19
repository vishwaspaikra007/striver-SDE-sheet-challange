// striver SDE sheet challange find-four-elements-that-sums-to-a-given-value
// author Vishwas Paikra
#include <bits/stdc++.h> 
string fourSum(vector<int> nums, int target, int n) {
    // Write your code here.
    unordered_map<int, array<int, 3>> sums;
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            int sum = nums[i]+nums[j];
            int rem = target - sum;
            if(sums[rem][0] && 
               sums[rem][1] != i && 
               sums[rem][1] != j &&
               sums[rem][2] != i &&
               sums[rem][2] != j) return "Yes";
            sums[sum] = {1, i, j}; 
        }
    }
    return "No";
}
