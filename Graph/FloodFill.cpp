#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        if(newColor == image[sr][sc])return image;
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int,int>>q;
        int oc = image[sr][sc];
        q.push({sr,sc});
        
        image[sr][sc] = newColor;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            vector<int>dx{0,0,1,-1};
            vector<int>dy{1,-1,0,0};
            
            for(int i=0; i < 4; i++){
                if(row+dx[i] >= 0 && row+dx[i] < n && col+dy[i] >= 0 && col+dy[i] < m && image[row+dx[i]][col+dy[i]] == oc){
                    image[row+dx[i]][col+dy[i]] = newColor;
                    q.push({row+dx[i], col+dy[i]});
                }
            }
        }
        return image;
        
    }
};