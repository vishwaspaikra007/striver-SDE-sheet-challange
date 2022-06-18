// striver SDE sheet challange pair-sum
// author Vishwas Paikra
#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    sort(arr.begin(), arr.end());
    int i = 0, n = arr.size()-1, sum;
    vector<vector<int>> ans;
    while(i < n) {
        sum = arr[i] + arr[n];
        if(sum == s) {
            int j = i, k = n, cnt1 = 1, cnt2 = 1, y;
            while(arr[i] == arr[++j]) ++cnt1;
            if(arr[i] != arr[n]) {
                while(arr[n] == arr[--k]) ++cnt2;
                y = cnt1*cnt2;
            } else {
                y = cnt1*(cnt1-1)/2;
            }
            for(int x=0;x<y;++x) ans.push_back({arr[i], arr[n]});
            i = j;
            n = k;
        }
        else if(sum < s) ++i;
        else --n;
    }
    return ans;
}
