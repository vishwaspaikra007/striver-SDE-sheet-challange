// striver SDE sheet challange search-in-rotated-sorted-array
// author Vishwas Paikra
int search(int* arr, int n, int key) {
    int i = 0, mid;
    while(i < n) {
        mid = i+(n-i)/2;
        if(arr[mid] == key) return mid;
        else if(arr[i] <= arr[mid]) {
            if(key < arr[mid] && key >= arr[i])
                n = mid;
            else i = mid + 1;
        } else {
            if(key > arr[mid] && key <= arr[n-1])
                i = mid + 1;
            else n = mid;
        }
    }
    return -1;
}
