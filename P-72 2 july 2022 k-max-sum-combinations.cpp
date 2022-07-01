// striver SDE sheet challange k-max-sum-combinations
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    priority_queue<pair<int, pair<int, int>>> p;
    set<pair<int, int>> s;
    vector<int> ans;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    p.push({a[n-1] + b[n-1], {n-1, n-1}});
    s.insert({n-1, n-1});
    while(k > 0) {
        int sum = p.top().first;
        int x = p.top().second.first;
        int y = p.top().second.second;
        p.pop();
        ans.push_back(sum);
        if(s.find({x-1, y}) == s.end()) {
            p.push({a[x-1]+b[y],{ x-1, y}});
            s.insert({x-1, y});
        }
        if(s.find({x, y-1}) == s.end()) {
            p.push({a[x]+b[y-1], {x, y-1}});
            s.insert({x, y-1});
        }
        --k;
    }
    return ans;
}
