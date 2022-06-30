// striver SDE sheet challange chess-tournament
// author Vishwas Paikra
bool isPoss(int mid, vector<int>&positions, int n, int c) {
    int cnt = 1;
    for(int i = 1, prev = 0;i < n; ++i) {
        if(positions[i] - positions[prev] >= mid) {
            prev = i;
            ++cnt;
            if(cnt == c) return true;
        }
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	sort(positions.begin(), positions.end());
    int i = 1, mid, j = positions[n-1] - positions[0], res = 1;
    while(i <= j) {
        mid = i+(j-i)/2;
        if(isPoss(mid, positions, n, c)) {
            res = mid;
            i = mid + 1;
        } else j = mid - 1;
    }
    return res;
}
