// striver SDE sheet challange total-unique-paths
// author Vishwas Paikra
#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	if(m==1) return 1;
	vector<vector<int>> ans(m, vector<int>(n));
	ans[0][0]=0;
	for(int i=1;i<m;++i) ans[i][0]=1;
	for(int i=1;i<n;++i) ans[0][i]=1;
	for(int i=1;i<m;++i) 
		for(int j=1;j<n;++j)
			ans[i][j]=ans[i-1][j]+ans[i][j-1];
	return ans[m-1][n-1];
}
