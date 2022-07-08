// striver SDE sheet challange The Celebrity Problem
// author Vishwas Paikra
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
#include<bits/stdc++.h>
int findCelebrity(int n) {
 	// Write your code here.
    stack<int> stk;
    for(int i = 0; i < n; ++i)
        stk.push(i);
    while(stk.size() > 1) {
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        if(knows(a,b))
            stk.push(b);
        else
            stk.push(a);
    }
    if(stk.empty()) return -1;
    int f = stk.top();
    for(int i = 0; i < n; ++i) {
        if(f != i && !knows(i,f)) return -1;
    }
    for(int i = 0; i < n; ++i) {
        if(knows(f,i)) return -1;
    }
    return f;
}
