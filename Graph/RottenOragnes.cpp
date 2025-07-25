#include <bits/stdc++.h>
using namespace std;




// WHEN WE NEED TO FIND SOME MINIMUM THINGS IN A GRAPH TRAVERSAL WE SHOULD USE BFS

//INTUTION : THINK LIKE FLOOD 


class Solution {
public:
    int bfs(queue<pair<pair<int,int>,int>>&q, vector<vector<int>>&visited, vector<vector<int>>& grid, int rows, int columns){
        int directions[5] = {0,-1,0,1,0};
        int time=0;
        while(!q.empty()){
            pair<pair<int,int>,int>pr = q.front();
            q.pop();
            time = pr.second;
            for(int k=0; k<4; k++){
                int nrow = pr.first.first+directions[k];
                int ncol = pr.first.second+directions[k+1];
                if(nrow>=0 && nrow<rows && ncol>=0 && ncol<columns && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    grid[nrow][ncol] = 2;
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},time+1});
                }
            }
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int ans = 0;
        vector<vector<int>>visited(rows,vector<int>(columns));
        queue<pair<pair<int,int>,int>>q; //[{r,c},{t}]
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j] == 2 && visited[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        ans = bfs(q,visited,grid,rows,columns);
        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         queue<pair<int,int>> q;
//         int fresh = 0;


//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(grid[i][j] == 2) {
//                     q.push({i,j});
//                 } else if(grid[i][j] == 1) {
//                     fresh++;
//                 }
//             }
//         }

//         int time = 0;
//         int dx[] = {-1, 1, 0, 0};
//         int dy[] = {0, 0, -1, 1};

//         while(!q.empty() && fresh > 0) {
//             int size = q.size();
//             for(int i = 0; i < size; i++) {
//                 auto [r, c] = q.front(); q.pop();

//                 for(int d = 0; d < 4; d++) {
//                     int nr = r + dx[d];
//                     int nc = c + dy[d];
//                     if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1) {
//                         grid[nr][nc] = 2;
//                         fresh--;
//                         q.push({nr, nc});
//                     }
//                 }
//             }
//             time++; 
//         }

//         return fresh == 0 ? time : -1;
//     }
// };



//WRONG : DFS CODE
/*
class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>&grid){
        //you can go in four directions

        if(row-1 >= 0 ){
            if(grid[row-1][col] == 1){
                grid[row-1][col] = 2;
                dfs(row-1, col, grid);
            }
        }
        if(row+1 < grid.size()){
            if(grid[row+1][col] == 1){
                grid[row+1][col] = 2;
                dfs(row+1,col,grid);
            }
        }
        if(col-1 >= 0){
            if(grid[row][col-1] == 1){
                grid[row][col-1]=2;
                dfs(row,col-1,grid);
            }
        }
        if(col+1 < grid[0].size()){
            if(grid[row][col+1] == 1){
                grid[row][col+1]=2;
                dfs(row,col+1,grid);
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int min=0;
        // vector<vector<int>>vis(gird.size(),grid[0].size());
        // for(int i=0; i < grid.size(); i++){
        //     for(int j=0; j < grid[0].size(); j++){
        //         vis[i][j] = -1;
        //     }
        // }
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 2 ){
                    dfs(i,j, grid);
                    min++;
                }
            }
        }
        for(int i=0; i < grid.size(); i++){
            for(int j=0; j < grid[0].size(); j++){
                if(grid[i][j] == 1)return -1;
            }
        }
        return min;
    }



};  

*/