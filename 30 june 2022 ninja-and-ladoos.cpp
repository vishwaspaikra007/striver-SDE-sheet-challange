// striver SDE sheet challange ninja-and-ladoos
// author Vishwas Paikra
#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(m > n) {
        return ninjaAndLadoos(row2, row1, n, m, k);
    }
    int left = max(0, k - n), right = min(k, m);
    while(left <= right) {
        int cut1 = (left + right) >> 1;
        int cut2 = k - cut1;
        int l1 = cut1 == 0 ? INT_MIN : row1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : row2[cut2 - 1];
        int r1 = cut1 == m ? INT_MAX : row1[cut1];
        int r2 = cut2 == n ? INT_MAX : row2[cut2];
        
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } 
        else if(l1 > r2) {
            right = cut1 - 1;
        }
        else {
            left = cut1 + 1;
        }
    }
    return 1;
}
