// striver SDE sheet challange combination-sum-ii
// author Vishwas Paikra
#include<bits/stdc++.h>
void bt(vector<vector<int>> &ans, vector<int> &temp, vector<int> &arr, int i, int n, int target) {
    if(target == 0){
        ans.push_back(temp);
        return;
    }
    for(int j = i; j < n; ++j) {
        if(j != i && arr[j] == arr[j-1]) continue;
        temp.push_back(arr[j]);
        bt(ans, temp, arr, j+1, n, target - arr[j]);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    bt(ans, temp, arr, 0, n, target);
    sort(ans.begin(), ans.end());
    return ans;
}
