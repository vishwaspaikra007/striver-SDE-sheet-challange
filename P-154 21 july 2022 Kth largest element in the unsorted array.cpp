// striver SDE sheet challange Kth largest element in the unsorted array
// author Vishwas Paikra
#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int K)
{
	sort(arr.begin(), arr.end());
    return arr[size-K];
}
