// striver SDE sheet challange modular-exponentiation
// author Vishwas Paikra
#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    long ans = 1, xx = x;
    while(n>0) {
        if(n&1)
            ans = (ans*xx)%m;
        xx = (xx%m * xx%m)%m;
        n >>= 1;
    }
    return (int)ans;
}
