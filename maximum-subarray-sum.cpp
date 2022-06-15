// striver SDE sheet challange maximum-subarray-sum
// author Vishwas Paikra
#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0, maxi = 0;
    for(int i=0;i<n;++i) {
        sum += arr[i];
        sum = max((long long)0, sum);
        maxi = max(maxi, sum);
    }
    return maxi;
}
