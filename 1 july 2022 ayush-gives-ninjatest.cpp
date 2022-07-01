// striver SDE sheet challange ayush-gives-ninjatest
// author Vishwas Paikra
#include<bits/stdc++.h>
bool isPoss(long long mid, vector<int> time, long long n) {
    long long cnt = 1, sum = 0;
    for(auto &i: time) {
        sum += i;
        if(i > mid) return false;
        if(sum > mid) {
            sum = i;
            ++cnt;
        }
    }
    return cnt <= n;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
    long long left = *min_element(begin(time), end(time));
	long long right = accumulate(time.begin(), time.end(), 0LL);
    long long ans = - 1, mid;
    while(left <= right) {
        mid = (left + right) >> 1;
        if(isPoss(mid, time, n)) {
            right = mid - 1;
            ans = mid;
        } else left = mid + 1;
    }
    return ans;
}
