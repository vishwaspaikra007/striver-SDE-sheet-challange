// striver SDE sheet challange ninja-and-sorted-arrays
// author Vishwas Paikra

#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    for(int i=m+n-1;i>-1;--i) {
        if(arr1[m-1] > arr2[n-1]) arr1[i] = arr1[--m];
        else arr1[i] = arr2[--n];
    }
    return arr1;
}
