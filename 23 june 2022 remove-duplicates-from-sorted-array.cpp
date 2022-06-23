// striver SDE sheet challange remove-duplicates-from-sorted-array
// author Vishwas Paikra
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int cnt = 1;
    for(int i = 1; i < n; ++i) {
        if(arr[i] != arr[i-1])
            ++cnt;
    }
    return cnt;
}
