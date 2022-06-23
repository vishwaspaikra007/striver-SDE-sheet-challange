// striver SDE sheet challange trapping-rainwater
// author Vishwas Paikra
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    int i = 0, x = 0, y = n;
    long long int sum = 0;
    n -= 1;
    while(i < n) {
        if(arr[i] < arr[n]) {
            if(arr[i] > arr[++x])
                sum += arr[i] - arr[x];
            else {
                i = x;
            }
        } else {
            if(arr[n] > arr[--y])
                sum += arr[n] - arr[y];
            else {
                n = y;
            }
        }
    }
    return sum;
}
