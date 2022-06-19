// striver SDE sheet challange longest-consecutive-sequence
// author Vishwas Paikra
#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    int curr = arr[0];
    int cnt = 1, maxi = 1;
    for(int i=1;i<n;++i) {
        if(curr == arr[i]) continue;
        else if(++curr == arr[i]) ++cnt;
        else {
            cnt = 1;
            curr = arr[i];
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}
