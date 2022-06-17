// striver SDE sheet challange count-inversions
// author Vishwas Paikra
#include <bits/stdc++.h> 
#define ll long long

ll merge(ll *arr, vector<ll> &temp, int l, int m, int r) {
    int i = l, j = m, k = l;
    ll cnt = 0;
    while(i < m && j <= r) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            cnt += m - i;
        }
    }
    while(i<m) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];
    for(i = l; i<=r; ++i) arr[i] = temp[i];
    return cnt;
}
ll mergeSort(ll *arr, vector<ll> &temp, int l, int r) {
    ll cnt = 0;
    if(l < r) {
        int mid = l+(r-l)/2;
        cnt += mergeSort(arr, temp, l, mid);
        cnt += mergeSort(arr, temp, mid+1, r);
        cnt += merge(arr, temp, l, mid+1, r);
    }
    return cnt;
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    vector<ll> temp(n);
    return mergeSort(arr, temp, 0, n-1);
}
