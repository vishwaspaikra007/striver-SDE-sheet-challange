// striver SDE sheet challange unique-element-in-sorted-array
// author Vishwas Paikra
int uniqueElement(vector<int> arr, int n)
{
	int i = 0, mid;
    n -= 1;
    while(i < n) {
        mid = i+(n-i)/2;
        if((mid%2 == 0 && arr[mid] == arr[mid+1]) || (mid%2 == 1 && arr[mid] == arr[mid-1]))
            i = mid + 1;
        else n = mid;
    }
    return arr[i];
}
