// striver SDE sheet challange pascal-s-triangle
#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> ans;
    ans.push_back(vector<long long int>{1});
    if(n == 1) return ans;
    ans.push_back(vector<long long int>{1,1});
    if(n == 2) return ans;
    
    for(int i=2;i<n;++i) {
        vector<long long int> arr = {1};
        for(int j=1;j<i; ++j) {
            arr.push_back(ans[i-1][j-1]+ans[i-1][j]);
        }
        arr.push_back(1);
        ans.push_back(arr);
    }
    return ans;
}
