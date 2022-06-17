// striver SDE sheet challange majority-element-ii
// author Vishwas Paikra
#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    unordered_map<int, int> cnt;
    int n = floor(arr.size()/3);
    for(int i: arr) ++cnt[i];
    for(auto obj: cnt)
        if(obj.second > n)
            ans.push_back(obj.first);
    return ans;
}
