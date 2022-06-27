// striver SDE sheet challange print-permutations-string
// author Vishwas Paikra
void permute(vector<string> &ans, string &s, string &temp, vector<bool> &hash) {
    if(temp.size() == s.size()) {
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < s.size(); ++i) {
        if(hash[i]) continue;
        hash[i] = true;
        temp.push_back(s[i]);
        permute(ans,s,temp,hash);
        temp.pop_back();
        hash[i] = false;
    }
}
vector<string> findPermutations(string &s) {
    vector<string> ans;
    string temp;
    vector<bool> hash(s.size());
    permute(ans,s,temp,hash);
    return ans;
}
