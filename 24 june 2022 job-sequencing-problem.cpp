// striver SDE sheet challange job-sequencing-problem
// author Vishwas Paikra
#include<bits/stdc++.h>
int jobScheduling(vector<vector<int>> &jobs)
{
    priority_queue<int, vector<int>, greater<int>> p;
    sort(jobs.begin(), jobs.end());
    int cnt = 0, n = jobs.size(), timeConsumed = 0;
    for(int i = 0; i < n; ++i) {
        if(p.size() < jobs[i][0]) {
            p.push(jobs[i][1]);
            cnt += jobs[i][1];
        } else if(p.top() < jobs[i][1]) {
            cnt -= p.top();
            p.pop();
            p.push(jobs[i][1]);
            cnt += jobs[i][1];
        }
    }
    return cnt;
}
