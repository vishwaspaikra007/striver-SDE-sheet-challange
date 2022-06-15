// striver SDE sheet challange next-permutaion
#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int m = n -= 1;
    while(n > 0 && permutation[n-1]>=permutation[n]) --n;
    if(n != 0) {
        while(m > 0 && permutation[n-1] >= permutation[m]) --m;
        swap(permutation[n-1], permutation[m]);
    }
    reverse(permutation.begin()+n, permutation.end());
    return permutation;
}
