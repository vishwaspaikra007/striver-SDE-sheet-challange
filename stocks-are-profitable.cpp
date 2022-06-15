// striver SDE sheet challange stocks-are-profitable
// author Vishwas Paikra
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size(), maxi=0;
    for(int i=0,j=0;i<n;++i) {
        if(prices[j]>prices[i]) j = i;
        maxi = max(maxi, prices[i]-prices[j]);
    }
    return maxi;
}
