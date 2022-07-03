// striver SDE sheet challange complete-string
// author Vishwas Paikra
#include<bits/stdc++.h>
string completeString(int n, vector<string> &a){
    unordered_map<string, bool> hash;
    sort(a.begin(), a.end());
    string maxi = "";
    for(string &s: a) {
        int cnt = 1;
        string str = "";
        for(int i = 0; i < s.size()-1; ++i) {
            str += s[i];
            if(hash[str]) ++cnt;
            else break;
        }
        hash[s] = true;
        if(cnt == s.size() && maxi.size() < cnt) maxi = s;
    }
    return maxi.size() ? maxi : "None";
}
