// striver SDE sheet challange reverse-pairs
// author Vishwas Paikra
#include <bits/stdc++.h> 
int merge(vector<int> &arr, vector<int> &temp, int l, int m, int r) {
    int i = l, j = m, k = l;
    int cnt = 0;
    while(i < m && j <= r) {
        if(arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            int x = i, y = m-1;
            while(x <= y) {
                int mid = x+(y-x)/2;
                if(arr[mid] > 2*arr[j]) {
                    y = mid - 1;
                } else x = mid + 1;
            }
            cnt += m - x;
            temp[k++] = arr[j++];
        }
    }
    while(i < m) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];
    for(i = l;i<=r;++i) arr[i] = temp[i];
    return cnt;
}
int mergeSort(vector<int> &arr, vector<int> &temp, int l, int r) {
    int cnt = 0;
    if(l < r) {
        int m = l+(r-l)/2;
        cnt += mergeSort(arr, temp, l, m);
        cnt += mergeSort(arr, temp, m+1, r);
        cnt += merge(arr, temp, l, m+1, r);
    }
    return cnt;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
    vector<int> temp(n);
    return mergeSort(arr, temp, 0, n-1);
}
