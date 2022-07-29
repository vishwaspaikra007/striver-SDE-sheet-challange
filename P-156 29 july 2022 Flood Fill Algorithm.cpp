// striver SDE sheet challange Flood Fill Algorithm
// author Vishwas Paikra
#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    if(image[x][y] == newColor) return image;
    int n = image.size(), m = image[0].size();
    queue<pair<int, int>> stk;
    int oldColor = image[x][y];
    image[x][y] = newColor;
    stk.emplace(x, y);
    
    int arr[] = {-1, 0, 1, 0, -1};
    while(!stk.empty()) {
        int x = stk.front().first;
        int y = stk.front().second;
        stk.pop();
        for(int i = 1; i < 5; ++i) {
            int u = x + arr[i-1];
            int v = y + arr[i];
            
            if(u>=0 && v>=0 && u<n && v<m && image[u][v] == oldColor) {
                image[u][v] = newColor;
                stk.emplace(u, v);
            }
        }
    }
   return image;
}
