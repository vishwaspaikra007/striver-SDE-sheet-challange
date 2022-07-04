// striver SDE sheet challange max-xor-queries
// author Vishwas Paikra
#include<bits/stdc++.h>
struct Node {
    Node *list[2];
};
class Trie {
    Node *root;
    public:
        Trie () {
            root = new Node();
        }
        void insert(int x) {
            Node *curr = root;
            for(int i = 31; i >= 0; --i) {
                int k = (x >> i) & 1;
                if(!curr->list[k]) {
                    curr->list[k] = new Node();
                }
                curr = curr->list[k];
            } 
        }
        int getMaxXOR(int x) {
            int _xor = 0;
            Node *curr = root;
            for(int i = 31; i >= 0; --i) {
                _xor <<= 1;
                int k = (x >> i) & 1;
                if(curr->list[1-k]) {
                    _xor |= 1;
                    curr = curr->list[1-k];
                } else curr = curr->list[k];
            } 
            return _xor;
        }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	Trie *trieObj = new Trie();
    vector<vector<int>> R(queries.size(), vector<int>(3));
    vector<int> ans(queries.size());
    for(int i = 0; i < queries.size(); ++i) {
        R[i] = {queries[i][1], queries[i][0], i};
    }
    sort(begin(arr), end(arr));
    sort(begin(R), end(R));
    int i = 0;
    for(auto &vec : R) {
        while(i < arr.size() && arr[i] <= vec[0]) {
            trieObj->insert(arr[i++]);
        }
        if(i == 0) ans[vec[2]] = -1;
        else ans[vec[2]] = trieObj->getMaxXOR(vec[1]);
    }
    return ans;
}
