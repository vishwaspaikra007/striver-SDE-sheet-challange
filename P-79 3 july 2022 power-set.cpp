// striver SDE sheet challange power-set
// author Vishwas Paikra
void subset(vector<vector<int>> &ans, vector<int> &v, vector<int> &temp, int idx) {
    if(idx == v.size()) {
        ans.push_back(temp);
        return;
    }
    subset(ans, v, temp, idx+1);
    temp.push_back(v[idx]);
    subset(ans, v, temp, idx+1);
    temp.pop_back();
}
vector<vector<int>> pwset(vector<int>v)
{
    vector<vector<int>> ans;
    vector<int> temp;
    subset(ans, v, temp, 0);
    return ans;
}
