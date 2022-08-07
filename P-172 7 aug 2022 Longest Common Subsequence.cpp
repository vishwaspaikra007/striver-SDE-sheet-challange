// striver SDE sheet challange Longest Common Subsequence
// author Vishwas Paikra
int lcs(string s, string t)
{
    int n = s.size() + 1, m = t.size() + 1;
	int ans[n][m];

    for(int i = 0;i < n; ++i) ans[i][0] = 0;
    for(int i = 1;i < m; ++i) ans[0][i] = 0;
    
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            if(s[i-1] == t[j-1])
                ans[i][j] = ans[i-1][j-1] + 1;
            else ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
        }
    }
    return ans[n-1][m-1];
}
