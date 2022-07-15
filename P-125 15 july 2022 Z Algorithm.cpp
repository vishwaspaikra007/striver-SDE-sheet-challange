// striver SDE sheet challange Z Algorithm
// author Vishwas Paikra
void setLps(vector<int> &lps, string &p, int m) {
    int len = 0, i = 1;
    lps[0] = 0;
    while(i < m) {
        if(p[len] == p[i]) {
            lps[i] = len+1;
            ++len;
            ++i;
        } else {
            if(len == 0) lps[i++] = 0;
            else len = lps[len-1];
        }
    }
}
int zAlgorithm(string s, string p, int n, int m)
{
	vector<int> lps(m);
    setLps(lps, p, m);
    int i = 0, j = 0, cnt = 0;
    while(i < n) {
        if(p[j] == s[i]) {
            ++i;
            ++j;
        } else {
            if(j != 0) j = lps[j-1];
            else ++i;
        }
        if(j == m) {
            ++cnt;
            j = lps[j-1];
        }
    }
    return cnt;
}
