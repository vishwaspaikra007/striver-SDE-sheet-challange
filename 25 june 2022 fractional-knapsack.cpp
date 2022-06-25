// striver SDE sheet challange fractional-knapsack
// author Vishwas Paikra
#include<bits/stdc++.h>
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    vector<pair<double, int>> val(n);
    for(int i = 0; i < n; ++i) {
        val[i] = make_pair(items[i].second/(double)items[i].first, i);
    }
    sort(val.begin(), val.end());
    double cnt = 0;
    for(int i = n-1; i > -1; --i) {
        if(w >= items[val[i].second].first) {
            w -= items[val[i].second].first;
            cnt += items[val[i].second].second;
        } else {
            cnt += (w/(double)items[val[i].second].first) * items[val[i].second].second;
            break;
        }
    }
    return cnt;
}
