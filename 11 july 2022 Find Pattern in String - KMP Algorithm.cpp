// striver SDE sheet challange Find Pattern in String - KMP Algorithm
// author Vishwas Paikra
// longest proper suffix
void setLps(vector<int> &lps, string &p, int m) {
    int i = 1, len = 0;
    lps[0] = 0;
    while(i < m) {
        if(p[len] == p[i]) {
            ++len;
            lps[i] = len;
            ++i;
        } else {
            if(len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}
bool findPattern(string p, string s)
{
    int n = s.size(), m = p.size();
    vector<int> lps(m);
    setLps(lps, p, m);
    int i = 0, j = 0;
    while(i < n) {
        if(p[j] == s[i]) {
            ++i;
            ++j;
        }
        if(j == m) {
            return true;
        }
        else if(i < n && p[j] != s[i]) {
            if(j != 0)
                j = lps[j-1];
            else
                ++i;
        }
    }
    return false;
}
