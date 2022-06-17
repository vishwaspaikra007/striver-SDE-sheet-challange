// striver SDE sheet challange majority-element
// author Vishwas Paikra
#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    unordered_map<int, int> cnt;
    for(int i=0;i<n;++i) {
        ++cnt[arr[i]];
    }
    for(auto obj: cnt) {
        if(obj.second > floor(n/2))
            return obj.first;
    }
    return  -1;
}
