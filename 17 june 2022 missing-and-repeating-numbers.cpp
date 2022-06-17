// striver SDE sheet challange missing-and-repeating-numbers
// author Vishwas Paikra
#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<bool> hash(n+1);
    hash[0] = true;
    pair<int, int> ans;
    for(int i: arr) {
        if(!hash[i]) hash[i]=true;
        else ans.second = i;
    }
    ans.first = find(hash.begin(), hash.end(), false) - hash.begin();
    return ans;
}
