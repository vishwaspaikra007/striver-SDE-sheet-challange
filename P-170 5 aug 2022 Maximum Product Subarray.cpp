// striver SDE sheet challange Maximum Product Subarray
// author Vishwas Paikra
void cal_sum1(int &i, int n, vector<int> &arr, int &sum1, int &maxi) {
    for(; i < n && sum1 > 0; ++i) {
        sum1 *= arr[i];
        maxi =  max(maxi, sum1);
    }
}
int maximumProduct(vector<int> &arr, int n)
{
	int sum1 = 0, sum2 = 1, maxi = INT_MIN, i = 0;
    
    while(sum1 == 0) {
        sum1 = 1;
        cal_sum1(i, n, arr, sum1, maxi);
    }
    while( i < n ) {
        sum1 *= arr[i];
        sum2 *= arr[i];
        maxi = max(maxi, max(sum1, sum2));
        if(arr[i] == 0) {
            ++i;
            while(sum1 == 0) {
                sum1 = 1;
                cal_sum1(i, n, arr, sum1, maxi);
            }
            sum2 = 1;
            continue;
        }
        ++i;
    }
    return maxi;
}
