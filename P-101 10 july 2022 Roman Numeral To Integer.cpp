// striver SDE sheet challange Roman Numeral To Integer
// author Vishwas Paikra
#include<bits/stdc++.h>
int romanToInt(string s) {
    // Write your code here
    int sum = 0, n = s.size();
    unordered_map<char, int> hash;
    hash['I'] = 1;
    hash['V'] = 5;
    hash['X'] = 10;
    hash['L'] = 50;
    hash['C'] = 100;
    hash['D'] = 500;
    hash['M'] = 1000;
    for(int i = 0; i < n; ++i) {
        if(i+1 < n && hash[s[i]] < hash[s[i+1]])
            sum -= hash[s[i]];
        else sum += hash[s[i]];
    }
    return sum;
}
