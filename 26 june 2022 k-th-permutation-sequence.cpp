// striver SDE sheet challange k-th-permutation-sequence
// author Vishwas Paikra
string kthPermutation(int n, int k) {
    string ans = "", temp = "";
    int fact = 1;
    for(int i = 1; i < n; ++i) {
        temp += ('0' + i);
        fact *= i;
    }
    k -= 1;
    temp += ('0' + n);
    while(true) {
        int idx = k/fact;
        ans += temp.substr(idx, 1);
        temp.erase(idx, 1);
        if(temp.size() == 0)
            break;
        k %= fact;
        fact = fact / temp.size();
    }
    return ans;
}
