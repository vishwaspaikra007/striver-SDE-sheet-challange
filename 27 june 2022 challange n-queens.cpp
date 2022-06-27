// striver SDE sheet challange n-queens
// author Vishwas Paikra
void BT(int start, int n, vector<vector<int>> &ans, vector<int> &temp,
       vector<bool> &col, vector<bool> &d1, vector<bool> &d2) {
    if(start == n) {
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!col[i] && !d1[start + i] && !d2[n - 1 + start - i]) {
            temp[start*n + i] = 1;
            col[i] = true;
            d1[start + i] = true;
            d2[n - 1 + start - i] = true;
            BT(start + 1, n, ans, temp, col, d1, d2);
            col[i] = false;
            d1[start + i] = false;
            d2[n - 1 + start - i] = false;
            temp[start*n + i] = 0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<int> temp(n*n, 0);
    vector<bool> col(n), d1(2*n), d2(2*n);
    BT(0, n, ans, temp, col, d1, d2);
    return ans;
}
