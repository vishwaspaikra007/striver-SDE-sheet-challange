// striver SDE sheet challange count-subarrays-with-given-xor
// author Vishwas Paikra
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int _xor = 0, cnt = 0;
    unordered_map<int, int> hash;
    for(int i: arr) {
        _xor ^= i;
        if(_xor == x) ++cnt;
        cnt += hash[_xor ^ x];
        ++hash[_xor];
    }
    return cnt;
}
