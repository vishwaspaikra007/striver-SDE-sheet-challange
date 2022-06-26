// striver SDE sheet challange palindrome-partitioning
// author Vishwas Paikra
#include<bits/stdc++.h>
bool isPalindrome(unordered_map<string, bool> &hash, string &s, int i, int j) {
    while(i < j) {
        if(s[i++] != s[j--])
            return hash[s.substr(i, j - i + 1)] = false;
    }
    return hash[s.substr(i, j - i + 1)] = true;
}
void _break(int start, int n, string &s, 
    vector<vector<string>> &ans,
    vector<string> &temp,
    unordered_map<string, bool> &hash) {
    if(start >= n) {
        ans.push_back(temp);
        return;
    }
    for(int i = start; i < n; ++i) {
        if(hash[s.substr(start, i - start + 1)] || isPalindrome(hash, s, start, i)) {
            temp.push_back(s.substr(start, i - start + 1));
            _break(i + 1, n, s, ans, temp, hash);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> temp;
    unordered_map<string, bool> hash;
    int n = s.size();
    _break(0, n, s, ans, temp, hash);
    return ans;
}
