// striver SDE sheet challange maximum-xor
// author Vishwas Paikra
struct Node {
    Node *list[2];
};
int maximumXor(vector<int> A)
{
    Node *root = new Node(), *curr;
    int mask = 1 << 30;
    for(int x : A) {
        curr = root;
        for(int i = 31; i > -1; --i) {
            int k = x >> i;
            k &= 1;
            if(!curr->list[k])
                curr->list[k] = new Node();
            curr = curr->list[k];
        }
    }
    int maxi = 0;
    for(int x : A) {
        int _xor = 0;
        curr = root;
        for(int i = 31; i > -1; --i) {
            _xor <<= 1;
            int k = x >> i;
            k &= 1;        
            if(curr->list[k^1]) {
                _xor |= 1;
                curr = curr->list[k^1];
            } else curr = curr->list[k];
        }
        maxi = max(maxi, _xor);
    }
    return maxi;
}
