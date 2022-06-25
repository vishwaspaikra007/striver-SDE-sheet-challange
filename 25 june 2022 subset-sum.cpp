// striver SDE sheet challange subset-sum
// author Vishwas Paikra
void subset(int n, int sum, vector<int> &ans, vector<int> &num) {
    if(n < 0) {
        ans.push_back(sum);
        return;
    }
    subset(n-1, sum, ans, num);
    subset(n-1, sum + num[n], ans, num);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    int n = num.size()-1;
    subset(n, 0, ans, num);
    sort(ans.begin(), ans.end());
    return ans;
}
