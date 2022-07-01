// striver SDE sheet challange kth-smallest-and-largest-element-of-array
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	sort(begin(arr), end(arr));
    return {arr[k-1], arr[n - k]};
}
