// striver SDE sheet challange minimum-number-of-platforms
// author Vishwas Paikra
#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int cnt = 0, maxi = 0;
    for(int i = 0, j = 0; i < n; ++i) {
        ++cnt;
        if(at[i] > dt[j]) {
            --cnt;
            ++j;
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}
