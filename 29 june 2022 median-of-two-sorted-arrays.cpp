// striver SDE sheet challange median-of-two-sorted-arrays
// author Vishwas Paikra
double median(vector<int> a, vector<int> b)
{
    vector<int> list;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) list.push_back(a[i++]);
        else list.push_back(b[j++]);
    }
    while(i < a.size()) list.push_back(a[i++]);
    while(j < b.size()) list.push_back(b[j++]);
    
    return list.size()%2 == 1 ? list[list.size()/2] :  
            (list[list.size()/2] +  list[list.size()/2 - 1])/2.0;
}
