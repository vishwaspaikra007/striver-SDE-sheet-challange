// striver SDE sheet challange Maximum In Sliding Windows Of Size K
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    deque<int> stk;
    stk.push_back(0);
    vector<int> ans;
    int i = 1;
    while(i < k) {
        while(!stk.empty() && nums[stk.back()] <= nums[i]) stk.pop_back();
        stk.push_back(i);
        ++i;
    }
    ans.push_back(nums[stk.front()]);
    while(i < n) {
        while(!stk.empty() && nums[stk.back()] <= nums[i]) 
            stk.pop_back();
        while(!stk.empty() && stk.front() <= i-k )
            stk.pop_front();
        stk.push_back(i);
        ans.push_back(nums[stk.front()]);
        ++i;
    }
    return ans;
}
