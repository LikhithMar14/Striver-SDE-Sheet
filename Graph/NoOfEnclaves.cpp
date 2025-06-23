#include<bits/stdc++.h>
using namespace std;
    
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int j = 0; j < m; j++) {
            if(grid[0][j]) q.push({0, j});
            if(grid[n-1][j]) q.push({n-1, j});
        }

        for(int i = 0; i < n; i++) {
            if(grid[i][0]) q.push({i, 0});
            if(grid[i][m-1]) q.push({i, m-1});
        }

        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(grid[row][col] == 0) continue;
            grid[row][col] = 0;

            for(int i = 0; i < 4; i++) {
                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc]) {
                    q.push({nr, nc});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans += grid[i][j];
            }
        }

        return ans;
    }
};
