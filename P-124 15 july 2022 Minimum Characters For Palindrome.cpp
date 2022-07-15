// striver SDE sheet challange Minimum Characters For Palindrome
// author Vishwas Paikra
#include<bits/stdc++.h>
void reverseStr(string &str, int n) {
    str += '#';
    while(--n >= 0) {
        str += str[n];
    }
}
int minCharsforPalindrome(string str) {
    int i = 1, j = 0, k = str.size(), n = 2*k + 1;
    reverseStr(str, k);
    vector<int> longestProperSuffix(n);
    longestProperSuffix[0] = 0;
    while(i < n) {
        if(str[j] == str[i]) {
            longestProperSuffix[i] = j+1;
            ++j;
            ++i;
        } else {
            if(j == 0) longestProperSuffix[i++] = 0;
            else j = longestProperSuffix[j-1];
        }
    }
    return k - longestProperSuffix[n-1];
}
