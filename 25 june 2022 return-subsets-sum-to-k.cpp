// striver SDE sheet challange return-subsets-sum-to-k
// author Vishwas Paikra
void bt(vector<vector<int>> &ans,  vector<int> &temp,  vector<int> &arr, int i, int n, int k) {
    if(i == n) {
        if(k == 0)
            ans.push_back(temp);
        return;
    }
    bt(ans, temp, arr, i+1, n, k);
    temp.push_back(arr[i]);
    bt(ans, temp, arr, i+1, n, k - arr[i]);
    temp.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> temp;
    bt(ans, temp, arr, 0, n, k);
    return ans;
}
