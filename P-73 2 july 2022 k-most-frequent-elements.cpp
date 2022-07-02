// striver SDE sheet challange k-most-frequent-elements
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int, int> hash;
    vector<pair<int, int>> ans;
    vector<int> res;
    for(int i: arr) {
        ++hash[i];
    }
    for(auto x : hash) {
        ans.emplace_back(x.second, x.first);
    }
    sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    });
    for(int i = k-1; i > -1; --i) {
        res.push_back(ans[i].second);
    }
    sort(res.begin(), res.end());
    return res;
}
