// striver SDE sheet challange maximum-activities
// author Vishwas Paikra
#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> ans(n);
    for(int i = 0; i < n; ++i) {
        ans[i] = {finish[i], start[i]};
    }
    sort(ans.begin(), ans.end());
    int last = ans[0].first, cnt = 1;
    for(int i = 1; i < n; ++i) {
        if(last <= ans[i].second) {
            ++cnt;
            last = ans[i].first;
        }
    }
    return cnt;
}
