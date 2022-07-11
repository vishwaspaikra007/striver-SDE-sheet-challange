// striver SDE sheet challange Check Permutation
// author Vishwas Paikra
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    int n = str1.size(), m = str2.size();
    if(n != m) return false;
    vector<int> x(26, 0), y(26, 0);
    for(int i = 0; i < n; ++i) {
        ++x[str1[i]-'a'];
        ++y[str2[i]-'a'];
    }
    return x == y;
}
