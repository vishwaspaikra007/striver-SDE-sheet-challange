// striver SDE sheet challange reverse-pairs leetcode
// author Vishwas Paikra
class Solution {
public:
    int merge(vector<int> &arr, vector<int> &temp, int l, int m, int r) {
        int i = l, j = m, k = l;
        int cnt = 0;
        for(int x=l,y=m;x<m;++x) {
            while(y<=r && arr[x]/2.0 > arr[y]) ++y;
            cnt += y - m;
        }
        while(i < m && j <= r) {
            if(arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        while(i < m) temp[k++] = arr[i++];
        while(j <= r) temp[k++] = arr[j++];
        for(i = l;i<=r;++i) arr[i] = temp[i];
        return cnt;
    }
    int mergeSort(vector<int> &arr, vector<int> &temp, int l, int r) {
        int cnt = 0;
        if(l < r) {
            int m = l+(r-l)/2;
            cnt += mergeSort(arr, temp, l, m);
            cnt += mergeSort(arr, temp, m+1, r);
            cnt += merge(arr, temp, l, m+1, r);
        }
        return cnt;
    }
    int reversePairs(vector<int> &arr){
        int n = arr.size();
        vector<int> temp(n);
        return mergeSort(arr, temp, 0, n-1);
    }
};
