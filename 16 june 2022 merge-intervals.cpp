// striver SDE sheet challange merge-intervals
// author Vishwas Paikra
#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    vector<int> temp(2);
    temp[0]=intervals[0][0];
    temp[1]=intervals[0][1];
    int n = intervals.size();
    for(int i=1;i<n;++i) {
        if(temp[0] <= intervals[i][0] && intervals[i][0] <= temp[1])
            temp[1] = max(temp[1], intervals[i][1]);
        else {
            ans.push_back(vector<int>{temp[0], temp[1]});
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
        }
    }
    ans.push_back(vector<int>{temp[0], temp[1]});
    return ans;
}
