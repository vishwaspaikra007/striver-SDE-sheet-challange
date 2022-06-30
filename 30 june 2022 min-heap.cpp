// striver SDE sheet challange min-heap
// author Vishwas Paikra
class Heap {
    int *arr;
    int capacity;
    int currSize;
    public:
    int parent(int i) { return (i-1)/2; }
    int left(int i ) { return 2*i + 1; }
    int right(int i) { return 2*i + 2; }
    
    Heap(int maxSize) {
        arr = new int[maxSize];
        capacity = maxSize;
        currSize = 0;
    }
    
    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < currSize && arr[l] < arr[smallest])
            smallest = l;
        if(r < currSize && arr[r] < arr[smallest])
            smallest = r;
        if(smallest != i) {
            swap(arr[smallest], arr[i]);
            heapify(smallest);
        }
    }
    
    int insert(int k) {
        int i = currSize++;
        arr[i] = k;
        while(i > 0 && arr[parent(i)] > arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    
    int pop() {
        if(currSize == 1) {
            --currSize;
            return arr[0];
        }
        int x = arr[0];
        arr[0] = arr[--currSize];
        heapify(0);
        return x;
    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    Heap minHeap(100005);
    vector<int> ans;
    for(auto &vec: q) {
        if(vec[0]) ans.push_back(minHeap.pop());
        else minHeap.insert(vec[1]);
    }
    return ans;
}
