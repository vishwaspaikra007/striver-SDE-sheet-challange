// striver SDE sheet challange Compare Version Numbers
// author Vishwas Paikra
int compareVersions(string a, string b) 
{
    int n = a.size(), m = b.size(), i = 0, j = 0;
    while(i < n || j < m) {
        long aval = 0, bval = 0;
        while(i < n && a[i] != '.') {
            aval = aval*10 + (a[i++]-'0');
        }
        while(j < m && b[j] != '.') {
            bval = bval*10 + (b[j++]-'0');
        }
        if(aval > bval) return 1;
        if(bval > aval) return -1;
        
        ++i; ++j;
    }
    return 0;
}
