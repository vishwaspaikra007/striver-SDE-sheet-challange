// striver SDE sheet challange Longest Common Prefix
// author Vishwas Paikra
#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    sort(begin(arr), end(arr));
    string str = "";
    int i = -1;
    while(true) {
        if(arr[0][++i] == arr[n-1][i])
            str += arr[0][i];
        else break;
    }
    return str;
}


