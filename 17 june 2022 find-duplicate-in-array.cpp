// striver SDE sheet challange find-duplicate-in-array
// author Vishwas Paikra

#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    vector<bool> hash(n);
    for(int i: arr) {
        if(!hash[i]) {
            hash[i] = true;
        } else return i;
    }
}
