// striver SDE sheet challange maximum-consecutive-ones
// author Vishwas Paikra
int longestSubSeg(vector<int> &arr , int n, int k){
    int cnt1 = 0, maxi = 0;
    for(int i=0,j=0;i<n;++i) {
        if(arr[i] || --k >= 0) ++cnt1;
        else {
            while(arr[j]) {
                ++j;
                --cnt1;
            }
            ++j;
        }
        maxi = max(maxi, cnt1);
    }
    return maxi;
}
