// striver SDE sheet challange 4sum
// author Vishwas Paikra
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int k = 4;
        temp.resize(k);
        sort(nums.begin(), nums.end());
        ksum(nums, target, 0, 0, k);
        return ans;
    }
    void ksum(vector<int>& nums, int target, int start, int k, int ok) {
        if(start == nums.size()) return;
        int avg = target/(ok-k);
        if(avg < nums[start] || avg > nums.back()) return;
        
        if(ok - k == 2) return sum2(nums, target, start, ok);
        for(int i = start; i < nums.size(); ++i) {
            if(i == start || nums[i-1] != nums[i]) {
                temp[k] = nums[i];
                ksum(nums, target - nums[i], i + 1, k + 1, ok);
            }
        }
    }
    void sum2(vector<int>& nums, int target, int start, int ok) {
        unordered_map<int, bool> hash;
        int prev = INT_MAX;
        for(int i = start; i < nums.size(); ++i) {
            int rest = target - nums[i];
            if(prev == INT_MAX || prev != nums[i]) {
                if(hash[rest]) {
                    temp[ok-2] = rest;
                    temp[ok-1] = nums[i];
                    prev = nums[i];
                    ans.push_back(temp);
                }
            }
            hash[nums[i]] = true; 
        }
    }
};
