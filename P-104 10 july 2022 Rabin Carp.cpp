// striver SDE sheet challange Rabin Carp
// author Vishwas Paikra
bool match(int i, int m, string &str, string &pat) {
    for(int j = i, k = 0; j < m; ++j, ++k) {
        if(pat[k] != str[j]) return false;
    }
    return true;
}
vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    int m = pat.size(), n = str.size();
    vector<int> ans;
    n = n-m;
    for(int i = 0; i <= n; ++i) {
        if(match(i, i+m, str, pat))
            ans.push_back(i);
    }
    return ans;
}
