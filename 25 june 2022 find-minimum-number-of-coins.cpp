// striver SDE sheet challange find-minimum-number-of-coins
// author Vishwas Paikra
int findMinimumCoins(int amount) 
{
    // Write your code here
    int arr[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int cnt = 0;
    for(int i = 0; i < 9; ++i) {
        cnt += amount/arr[i];
        amount %= arr[i];
    }
    return cnt;
}
