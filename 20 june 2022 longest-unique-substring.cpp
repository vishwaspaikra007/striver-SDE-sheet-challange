// striver SDE sheet challange longest-unique-substring
// author Vishwas Paikra
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    vector<int> hash(26, -1);
    int n = input.size(), maxi = 1, afterThisIndexOnly = 0;
    for(int i = 0; i < n; ++i) {
       if(hash[input[i] - 'a'] >= afterThisIndexOnly)
           afterThisIndexOnly = hash[input[i] - 'a']+1;
       maxi = max(maxi, i - afterThisIndexOnly + 1);
       hash[input[i] - 'a'] = i;
    }
    return maxi;
}
