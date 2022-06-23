// striver SDE sheet challange maximum-meetings
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<vector<int>> arr(n, vector<int>(3));
    for(int i = 0; i < n; ++i) {
        arr[i][0] = start[i];
        arr[i][1] = end[i];
        arr[i][2] = i + 1;
    }
    sort(arr.begin(), arr.end());
    vector<int> ans;
    ans.push_back(0);
    for(int i = 1; i < n; ++i) {
        int lastEnd = arr[ans.back()][1];
        if(lastEnd < arr[i][0])
            ans.push_back(i);
        else if(lastEnd > arr[i][1] || (lastEnd == arr[i][1] && arr[ans.back()][2] > arr[i][2])) {
            ans.pop_back();
            ans.push_back(i);
        }
    }
    for(int i = 0; i < ans.size(); ++i) {
        ans[i] = arr[ans[i]][2];
    }
    return ans;
}
