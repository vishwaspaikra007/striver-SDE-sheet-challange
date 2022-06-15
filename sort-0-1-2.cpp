// striver SDE sheet challenge sort-0-1-2
#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
    int j = -1;
    for(int i=0;i<n;++i)
        if(arr[i] == 0) 
            swap(arr[i], arr[++j]);
    for(int i=j+1; i<n; ++i)
        if(arr[i] == 1)
            swap(arr[i], arr[++j]);
}
