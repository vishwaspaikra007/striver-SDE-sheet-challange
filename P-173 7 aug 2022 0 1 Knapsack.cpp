// striver SDE sheet challange 0 1 Knapsack
// author Vishwas Paikra
#include<bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int W)
{
	vector<vector<int>> dp(n, vector<int>(W+1, 0));

    for(int i = weights[0]; i <= W; ++i)
        dp[0][i] = values[0];
    
    for(int i = 1; i < n; ++i) {
        for(int cap = 0; cap <= W; ++cap) {
            int nottaken = dp[i-1][cap];
            int taken = INT_MIN;
            if(weights[i] <= cap) {
                taken = values[i] + dp[i-1][cap - weights[i]];
            }
            dp[i][cap] = max(taken, nottaken);
        }
    }
    return dp[n-1][W];
}
