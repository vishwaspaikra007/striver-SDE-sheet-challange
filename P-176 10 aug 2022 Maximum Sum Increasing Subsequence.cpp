// striver SDE sheet challange Maximum Sum Increasing Subsequence
// author Vishwas Paikra
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	int sm[n], maxi = 0;
    for(int i = 0; i < n; ++i) {
        int res = 0;
        for(int j = i-1; j >= 0; --j) {
            if(rack[j] < rack[i]) {
                res = max(res, sm[j]);
            }
        }
        sm[i] = res + rack[i];
        maxi = max(maxi, sm[i]);
    }
    return maxi;
}
