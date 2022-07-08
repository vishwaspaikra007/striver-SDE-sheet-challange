// striver SDE sheet challange Longest Palindromic Substring
// author Vishwas Paikra
string longestPalinSubstring(string str)
{
    int n = str.size();
    int maxi = 0;
    pair<int, int> idxs = {0,0};
    string ans;
    for(int i = 0; i < n; ++i) {
        int cnt = 0;
        int j=i, k=i+1;
        for(; j>=0 && k<n; --j,++k) {
            if(str[j] != str[k]) break;
            cnt +=2;
            if(maxi < cnt) {
                maxi = cnt;
                idxs = {j,k};
            }
        }
        cnt = 1;
        j=i-1,k=i+1;
        for(; j>=0 && k<n; --j,++k) {
            if(str[j] != str[k]) break;
            cnt += 2;
            if(maxi < cnt) {
                maxi = cnt;
                idxs = {j,k};
            }
        }
    }
    return str.substr(idxs.first, idxs.second - idxs.first + 1);
}
