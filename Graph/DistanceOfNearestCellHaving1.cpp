#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({0, {i, j}});
                    grid[i][j] = -1; 
                }
            }
        }
        
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        while(!q.empty()){
            int weight = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0){
                    grid[nr][nc] = weight + 1;
                    q.push({weight + 1, {nr, nc}});
                }
            }
        }


        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == -1) grid[i][j] = 0;
            }
        }

        return grid;
    }
};
