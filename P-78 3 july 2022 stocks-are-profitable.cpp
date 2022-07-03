// striver SDE sheet challange stocks-are-profitable
// author Vishwas Paikra
#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    unordered_map<string, bool> hash;
    for(int i = 0; i < word.size(); ++i) {
        string str = "";
        for(int j = i; j < word.size(); ++j) {
            str += word[j];
            hash[str] =  true;
        }
    }
    return hash.size();
}
